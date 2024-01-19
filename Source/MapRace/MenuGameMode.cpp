// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"
#include "MenuCharacter.h"
#include "MenuHUD.h"
#include "MenuPlayerController.h"


AMenuGameMode::AMenuGameMode()
{

    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMenuHUD::StaticClass();
}
