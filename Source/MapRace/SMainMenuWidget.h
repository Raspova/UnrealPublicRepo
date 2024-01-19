// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class MAPRACE_API SMainMenuWidget
{
public:

	SLATE_BEGIN_ARGS(SMainMenuWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply OnPLayClicked() const;
	FReply OnQuitClicked() const;

	TWeakObjectPtr<class AmenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };

};
