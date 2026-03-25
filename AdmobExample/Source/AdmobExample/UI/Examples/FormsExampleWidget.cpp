#include "FormsExampleWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"

using namespace Flutter;

TSharedRef<SWidget> UFormsExampleWidget::RebuildWidget() {
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
                Text(TEXT("Forms Showcase")).FontSize(20).Color(FLinearColor::White)
            )
        );

    auto Content = Flutter::Padding(FMargin(24.f)).Child(
        Column()(
            Text(TEXT("Input Fields")).FontSize(20).Color(FLinearColor::Black),
            SizedBox(1.f, 12.f),
            TextField().HintText(TEXT("Enter your name...")).OnChanged(this, TEXT("OnTextChanged")),
            SizedBox(1.f, 12.f),
            TextField().HintText(TEXT("Enter your email...")).OnChanged(this, TEXT("OnTextChanged")),
            SizedBox(1.f, 24.f),
            ElevatedButton().OnPressed(this, TEXT("OnSubmitClicked")).Child(
                Flutter::Padding(FMargin(24.f, 12.f)).Child(Text(TEXT("Submit Details")).FontSize(16).Color(FLinearColor::White))
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
void UFormsExampleWidget::OnBackClicked() { RemoveFromParent(); }
void UFormsExampleWidget::OnTextChanged(const FText& Text) { }
void UFormsExampleWidget::OnSubmitClicked() { 
    if (WidgetTree && WidgetTree->RootWidget) {
        Fluttertoast::showToast(this, Cast<UCanvasPanel>(WidgetTree->RootWidget), TEXT("Submitted Forms successfully!")); 
    }
}
