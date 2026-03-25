#include "AboutPageWidget.h"
#include "FlutterUMGWidgets.h"

using namespace Flutter;

TSharedRef<SWidget> UAboutPageWidget::RebuildWidget() {
    FFlutterBuildContext Context(this);
    auto AboutWidget = Center()(Text(TEXT("About Page")).FontSize(24));
    return AboutWidget.Widget->TakeWidget();
}
