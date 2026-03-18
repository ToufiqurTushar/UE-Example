#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

class FLUTTERUMG_API FFlutterBuildContext
{
public:
    FFlutterBuildContext(UUserWidget* InContextWidget);
    ~FFlutterBuildContext();

    static UUserWidget* GetCurrentContext();

private:
    // We use a simple static for the main game thread
    static UUserWidget* CurrentContextWidget;
    UUserWidget* PreviousContextWidget;
};

template<typename T>
T* CreateFlutterUMGWidget()
{
    UUserWidget* Context = FFlutterBuildContext::GetCurrentContext();
    if (Context)
    {
        return NewObject<T>(Context);
    }
    // Fallback if no context
    return NewObject<T>((UObject*)GetTransientPackage());
}
