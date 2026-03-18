#include "FlutterBuildContext.h"

UUserWidget* FFlutterBuildContext::CurrentContextWidget = nullptr;

FFlutterBuildContext::FFlutterBuildContext(UUserWidget* InContextWidget)
{
    PreviousContextWidget = CurrentContextWidget;
    CurrentContextWidget = InContextWidget;
}

FFlutterBuildContext::~FFlutterBuildContext()
{
    CurrentContextWidget = PreviousContextWidget;
}

UUserWidget* FFlutterBuildContext::GetCurrentContext()
{
    return CurrentContextWidget;
}
