#pragma once

#include "CoreMinimal.h"
#include "FlutterBuildContext.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Spacer.h"
#include "Components/VerticalBox.h"
#include "Components/HorizontalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/Border.h"
#include "Components/BorderSlot.h"
#include "Components/Image.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "Components/SizeBox.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateTypes.h"
#include "Components/WidgetSwitcher.h"

namespace Flutter
{
    struct Text
    {
        UTextBlock* Widget;
        Text(const FString& InText) {
            Widget = CreateFlutterUMGWidget<UTextBlock>();
            Widget->SetText(FText::FromString(InText));
            Widget->SetColorAndOpacity(FSlateColor(FLinearColor(0.13f, 0.13f, 0.13f, 1.0f)));
            FSlateFontInfo FontInfo = Widget->GetFont();
            FontInfo.Size = 14; 
            Widget->SetFont(FontInfo);
        }
        Text& FontSize(int32 Size) {
            FSlateFontInfo FontInfo = Widget->GetFont();
            FontInfo.Size = Size;
            Widget->SetFont(FontInfo);
            return *this;
        }
        Text& Color(FLinearColor InColor) {
            Widget->SetColorAndOpacity(FSlateColor(InColor));
            return *this;
        }
		Text& TextAlign(ETextJustify::Type Alignment) {
			Widget->SetJustification(Alignment);
			return *this;
		}
        operator UWidget*() const { return Widget; }
    };

    struct ElevatedButton
    {
        UButton* Widget;
        ElevatedButton() {
            Widget = CreateFlutterUMGWidget<UButton>();
            
            FButtonStyle ButtonStyle = Widget->GetStyle();
            FSlateBrush NormalBrush = ButtonStyle.Normal;
            NormalBrush.TintColor = FSlateColor(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f)); 
            NormalBrush.DrawAs = ESlateBrushDrawType::RoundedBox;
            NormalBrush.OutlineSettings.CornerRadii = FVector4(4,4,4,4);
            
            FSlateBrush HoveredBrush = NormalBrush;
            HoveredBrush.TintColor = FSlateColor(FLinearColor(0.26f, 0.67f, 0.98f, 1.0f)); 
            
            FSlateBrush PressedBrush = NormalBrush;
            PressedBrush.TintColor = FSlateColor(FLinearColor(0.12f, 0.53f, 0.90f, 1.0f)); 
            
            ButtonStyle.SetNormal(NormalBrush);
            ButtonStyle.SetHovered(HoveredBrush);
            ButtonStyle.SetPressed(PressedBrush);
            Widget->SetStyle(ButtonStyle);
        }
        
        ElevatedButton& OnPressed(UObject* Object, FName FuncName) {
            FScriptDelegate Delegate;
            Delegate.BindUFunction(Object, FuncName);
            Widget->OnClicked.AddUnique(Delegate);
            return *this;
        }

        ElevatedButton& Child(UWidget* InChild) {
            if (UTextBlock* TextChild = Cast<UTextBlock>(InChild)) {
                TextChild->SetColorAndOpacity(FSlateColor(FLinearColor::White));
            }
            UBorder* Pad = CreateFlutterUMGWidget<UBorder>();
            Pad->SetPadding(FMargin(16, 8)); 
            Pad->SetBrushColor(FLinearColor::Transparent);
            Pad->SetHorizontalAlignment(HAlign_Center);
            Pad->SetVerticalAlignment(VAlign_Center);
            Pad->AddChild(InChild);

            Widget->AddChild(Pad);
            return *this;
        }
        operator UWidget*() const { return Widget; }
    };

    struct SizedBox
    {
        USpacer* Widget;
        SizedBox(float Width = 1.0f, float Height = 1.0f) {
            Widget = CreateFlutterUMGWidget<USpacer>();
            Widget->SetSize(FVector2D(Width, Height));
        }
        SizedBox& Height(float InHeight) {
            Widget->SetSize(FVector2D(Widget->GetSize().X, InHeight));
            return *this;
        }
		SizedBox& Width(float InWidth) {
			Widget->SetSize(FVector2D(InWidth, Widget->GetSize().Y));
			return *this;
		}
        operator UWidget*() const { return Widget; }
    };

    struct Expanded
    {
        UWidget* ChildWidget;
        int32 Flex;
        Expanded(int32 InFlex = 1) : ChildWidget(nullptr), Flex(InFlex) {}
        Expanded& Child(UWidget* InChild) { ChildWidget = InChild; return *this; }
    };

    struct Positioned
    {
        UWidget* ChildWidget = nullptr;
        TOptional<float> L, T, R, B;

        Positioned() {}
        Positioned& Left(float v) { L = v; return *this; }
        Positioned& Top(float v) { T = v; return *this; }
        Positioned& Right(float v) { R = v; return *this; }
        Positioned& Bottom(float v) { B = v; return *this; }
        Positioned& Child(UWidget* InChild) { ChildWidget = InChild; return *this; }

        void Apply(UCanvasPanelSlot* Slot) const {
            if (!Slot) return;
            if (L.IsSet() && R.IsSet() && T.IsSet() && B.IsSet()) {
                Slot->SetAnchors(FAnchors(0,0,1,1));
                Slot->SetOffsets(FMargin(L.GetValue(), T.GetValue(), R.GetValue(), B.GetValue()));
            } else {
                float MinX = L.IsSet() ? 0.0f : (R.IsSet() ? 1.0f : 0.5f);
                float MinY = T.IsSet() ? 0.0f : (B.IsSet() ? 1.0f : 0.5f);
                float AlignX = L.IsSet() ? 0.0f : (R.IsSet() ? 1.0f : 0.5f);
                float AlignY = T.IsSet() ? 0.0f : (B.IsSet() ? 1.0f : 0.5f);
                
                Slot->SetAnchors(FAnchors(MinX, MinY, MinX, MinY));
                Slot->SetAlignment(FVector2D(AlignX, AlignY));
                
                float OffsetX = L.IsSet() ? L.GetValue() : (R.IsSet() ? -R.GetValue() : 0.0f);
                float OffsetY = T.IsSet() ? T.GetValue() : (B.IsSet() ? -B.GetValue() : 0.0f);
                
                Slot->SetOffsets(FMargin(OffsetX, OffsetY, 0, 0));
                Slot->SetAutoSize(true);
            }
        }
    };

    struct Column
    {
        UVerticalBox* Widget;
        Column() {
            Widget = CreateFlutterUMGWidget<UVerticalBox>();
        }
        
        Column& MainAxisAlignment(uint8 Alignment) {
            return *this;
        }

        template<typename... Args>
        Column& operator()(Args... args) {
            (AddChild(args), ...);
            return *this;
        }

    private:
        void AddChild(UWidget* Child) {
            if (Child) {
                if (UVerticalBoxSlot* Slot = Widget->AddChildToVerticalBox(Child)) {
                    Slot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                    Slot->SetHorizontalAlignment(HAlign_Fill);
                }
            }
        }
        void AddChild(const Expanded& Exp) {
            if (Exp.ChildWidget) {
                if (UVerticalBoxSlot* Slot = Widget->AddChildToVerticalBox(Exp.ChildWidget)) {
                    FSlateChildSize SizeRule(ESlateSizeRule::Fill);
                    SizeRule.Value = Exp.Flex;
                    Slot->SetSize(SizeRule);
                    Slot->SetHorizontalAlignment(HAlign_Fill);
                }
            }
        }
    public:
        operator UWidget*() const { return Widget; }
    };

    struct Row
    {
        UHorizontalBox* Widget;
        Row() {
            Widget = CreateFlutterUMGWidget<UHorizontalBox>();
        }
        
        Row& MainAxisAlignment(uint8 Alignment) {
            return *this;
        }

        template<typename... Args>
        Row& operator()(Args... args) {
            (AddChild(args), ...);
            return *this;
        }

    private:
        void AddChild(UWidget* Child) {
            if (Child) {
                if (UHorizontalBoxSlot* Slot = Widget->AddChildToHorizontalBox(Child)) {
                    Slot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                    Slot->SetVerticalAlignment(VAlign_Fill);
                }
            }
        }
        void AddChild(const Expanded& Exp) {
            if (Exp.ChildWidget) {
                if (UHorizontalBoxSlot* Slot = Widget->AddChildToHorizontalBox(Exp.ChildWidget)) {
                    FSlateChildSize SizeRule(ESlateSizeRule::Fill);
                    SizeRule.Value = Exp.Flex;
                    Slot->SetSize(SizeRule);
                    Slot->SetVerticalAlignment(VAlign_Fill);
                }
            }
        }
    public:
        operator UWidget*() const { return Widget; }
    };

    struct Center
    {
        UOverlay* Widget;
        Center() {
            Widget = CreateFlutterUMGWidget<UOverlay>();
        }

        Center& operator()(UWidget* ChildWidget) {
            UOverlaySlot* Slot = Widget->AddChildToOverlay(ChildWidget);
            Slot->SetHorizontalAlignment(HAlign_Center);
            Slot->SetVerticalAlignment(VAlign_Center);
            return *this;
        }
        operator UWidget*() const { return Widget; }
    };

    struct Align
    {
        UOverlay* Widget;
		EHorizontalAlignment HAlign;
		EVerticalAlignment VAlign;
        Align(EHorizontalAlignment InHAlign, EVerticalAlignment InVAlign) : HAlign(InHAlign), VAlign(InVAlign) {
            Widget = CreateFlutterUMGWidget<UOverlay>();
        }

        Align& operator()(UWidget* ChildWidget) {
            UOverlaySlot* Slot = Widget->AddChildToOverlay(ChildWidget);
            Slot->SetHorizontalAlignment(HAlign);
            Slot->SetVerticalAlignment(VAlign);
            return *this;
        }
        operator UWidget*() const { return Widget; }
    };

    struct Container
    {
        UBorder* Widget;
        Container() {
            Widget = CreateFlutterUMGWidget<UBorder>();
        }
        Container& Color(FLinearColor InColor) {
            Widget->SetBrushColor(InColor);
            return *this;
        }
		Container& Padding(FMargin InPadding) {
			Widget->SetPadding(InPadding);
			return *this;
		}
        Container& Child(UWidget* ChildWidget) {
            Widget->AddChild(ChildWidget);
            if (auto* Slot = Cast<UBorderSlot>(Widget->Slot)) {
                Slot->SetHorizontalAlignment(HAlign_Center);
                Slot->SetVerticalAlignment(VAlign_Center);
            }
            return *this;
        }
        operator UWidget*() const { return Widget; }
    };

	struct Padding
	{
		UBorder* Widget;
		Padding(FMargin InPadding) {
			Widget = CreateFlutterUMGWidget<UBorder>();
            Widget->SetBrushColor(FLinearColor::Transparent);
			Widget->SetPadding(InPadding);
		}
		Padding& Child(UWidget* ChildWidget) {
            Widget->AddChild(ChildWidget);
			if (auto* Slot = Cast<UBorderSlot>(Widget->Slot)) {
                Slot->SetHorizontalAlignment(HAlign_Fill);
                Slot->SetVerticalAlignment(VAlign_Fill);
            }
            return *this;
        }
        operator UWidget*() const { return Widget; }
	};

	struct Image
	{
		UImage* Widget;
		Image() {
			Widget = CreateFlutterUMGWidget<UImage>();
		}
		Image& Color(FLinearColor InColor) {
			Widget->SetColorAndOpacity(InColor);
			return *this;
		}
		Image& Brush(const FSlateBrush& InBrush) {
			Widget->SetBrush(InBrush);
			return *this;
		}
		operator UWidget*() const { return Widget; }
	};

	struct TextField
	{
		UEditableTextBox* Widget;
		TextField() {
			Widget = CreateFlutterUMGWidget<UEditableTextBox>();
            
            FEditableTextBoxStyle Style = Widget->WidgetStyle;
            
            Style.BackgroundImageNormal.DrawAs = ESlateBrushDrawType::RoundedBox;
            Style.BackgroundImageNormal.OutlineSettings.CornerRadii = FVector4(4,4,4,4);
            Style.BackgroundImageNormal.TintColor = FSlateColor(FLinearColor(0.96f, 0.96f, 0.96f, 1.0f)); 
            
            Style.BackgroundImageHovered = Style.BackgroundImageNormal;
            Style.BackgroundImageHovered.TintColor = FSlateColor(FLinearColor(0.93f, 0.93f, 0.93f, 1.0f)); 
            
            Style.BackgroundImageFocused = Style.BackgroundImageNormal;
            Style.BackgroundImageFocused.TintColor = FSlateColor(FLinearColor(0.90f, 0.90f, 0.90f, 1.0f)); 

            Widget->WidgetStyle = Style;
		}
		TextField& HintText(const FString& Hint) {
			Widget->SetHintText(FText::FromString(Hint));
			return *this;
		}
		TextField& Text(const FString& InText) {
			Widget->SetText(FText::FromString(InText));
			return *this;
		}
		TextField& OnChanged(UObject* Object, FName FuncName) {
            FScriptDelegate Delegate;
            Delegate.BindUFunction(Object, FuncName);
            Widget->OnTextChanged.AddUnique(Delegate);
            return *this;
        }
		operator UWidget*() const { return Widget; }
	};

    struct Card
    {
        UOverlay* Widget;
        UWidget* ChildWidget = nullptr;
        float Elevation = 4.0f;
        float BorderRadius = 8.0f;
        FLinearColor Color = FLinearColor::White;

        Card() {
            Widget = CreateFlutterUMGWidget<UOverlay>();
        }
        
        Card& SetElevation(float InElevation) { Elevation = InElevation; return *this; }
        Card& SetBorderRadius(float InRadius) { BorderRadius = InRadius; return *this; }
        Card& SetColor(FLinearColor InColor) { Color = InColor; return *this; }

        Card& Child(UWidget* InChild) { ChildWidget = InChild; return *this; }

        operator UWidget*() {
            if (Widget->GetChildrenCount() == 0) {
                // Shadow Border
                UBorder* Shadow = CreateFlutterUMGWidget<UBorder>();
                FSlateBrush ShadowBrush;
                ShadowBrush.DrawAs = ESlateBrushDrawType::RoundedBox;
                ShadowBrush.OutlineSettings.CornerRadii = FVector4(BorderRadius, BorderRadius, BorderRadius, BorderRadius);
                // Dynamic shadow opacity based on elevation
                ShadowBrush.TintColor = FSlateColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.15f + (Elevation * 0.01f))); 
                Shadow->SetBrush(ShadowBrush);
                
                UOverlaySlot* ShadowSlot = Widget->AddChildToOverlay(Shadow);
                ShadowSlot->SetHorizontalAlignment(HAlign_Fill);
                ShadowSlot->SetVerticalAlignment(VAlign_Fill);
                ShadowSlot->SetPadding(FMargin(0, Elevation, 0, 0)); // Shift down by Elevation

                // Foreground Card Border
                UBorder* Foreground = CreateFlutterUMGWidget<UBorder>();
                FSlateBrush ForegroundBrush;
                ForegroundBrush.DrawAs = ESlateBrushDrawType::RoundedBox;
                ForegroundBrush.OutlineSettings.CornerRadii = FVector4(BorderRadius, BorderRadius, BorderRadius, BorderRadius);
                ForegroundBrush.TintColor = FSlateColor(Color);
                Foreground->SetBrush(ForegroundBrush);
                
                if (ChildWidget) {
                    Foreground->AddChild(ChildWidget);
                    if (auto* Slot = Cast<UBorderSlot>(Foreground->Slot)) {
                        Slot->SetPadding(FMargin(0.0f)); // Inner padding applied explicitly by children
                    }
                }
                
                UOverlaySlot* FgSlot = Widget->AddChildToOverlay(Foreground);
                FgSlot->SetHorizontalAlignment(HAlign_Fill);
                FgSlot->SetVerticalAlignment(VAlign_Fill);
                FgSlot->SetPadding(FMargin(0, 0, 0, Elevation)); // Lift up by Elevation
            }
            return Widget;
        }
    };

    struct ListTile
    {
        UBorder* Widget;
        UWidget* LeadingWidget = nullptr;
        UWidget* TitleWidget = nullptr;
        UWidget* SubtitleWidget = nullptr;
        UWidget* TrailingWidget = nullptr;

        ListTile() {
            Widget = CreateFlutterUMGWidget<UBorder>();
            Widget->SetBrushColor(FLinearColor::Transparent); 
            Widget->SetPadding(FMargin(16.f, 8.f));
        }

        ListTile& Leading(UWidget* InLeading) { LeadingWidget = InLeading; return *this; }
        ListTile& Title(UWidget* InTitle) { TitleWidget = InTitle; return *this; }
        ListTile& Subtitle(UWidget* InSubtitle) { SubtitleWidget = InSubtitle; return *this; }
        ListTile& Trailing(UWidget* InTrailing) { TrailingWidget = InTrailing; return *this; }

        operator UWidget*() {
            if (Widget->GetChildrenCount() == 0) {
                Row R;
                if (LeadingWidget) {
                    R(Padding(FMargin(0, 0, 16.f, 0)).Child(Center()(LeadingWidget)));
                }
                if (TitleWidget || SubtitleWidget) {
                    Column C;
                    if (TitleWidget) C(TitleWidget);
                    if (SubtitleWidget) C(Padding(FMargin(0, 4.f, 0, 0)).Child(SubtitleWidget));
                    R(Expanded().Child(C));
                } else {
                    R(Expanded().Child(SizedBox()));
                }
                if (TrailingWidget) {
                    R(Padding(FMargin(16.f, 0, 0, 0)).Child(Center()(TrailingWidget)));
                }
                Widget->AddChild(R);
                if (auto* Slot = Cast<UBorderSlot>(Widget->Slot)) {
                    Slot->SetHorizontalAlignment(HAlign_Fill);
                    Slot->SetVerticalAlignment(VAlign_Center);
                }
            }
            return Widget;
        }
    };

	struct ListView
	{
		UScrollBox* Widget;
		ListView() {
			Widget = CreateFlutterUMGWidget<UScrollBox>();
		}
		template<typename... Args>
        ListView& operator()(Args... args) {
            (Widget->AddChild(args), ...);
            return *this;
        }

        static ListView builder(int32 ItemCount, TFunctionRef<UWidget*(int32 Index)> ItemBuilder) {
            ListView List;
            for (int32 i = 0; i < ItemCount; ++i) {
                if (UWidget* Child = ItemBuilder(i)) {
                    List.Widget->AddChild(Child);
                }
            }
            return List;
        }

		operator UWidget*() const { return Widget; }
	};

    struct Stack
    {
        UCanvasPanel* Widget;
        Stack() {
            Widget = CreateFlutterUMGWidget<UCanvasPanel>();
        }

        template<typename... Args>
        Stack& operator()(Args... args) {
            (AddChild(args), ...);
            return *this;
        }

    private:
        void AddChild(UWidget* Child) {
            if (Child) {
                if (UCanvasPanelSlot* Slot = Widget->AddChildToCanvas(Child)) {
                    Slot->SetAutoSize(true);
                    Slot->SetAnchors(FAnchors(0,0,0,0));
                }
            }
        }
        void AddChild(const Positioned& Pos) {
            if (Pos.ChildWidget) {
                if (UCanvasPanelSlot* Slot = Widget->AddChildToCanvas(Pos.ChildWidget)) {
                    Pos.Apply(Slot);
                }
            }
        }
    public:
        operator UWidget*() const { return Widget; }
    };

    struct Scaffold
    {
        UCanvasPanel* Widget;
        UWidget* AppBarWidget = nullptr;
        UWidget* BodyWidget = nullptr;
        UWidget* BottomNavWidget = nullptr;

        Scaffold() {
            Widget = CreateFlutterUMGWidget<UCanvasPanel>();
            UBorder* Background = CreateFlutterUMGWidget<UBorder>();
            Background->SetBrushColor(FLinearColor(0.98f, 0.98f, 0.98f, 1.0f)); 
            if (UCanvasPanelSlot* BgSlot = Widget->AddChildToCanvas(Background)) {
                BgSlot->SetAnchors(FAnchors(0,0,1,1));
                BgSlot->SetOffsets(FMargin(0,0,0,0));
            }
        }

        Scaffold& AppBar(UWidget* InAppBar) {
            AppBarWidget = InAppBar;
            return *this;
        }

        Scaffold& Body(UWidget* InBody) {
            BodyWidget = InBody;
            return *this;
        }

        Scaffold& BottomNavigationBar(UWidget* InBottomNav) {
            BottomNavWidget = InBottomNav;
            return *this;
        }

        UWidget* Build() {
            UVerticalBox* LayoutBox = CreateFlutterUMGWidget<UVerticalBox>();
            if (AppBarWidget) {
                if (UVerticalBoxSlot* Slot = LayoutBox->AddChildToVerticalBox(AppBarWidget)) {
                    Slot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                }
            }
            if (BodyWidget) {
                if (UVerticalBoxSlot* Slot = LayoutBox->AddChildToVerticalBox(BodyWidget)) {
                    Slot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
                }
            }
            if (BottomNavWidget) {
                if (UVerticalBoxSlot* Slot = LayoutBox->AddChildToVerticalBox(BottomNavWidget)) {
                    Slot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
                }
            }

            if (UCanvasPanelSlot* RootSlot = Widget->AddChildToCanvas(LayoutBox)) {
                RootSlot->SetAnchors(FAnchors(0,0,1,1));
                RootSlot->SetOffsets(FMargin(0,0,0,0));
            }
            return Widget;
        }
    };

    // Helper for AppBar
    struct AppBar
    {
        UBorder* Widget;
        AppBar() {
            Widget = CreateFlutterUMGWidget<UBorder>();
            Widget->SetBrushColor(FLinearColor(0.13f, 0.59f, 0.95f, 1.0f)); 
        }
        AppBar& Title(UWidget* TitleWidget) {
            Widget->AddChild(TitleWidget);
            if (auto* Slot = Cast<UBorderSlot>(Widget->Slot)) {
                Slot->SetPadding(FMargin(16.f, 16.f, 16.f, 16.f)); 
                Slot->SetHorizontalAlignment(HAlign_Left);
                Slot->SetVerticalAlignment(VAlign_Center);
            }
            if (UTextBlock* TextTitle = Cast<UTextBlock>(TitleWidget)) {
                TextTitle->SetColorAndOpacity(FSlateColor(FLinearColor::White));
                FSlateFontInfo FontInfo = TextTitle->GetFont();
                FontInfo.Size = 20; 
                TextTitle->SetFont(FontInfo);
            }
            return *this;
        }
        operator UWidget*() const { return Widget; }
    };

    struct Fluttertoast
    {
        static void showToast(UUserWidget* ContextWidget, UCanvasPanel* RootCanvas, const FString& Message)
        {
            if (!RootCanvas || !ContextWidget) return;

            FFlutterBuildContext Context(ContextWidget);
            UWidget* ToastWidget = 
                Container().Color(FLinearColor(0.2f, 0.2f, 0.2f, 0.9f)).Padding(FMargin(16.f, 8.f)).Child(
                    Text(Message).FontSize(16).Color(FLinearColor::White)
                );

            Positioned Pos;
            Pos.Bottom(150.f).Child(ToastWidget);
            if (UCanvasPanelSlot* Slot = RootCanvas->AddChildToCanvas(Pos.ChildWidget))
            {
                Pos.Apply(Slot);
            }

            TWeakObjectPtr<UWidget> WeakToast(ToastWidget);
            FTimerHandle TimerHandle;
            ContextWidget->GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([WeakToast]()
            {
                if (WeakToast.IsValid())
                {
                    WeakToast->RemoveFromParent();
                }
            }), 3.0f, false);
        }
    };

    struct IndexedStack
    {
        UWidgetSwitcher* Widget;
        IndexedStack() {
            Widget = CreateFlutterUMGWidget<UWidgetSwitcher>();
        }
        IndexedStack& Index(int32 ActiveIndex) {
            Widget->SetActiveWidgetIndex(ActiveIndex);
            return *this;
        }
        template<typename... Args>
        IndexedStack& operator()(Args... args) {
            (AddChild(args), ...);
            return *this;
        }
    private:
        void AddChild(UWidget* Child) {
            if (Child) Widget->AddChild(Child);
        }
    public:
        operator UWidget*() const { return Widget; }
    };

    struct BottomNavigationBarItem
    {
        FString IconText;
        FString Label;
        class UTexture2D* IconImage;

        BottomNavigationBarItem(const FString& InIcon, const FString& InLabel, UTexture2D* InImage = nullptr) 
            : IconText(InIcon), Label(InLabel), IconImage(InImage) {}
    };

    struct BottomNavigationBar
    {
        UBorder* Wrapper = nullptr;
        UHorizontalBox* Widget = nullptr;
        int32 CurrentIndex = 0;

        BottomNavigationBar() {
            Wrapper = CreateFlutterUMGWidget<UBorder>();
            Wrapper->SetBrushColor(FLinearColor(0.85f, 0.85f, 0.85f, 1.0f)); 
            Wrapper->SetPadding(FMargin(0, 0.5f, 0, 0)); 

            UBorder* InnerBg = CreateFlutterUMGWidget<UBorder>();
            InnerBg->SetBrushColor(FLinearColor(0.98f, 0.98f, 0.98f, 1.0f)); 
            InnerBg->SetPadding(FMargin(0, 4.f, 0, 16.f)); 
            
            Widget = CreateFlutterUMGWidget<UHorizontalBox>();
            InnerBg->AddChild(Widget);
            Wrapper->AddChild(InnerBg);
        }

        BottomNavigationBar(UHorizontalBox* ExistingWidget) {
            Widget = ExistingWidget;
        }

        BottomNavigationBar& Items(const TArray<BottomNavigationBarItem>& InItems, UObject* ContextObject, const TArray<FName>& Callbacks, int32 InCurrentIndex = 0) {
            Widget->ClearChildren();
            CurrentIndex = InCurrentIndex;
            
            for (int32 i = 0; i < InItems.Num(); ++i) {
                UBorder* ItemContainer = CreateFlutterUMGWidget<UBorder>();
                ItemContainer->SetBrushColor(FLinearColor::Transparent);
                
                UButton* Btn = CreateFlutterUMGWidget<UButton>();
                FButtonStyle BtnStyle = Btn->GetStyle();
                BtnStyle.Normal.TintColor = FSlateColor(FLinearColor::Transparent);
                BtnStyle.Hovered.TintColor = FSlateColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.04f));
                BtnStyle.Pressed.TintColor = FSlateColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.08f));
                BtnStyle.Normal.DrawAs = ESlateBrushDrawType::Box;
                BtnStyle.Hovered.DrawAs = ESlateBrushDrawType::Box;
                BtnStyle.Pressed.DrawAs = ESlateBrushDrawType::Box;
                Btn->SetStyle(BtnStyle);

                if (ContextObject && Callbacks.IsValidIndex(i)) {
                    FScriptDelegate Delegate;
                    Delegate.BindUFunction(ContextObject, Callbacks[i]);
                    Btn->OnClicked.AddUnique(Delegate);
                }

                UVerticalBox* VBox = CreateFlutterUMGWidget<UVerticalBox>();
                
                if (InItems[i].IconImage) {
                    FSlateBrush Brush;
                    Brush.SetResourceObject(InItems[i].IconImage);
                    Brush.ImageSize = FVector2D(CurrentIndex == i ? 26 : 22, CurrentIndex == i ? 26 : 22);
                    
                    Image ImgWidget;
                    ImgWidget.Brush(Brush);
                    ImgWidget.Color(CurrentIndex == i ? FLinearColor(0.13f, 0.59f, 0.95f, 1.0f) : FLinearColor(0.5f, 0.5f, 0.5f, 1.0f));
                    
                    if (UVerticalBoxSlot* VSlot = VBox->AddChildToVerticalBox(ImgWidget.Widget)) {
                        VSlot->SetHorizontalAlignment(HAlign_Center);
                    }
                } else {
                    UTextBlock* IconTxt = CreateFlutterUMGWidget<UTextBlock>();
                    IconTxt->SetText(FText::FromString(InItems[i].IconText));
                    FSlateFontInfo FontInfo = IconTxt->GetFont();
                    FontInfo.Size = CurrentIndex == i ? 26 : 22; 
                    IconTxt->SetFont(FontInfo);
                    IconTxt->SetColorAndOpacity(FSlateColor(CurrentIndex == i ? FLinearColor(0.13f, 0.59f, 0.95f, 1.0f) : FLinearColor(0.5f, 0.5f, 0.5f, 1.0f)));
                    if (UVerticalBoxSlot* VSlot = VBox->AddChildToVerticalBox(IconTxt)) {
                        VSlot->SetHorizontalAlignment(HAlign_Center);
                    }
                }

                UTextBlock* LabelTxt = CreateFlutterUMGWidget<UTextBlock>();
                LabelTxt->SetText(FText::FromString(InItems[i].Label));
                FSlateFontInfo LabelFont = LabelTxt->GetFont();
                LabelFont.Size = CurrentIndex == i ? 12 : 11; 
                LabelTxt->SetFont(LabelFont);
                LabelTxt->SetColorAndOpacity(FSlateColor(CurrentIndex == i ? FLinearColor(0.13f, 0.59f, 0.95f, 1.0f) : FLinearColor(0.5f, 0.5f, 0.5f, 1.0f)));
                if (UVerticalBoxSlot* VSlot = VBox->AddChildToVerticalBox(LabelTxt)) {
                    VSlot->SetHorizontalAlignment(HAlign_Center);
                    VSlot->SetPadding(FMargin(0, 4.f, 0, 0));
                }

                UBorder* Pad = CreateFlutterUMGWidget<UBorder>();
                Pad->SetPadding(FMargin(0, 4.f));
                Pad->SetBrushColor(FLinearColor::Transparent);
                Pad->AddChild(VBox);
                Pad->SetHorizontalAlignment(HAlign_Center);

                Btn->AddChild(Pad);
                ItemContainer->AddChild(Btn);
                
                if (UHorizontalBoxSlot* Slot = Widget->AddChildToHorizontalBox(ItemContainer)) {
                    Slot->SetSize(FSlateChildSize(ESlateSizeRule::Fill));
                    Slot->SetHorizontalAlignment(HAlign_Fill);
                }
            }
            return *this;
        }

        operator UWidget*() const { return Wrapper ? (UWidget*)Wrapper : (UWidget*)Widget; }
    };
}
