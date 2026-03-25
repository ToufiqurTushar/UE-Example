#include "TextExampleWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"

using namespace Flutter;

TSharedRef<SWidget> UTextExampleWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);

    auto AppBar = Container()
        .Color(FLinearColor(0.1f, 0.5f, 0.9f, 1.0f))
        .Padding(FMargin(16.f, 15.f))
        .Child(
            Row().MainAxisAlignment(0)(
                ElevatedButton().OnPressed(this, TEXT("OnBackClicked")).Child(
                    Text(TEXT("Back")).Color(FLinearColor::White).FontSize(14)
                ),
                SizedBox(16.f, 1.f),
                Text(TEXT("Text Showcase")).FontSize(20).Color(FLinearColor::White)
            )
        );

    auto Content = Flutter::Padding(FMargin(24.f)).Child(
        Column()(
            Text(TEXT("Headline Large")).FontSize(32).Color(FLinearColor::Black),
            SizedBox(1.f, 12.f),
            Text(TEXT("Title Medium")).FontSize(22).Color(FLinearColor(0.3f, 0.3f, 0.3f, 1.f)),
            SizedBox(1.f, 12.f),
            Text(TEXT("Body Small")).FontSize(14).Color(FLinearColor(0.5f, 0.5f, 0.5f, 1.f)),
            SizedBox(1.f, 24.f),
            Text(TEXT("Warning Error Text")).FontSize(16).Color(FLinearColor::Red),
            SizedBox(1.f, 24.f),
            Text(TEXT("Primary Colored Header")).FontSize(20).Color(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f))
        )
    );

    auto Root = Container().Color(FLinearColor::White).Child(
        Column()(
            AppBar,
            Expanded().Child(Content)
        )
    );

    if (WidgetTree) {
        WidgetTree->RootWidget = Root.Widget;
    }

    return Root.Widget->TakeWidget();
}

void UTextExampleWidget::OnBackClicked() {
    RemoveFromParent();
}
