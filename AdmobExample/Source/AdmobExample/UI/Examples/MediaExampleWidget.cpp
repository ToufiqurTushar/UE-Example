#include "MediaExampleWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"
#include "Engine/Texture2D.h"

using namespace Flutter;

TSharedRef<SWidget> UMediaExampleWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);
    
    auto AppBar = Container()
        .Color(FLinearColor(0.1f, 0.5f, 0.9f, 1.0f))
        .Padding(FMargin(16.f, 15.f))
        .Child(
            Row()(
                ElevatedButton().OnPressed(this, TEXT("OnBackClicked")).Child(
                    Text(TEXT("Back")).Color(FLinearColor::White).FontSize(14)
                ),
                SizedBox(16.f, 1.f),
                Text(TEXT("Media & Align Showcase")).FontSize(20).Color(FLinearColor::White)
            )
        );

    UTexture2D* DummyImage = LoadObject<UTexture2D>(nullptr, TEXT("/Engine/EngineResources/DefaultTexture.DefaultTexture"));
    FSlateBrush ImgBrush;
    if (DummyImage) ImgBrush.SetResourceObject(DummyImage);
    ImgBrush.ImageSize = FVector2D(100.f, 100.f);
    ImgBrush.DrawAs = ESlateBrushDrawType::Image;

    auto Content = Flutter::Padding(FMargin(24.f)).Child(
        Column()(
            Text(TEXT("Local Resource Image")).FontSize(20).Color(FLinearColor::Black),
            SizedBox(1.f, 12.f),
            Container().Color(FLinearColor(0.9f, 0.9f, 0.9f, 1.0f)).Padding(FMargin(10.f)).Child(
                Image().Brush(ImgBrush).Widget
            ),
            SizedBox(1.f, 24.f),
            Text(TEXT("Align Content (Right/Center)")).FontSize(20).Color(FLinearColor::Black),
            SizedBox(1.f, 12.f),
            Container().Color(FLinearColor(0.85f, 0.85f, 0.85f, 1.f)).Padding(FMargin(10.f)).Child(
                Flutter::Align(HAlign_Right, VAlign_Center)(
                    Container().Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f)).Padding(FMargin(20)).Child(Text(TEXT("Right Aligned Block")).Color(FLinearColor::White))
                )
            ),
            SizedBox(1.f, 24.f),
            Text(TEXT("Align Content (Center/Top)")).FontSize(20).Color(FLinearColor::Black),
            SizedBox(1.f, 12.f),
            Container().Color(FLinearColor(0.85f, 0.85f, 0.85f, 1.f)).Padding(FMargin(10.f)).Child(
                Flutter::Align(HAlign_Center, VAlign_Top)(
                    Container().Color(FLinearColor(0.8f, 0.3f, 0.3f, 1.0f)).Padding(FMargin(15)).Child(Text(TEXT("Center Top Block")).Color(FLinearColor::White))
                )
            )
        )
    );

    auto Root = Container().Color(FLinearColor::White).Child(
        Column()(
            AppBar,
            Expanded().Child(Content)
        )
    );

    if (WidgetTree) WidgetTree->RootWidget = Root.Widget;
    return Root.Widget->TakeWidget();
}
void UMediaExampleWidget::OnBackClicked() { RemoveFromParent(); }
