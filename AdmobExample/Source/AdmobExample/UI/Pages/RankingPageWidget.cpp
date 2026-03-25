#include "RankingPageWidget.h"
#include "FlutterUMGWidgets.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetTree.h"

using namespace Flutter;

TSharedRef<SWidget> URankingPageWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);

    Flutter::Stack RankingStack;
    RankingCanvas = RankingStack.Widget;

    Flutter::SizeBox HostBox;
    RankingSizeBox = HostBox.Widget;
    TargetRankingHeight = 20.0f;
    CurrentRankingHeight = 20.0f;
    RankingSizeBox->SetHeightOverride(CurrentRankingHeight);
    RankingSizeBox->AddChild(RankingCanvas);

    Flutter::ListView Scroller;
    Scroller.Widget->AddChild(RankingSizeBox);

    auto RootCol = Flutter::Column().MainAxisAlignment(0)(
        Flutter::Padding(FMargin(16.f)).Child(
            Flutter::Row().MainAxisAlignment(0)(
                Flutter::Expanded().Child(Flutter::ElevatedButton().OnPressed(this, TEXT("OnRankingAddClicked")).Child(Flutter::Text(TEXT("Add")).FontSize(14).Color(FLinearColor::White))),
                Flutter::SizedBox(10.f, 1.f),
                Flutter::Expanded().Child(Flutter::ElevatedButton().OnPressed(this, TEXT("OnRankingShuffleClicked")).Child(Flutter::Text(TEXT("Rescore")).FontSize(14).Color(FLinearColor::White))),
                Flutter::SizedBox(10.f, 1.f),
                Flutter::Expanded().Child(Flutter::ElevatedButton().OnPressed(this, TEXT("OnRankingRemoveClicked")).Child(Flutter::Text(TEXT("Remove")).FontSize(14).Color(FLinearColor::White)))
            )
        ),
        Flutter::Expanded().Child(
            Flutter::Padding(FMargin(16.f, 0.f, 16.f, 16.f)).Child(
                Scroller
            )
        )
    );

    if (!GetWorld()->GetTimerManager().IsTimerActive(AnimationTimerHandle)) {
        GetWorld()->GetTimerManager().SetTimer(AnimationTimerHandle, this, &URankingPageWidget::AnimationTick, 0.016f, true);
    }

    if (WidgetTree) {
        WidgetTree->RootWidget = RootCol.Widget; // Anchor for Garbage Collector
    }

    return RootCol.Widget->TakeWidget();
}

void URankingPageWidget::AnimationTick() {
    float InDeltaTime = 0.016f; // Lock to 60fps equivalent for FInterpTo
    
    if (RankingSizeBox && !FMath::IsNearlyEqual(CurrentRankingHeight, TargetRankingHeight, 0.5f)) {
        CurrentRankingHeight = FMath::FInterpTo(CurrentRankingHeight, TargetRankingHeight, InDeltaTime, 10.0f);
        RankingSizeBox->SetHeightOverride(CurrentRankingHeight);
    }

    for (int32 i = RankingItems.Num() - 1; i >= 0; --i) {
        FRankingItem& Item = RankingItems[i];
        
        Item.CurrentY = FMath::FInterpTo(Item.CurrentY, Item.TargetY, InDeltaTime, 10.0f);
        Item.Opacity = FMath::FInterpTo(Item.Opacity, Item.TargetOpacity, InDeltaTime, 12.0f);

        if (Item.Widget) {
            if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Item.Widget->Slot)) {
                FMargin Offs = CanvasSlot->GetOffsets();
                CanvasSlot->SetOffsets(FMargin(Offs.Left, Item.CurrentY, Offs.Right, Offs.Bottom));
            }
            Item.Widget->SetRenderOpacity(Item.Opacity);
        }

        if (Item.bIsRemoving && Item.Opacity < 0.05f) {
            if (Item.Widget) {
                Item.Widget->RemoveFromParent();
            }
            RankingItems.RemoveAt(i);
        }
    }
}

void URankingPageWidget::OnRankingAddClicked() {
    if (!RankingCanvas) return;

    FRankingItem NewItem;
    NewItem.Id = NextRankingId++;
    NewItem.Name = FString::Printf(TEXT("Player %d"), NewItem.Id);
    NewItem.Score = FMath::RandRange(10, 1000);
    NewItem.CurrentY = RankingItems.Num() * 80.0f + 600.0f;
    NewItem.Opacity = 0.0f;
    NewItem.TargetOpacity = 1.0f;

    UWidget* CardWidget = Flutter::Card().SetElevation(2.f).SetBorderRadius(8.f).Child(
        Flutter::ListTile()
            .Leading(Flutter::Text(FString::Printf(TEXT("#%d"), NewItem.Id)).FontSize(18).Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.f)))
            .Title(Flutter::Text(NewItem.Name).FontSize(16))
            .Trailing(Flutter::Text(FString::Printf(TEXT("%d pt"), NewItem.Score)).FontSize(16).Color(FLinearColor::Red))
    );
    
    NewItem.Widget = CardWidget;

    UCanvasPanelSlot* Slot = RankingCanvas->AddChildToCanvas(NewItem.Widget);
    if (Slot) {
        Slot->SetAutoSize(false);
        Slot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 0.0f));
        Slot->SetOffsets(FMargin(0.0f, NewItem.CurrentY, 0.0f, 70.0f));
    }
    NewItem.Widget->SetRenderOpacity(0.0f);

    RankingItems.Add(NewItem);

    RankingItems.Sort([](const FRankingItem& A, const FRankingItem& B) {
        return A.Score > B.Score;
    });

    float YOffset = 0.0f;
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.TargetY = YOffset;
            YOffset += 80.0f;
        }
    }
    TargetRankingHeight = YOffset + 20.0f;
}

void URankingPageWidget::OnRankingRemoveClicked() {
    for (int32 i = RankingItems.Num() - 1; i >= 0; --i) {
        if (!RankingItems[i].bIsRemoving) {
            RankingItems[i].bIsRemoving = true;
            RankingItems[i].TargetOpacity = 0.0f;
            break;
        }
    }

    float YOffset = 0.0f;
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.TargetY = YOffset;
            YOffset += 80.0f;
        }
    }
    TargetRankingHeight = YOffset + 20.0f;
}

void URankingPageWidget::OnRankingShuffleClicked() {
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.Score = FMath::RandRange(10, 1000);
            
            if (Item.Widget) {
                Item.Widget->RemoveFromParent();
            }

            UWidget* CardWidget = Flutter::Card().SetElevation(2.f).SetBorderRadius(8.f).Child(
                Flutter::ListTile()
                    .Leading(Flutter::Text(FString::Printf(TEXT("#%d"), Item.Id)).FontSize(18).Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.f)))
                    .Title(Flutter::Text(Item.Name).FontSize(16))
                    .Trailing(Flutter::Text(FString::Printf(TEXT("%d pt"), Item.Score)).FontSize(16).Color(FLinearColor::Red))
            );
            
            Item.Widget = CardWidget;
            
            if (RankingCanvas) {
                UCanvasPanelSlot* Slot = RankingCanvas->AddChildToCanvas(Item.Widget);
                if (Slot) {
                    Slot->SetAutoSize(false);
                    Slot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 0.0f));
                    Slot->SetOffsets(FMargin(0.0f, Item.CurrentY, 0.0f, 70.0f));
                }
            }
            Item.Widget->SetRenderOpacity(Item.Opacity);
        }
    }
    
    RankingItems.Sort([](const FRankingItem& A, const FRankingItem& B) {
        return A.Score > B.Score;
    });

    float YOffset = 0.0f;
    for (FRankingItem& Item : RankingItems) {
        if (!Item.bIsRemoving) {
            Item.TargetY = YOffset;
            YOffset += 80.0f;
        }
    }
    TargetRankingHeight = YOffset + 20.0f;
}
