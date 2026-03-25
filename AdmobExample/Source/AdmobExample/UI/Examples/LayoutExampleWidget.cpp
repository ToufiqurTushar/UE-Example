#include "LayoutExampleWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"

using namespace Flutter;

TSharedRef<SWidget> ULayoutExampleWidget::RebuildWidget() {
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
                Text(TEXT("Layout Showcase")).FontSize(20).Color(FLinearColor::White)
            )
        );

    auto TopRow = Row().MainAxisAlignment(1)(
        Container().Color(FLinearColor::Red).Padding(FMargin(20.f)).Child(Text(TEXT("A")).Color(FLinearColor::White)),
        SizedBox(10.f, 1.f),
        Container().Color(FLinearColor::Green).Padding(FMargin(20.f)).Child(Text(TEXT("B")).Color(FLinearColor::White)),
        SizedBox(10.f, 1.f),
        Container().Color(FLinearColor::Blue).Padding(FMargin(20.f)).Child(Text(TEXT("C")).Color(FLinearColor::White))
    );

    auto SideStack = Stack()(
        Container().Color(FLinearColor::Yellow).Padding(FMargin(100.f, 100.f)),
        Positioned().Left(10.f).Top(10.f).Child(
            Container().Color(FLinearColor::Black).Padding(FMargin(20.f, 20.f))
        )
    );

    auto ComplexLayoutCol = Column()(
        Flutter::Padding(FMargin(16.f)).Child(Text(TEXT("Row Distribution")).FontSize(18).Color(FLinearColor::Black)),
        Flutter::Padding(FMargin(16.f)).Child(TopRow),
        Flutter::Padding(FMargin(16.f)).Child(Text(TEXT("Stack Overlays")).FontSize(18).Color(FLinearColor::Black)),
        Flutter::Padding(FMargin(20.f)).Child(SideStack)
    );

    auto Root = Container().Color(FLinearColor::White).Child(
        Column()(
            AppBar,
            Expanded().Child(ComplexLayoutCol)
        )
    );

    if (WidgetTree) {
        WidgetTree->RootWidget = Root.Widget;
    }

    return Root.Widget->TakeWidget();
}

void ULayoutExampleWidget::OnBackClicked() {
    RemoveFromParent();
}
