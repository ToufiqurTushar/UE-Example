#include "AboutPageWidget.h"
#include "FlutterUMGWidgets.h"
#include "Blueprint/WidgetTree.h"

using namespace Flutter;

TSharedRef<SWidget> UAboutPageWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);
    auto AboutWidget = Center()(Text(TEXT("About Page")).FontSize(24));
    if (WidgetTree) {
        WidgetTree->RootWidget = AboutWidget.Widget;
    }

    return AboutWidget.Widget->TakeWidget();
}
