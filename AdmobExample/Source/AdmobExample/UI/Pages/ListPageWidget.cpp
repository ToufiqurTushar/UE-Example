#include "ListPageWidget.h"
#include "FlutterUMGWidgets.h"

using namespace Flutter;

TSharedRef<SWidget> UListPageWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);

    auto MyCol = Column()(
        Center()(Text(TEXT("ListView.builder Example")).FontSize(18).Color(FLinearColor(0.13f, 0.13f, 0.13f, 1.0f))),
        SizedBox(1.0f, 10.0f),
        Expanded().Child(
            ListView::builder(20, [this](int32 Index) -> UWidget* {
                return Flutter::Padding(FMargin(8.f, 4.f, 8.f, 4.f)).Child(
                    InkWell().OnTap(this, TEXT("OnListItemClicked"), Index).Child(
                        Card().SetElevation(4.0f).SetBorderRadius(8.0f).Child(
                            ListTile()
                                .Leading(Container().Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f)).Padding(FMargin(8.f)).Child(Text(TEXT("#")).Color(FLinearColor::White).FontSize(16)))
                                .Title(Text(FString::Printf(TEXT("Item %d"), Index)).FontSize(16))
                                .Subtitle(Text(TEXT("Click to see index.")).FontSize(12).Color(FLinearColor(0.4f, 0.4f, 0.4f, 1.0f)))
                                .Trailing(Text(TEXT("Click Me")).FontSize(14).Color(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f)))
                        )
                    )
                );
            })
        )
    );

    return MyCol.Widget->TakeWidget();
}

void UListPageWidget::OnListItemClicked(int32 Index) {
    UE_LOG(LogTemp, Warning, TEXT("List item %d clicked!"), Index);
}
