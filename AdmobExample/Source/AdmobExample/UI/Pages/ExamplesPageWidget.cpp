#include "ExamplesPageWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"
#include "Examples/TextExampleWidget.h"
#include "Examples/LayoutExampleWidget.h"
#include "Examples/FormsExampleWidget.h"
#include "Examples/ListsExampleWidget.h"
#include "Examples/MediaExampleWidget.h"

using namespace Flutter;

TSharedRef<SWidget> UExamplesPageWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);

    auto MyCol = Column()(
        Center()(Text(TEXT("FlutterUMG Examples")).FontSize(20).Color(FLinearColor(0.13f, 0.13f, 0.13f, 1.0f))),
        SizedBox(1.0f, 20.0f),
        Expanded().Child(
            ListView()(
                Flutter::Padding(FMargin(16.f, 8.f)).Child(
                    ElevatedButton().OnPressed(this, TEXT("OnTextExampleClicked")).Child(
                        Flutter::Padding(FMargin(16.f, 12.f)).Child(Text(TEXT("Text & Typography")).FontSize(16).Color(FLinearColor::White))
                    )
                ),
                Flutter::Padding(FMargin(16.f, 8.f)).Child(
                    ElevatedButton().OnPressed(this, TEXT("OnLayoutExampleClicked")).Child(
                        Flutter::Padding(FMargin(16.f, 12.f)).Child(Text(TEXT("Complex Layouts (Row/Col/Stack)")).FontSize(16).Color(FLinearColor::White))
                    )
                ),
                Flutter::Padding(FMargin(16.f, 8.f)).Child(
                    ElevatedButton().OnPressed(this, TEXT("OnFormsExampleClicked")).Child(
                        Flutter::Padding(FMargin(16.f, 12.f)).Child(Text(TEXT("Forms & TextFields")).FontSize(16).Color(FLinearColor::White))
                    )
                ),
                Flutter::Padding(FMargin(16.f, 8.f)).Child(
                    ElevatedButton().OnPressed(this, TEXT("OnListsExampleClicked")).Child(
                        Flutter::Padding(FMargin(16.f, 12.f)).Child(Text(TEXT("Data Lists & Cards")).FontSize(16).Color(FLinearColor::White))
                    )
                ),
                Flutter::Padding(FMargin(16.f, 8.f)).Child(
                    ElevatedButton().OnPressed(this, TEXT("OnMediaExampleClicked")).Child(
                        Flutter::Padding(FMargin(16.f, 12.f)).Child(Text(TEXT("Media, Images & Alignment")).FontSize(16).Color(FLinearColor::White))
                    )
                )
            )
        )
    );

    if (WidgetTree) {
        WidgetTree->RootWidget = MyCol.Widget; // Anchor for Garbage Collector
    }

    return MyCol.Widget->TakeWidget();
}

void UExamplesPageWidget::PushExamplePage(TSubclassOf<UUserWidget> WidgetClass) {
    if (WidgetClass) {
        UUserWidget* ExamplePanel = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
        if (ExamplePanel) {
            ExamplePanel->AddToViewport(10); // Render above Bottom Nav
        }
    }
}

void UExamplesPageWidget::OnTextExampleClicked() {
    PushExamplePage(UTextExampleWidget::StaticClass());
}

void UExamplesPageWidget::OnLayoutExampleClicked() {
    PushExamplePage(ULayoutExampleWidget::StaticClass());
}

void UExamplesPageWidget::OnFormsExampleClicked() {
    PushExamplePage(UFormsExampleWidget::StaticClass());
}

void UExamplesPageWidget::OnListsExampleClicked() {
    PushExamplePage(UListsExampleWidget::StaticClass());
}

void UExamplesPageWidget::OnMediaExampleClicked() {
    PushExamplePage(UMediaExampleWidget::StaticClass());
}
