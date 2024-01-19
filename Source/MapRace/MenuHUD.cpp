// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "SMainMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AMenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (GEngine && GEngine->GameViewPort) {
        MenuWidget = SNew(SMainMenuWidget).OwningHUD(this);
        GEngine->GameViewPort->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
    }
}
