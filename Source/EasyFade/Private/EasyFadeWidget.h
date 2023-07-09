// Copyright 2023 Metaseven. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Images/SImage.h"
#include "EasyFadeTypes.h"

class SEasyFadeWidget : public SImage
{
public:
	SLATE_BEGIN_ARGS(SEasyFadeWidget)
	{
	}
	SLATE_ARGUMENT(FEasyFadeParams, FadeParams)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	void StartFade();

	FEasyFadeDelegate OnFadeFinished;

private:
	void FinishFade();
	void ApplyFade(const FLinearColor& NextColor);

	UWorld* GetWorld() const;
	bool IsGamePaused() const;
	void SetPrimaryVolume(const float Volume);

	FEasyFadeParams FadeParams;
	float TimeRemaining;
};
