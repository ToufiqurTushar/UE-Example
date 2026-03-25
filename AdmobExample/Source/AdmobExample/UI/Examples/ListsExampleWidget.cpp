#include "ListsExampleWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"

using namespace Flutter;

TSharedRef<SWidget> UListsExampleWidget::RebuildWidget() {
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
                Text(TEXT("Lists & Cards Showcase")).FontSize(20).Color(FLinearColor::White)
            )
        );

    auto List = ListView();
    for(int i = 0; i < 20; ++i) {
        FString TitleStr = FString::Printf(TEXT("List Element %d"), i);
        List(
            Flutter::Padding(FMargin(0, 4.f, 0, 4.f)).Child(
                Card().SetElevation(2.0f).SetBorderRadius(8.f).Child(
                    ListTile()
                    .Title(Text(TitleStr).FontSize(16).Color(FLinearColor::Black))
                    .Subtitle(Text(TEXT("Subtitle description testing.")).FontSize(12).Color(FLinearColor(0.5f, 0.5f, 0.5f, 1.0f)))
                    .Leading(Container().Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f)).Padding(FMargin(15.f)).Child(Text(TEXT("A")).Color(FLinearColor::White).FontSize(20)))
                )
            )
        );
    }

    auto Content = Flutter::Padding(FMargin(16.f)).Child(List);

    auto Root = Container().Color(FLinearColor::White).Child(
        Column()(
            AppBar,
            Expanded().Child(Content)
        )
    );

    if (WidgetTree) WidgetTree->RootWidget = Root.Widget;
    return Root.Widget->TakeWidget();
}
void UListsExampleWidget::OnBackClicked() { RemoveFromParent(); }
