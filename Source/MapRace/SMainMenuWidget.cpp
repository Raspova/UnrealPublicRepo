// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "MenuHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "MainMenu"

void SMainMenuWidget::Construct(const FArguments &InArgs)
{
    cVanSupportFocus = true;

    OwningHUD = InArgs._OwningHUD;

    const FMargin ContentPadding = FMargin(500.f, 300.f);
    const FMargin ButtonPadding = FMargin(10.f);

    const FText TitleText = LOCTEXT("GameTitle", "Title");
    const FText PlayText = LOCTEXT("PlayGame", "Play");
    const FText SettingsText = LOCTEXT("Settings", "Settings");
    const FText QuitText = LOCTEXT("QuitGame", "Quit");

    FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
    ButtonTextStyle.Size = 40.f;

    FSlateFontInfo TitleTextStyle = ButtonTextStyle;
    TitleTextStyle.Size = 60.f;

    ChildSlot
        [
            SNew(SOverlay)
            + SOverlay::Slot()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Fill)
            [
                SNew(SImage)
                .ColorAndOpacity(FColor::Black)
            ]
            + SOverlay::Slot()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Fill)
            .Padding(ContentPadding)
            [
                SNew(SVerticalBox)
                + SVerticalBox::Slot()
                [
                    SNew(STextBlock)
                    .Font(TitleTextStyle)
                    .Text(TitleText)
                    .Justification(ETextJustify::Center)
                ]

                + SVerticalBox::Slot()
                .Padding(ButtonPadding)
                [
                    SNew(SButton)
                    .OnClicked(this, &SMainMenuWidget::OnPLayClicked)
                    [
                        SNew(STextBlock)
                        .Font(ButtonTextStyle)
                        .Text(PlayText)
                        .Justification(ETextJustify::Center)
                    ]
                ]

                + SVerticalBox::Slot()
                .Padding(ButtonPadding)
                [
                    SNew(SButton)
                    [
                        SNew(STextBlock)
                        .Font(ButtonTextStyle)
                        .Text(SettingsText)
                        .Justification(ETextJustify::Center)
                    ]
                ]

                + SVerticalBox::Slot()
                .Padding(ButtonPadding)
                [
                    SNew(SButton)
                    .OnClicked(this, &SMainMenuWidget::OnQuitClicked)
                    [
                        SNew(STextBlock)
                        .Font(ButtonTextStyle)
                        .Text(QuitText)
                        .Justification(ETextJustify::Center)
                    ]
                ]
            ]
        ];
}

FReply SMainMenuWidget::OnQuitClicked() const
{
    // C'est ici qu'il faut appeller et lancer le truc du jeu


    return FReply::Handled();
}

FReply SMainMenuWidget::OnPLayClicked() const
{
    if (OwningHUD.IsValid()) {
        if (APlayerControlle* PC = OwningHUD-> PlayerOwner) {
            PC->ConsoleCommand("quit");
        }
    }

    return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE