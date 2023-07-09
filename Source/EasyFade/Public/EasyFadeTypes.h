// Copyright 2023 Metaseven. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EasyFadeTypes.generated.h"

DECLARE_DELEGATE(FEasyFadeDelegate);
DECLARE_DYNAMIC_DELEGATE(FEasyFadeDynamicDelegate);

USTRUCT(BlueprintType)
struct FEasyFadeParams
{
	GENERATED_BODY()

	/** How long the fade should take, in seconds. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EasyFade")
	float Time;

	/** Color to fade from. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EasyFade")
	FLinearColor FromColor;

	/** Color to fade to. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EasyFade")
	FLinearColor ToColor;

	/** Delegate executed when the fade is finished. */
	FEasyFadeDelegate OnFinished;

	/** Event called when the fade is finished. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "On Finished", Category = "EasyFade")
	FEasyFadeDynamicDelegate OnFinishedDynamic;

	/** True to fade audio volume along with the alpha of the color. */
	UPROPERTY(AdvancedDisplay, EditAnywhere, BlueprintReadWrite, Category = "EasyFade")
	bool bFadeAudio;

	/** True to continue to fade when the game is paused. */
	UPROPERTY(AdvancedDisplay, EditAnywhere, BlueprintReadWrite, Category = "EasyFade")
	bool bFadeWhenPaused;

	FEasyFadeParams()
		: Time(0.0f)
		, FromColor(FLinearColor::Transparent)
		, ToColor(FLinearColor::Transparent)
		, bFadeAudio(true)
		, bFadeWhenPaused(true)
	{
	}

	FEasyFadeParams(const float InTime, const FLinearColor& InFromColor, const FLinearColor& InToColor, const FEasyFadeDelegate& InOnFinished, const bool bInFadeAudio, const bool bInFadeWhenPaused)
		: Time(InTime)
		, FromColor(InFromColor)
		, ToColor(InToColor)
		, OnFinished(InOnFinished)
		, bFadeAudio(bInFadeAudio)
		, bFadeWhenPaused(bInFadeWhenPaused)
	{
	}

	FEasyFadeParams(const float InTime, const FLinearColor& InFromColor, const FLinearColor& InToColor, const FEasyFadeDynamicDelegate& InOnFinished, const bool bInFadeAudio, const bool bInFadeWhenPaused)
		: Time(InTime)
		, FromColor(InFromColor)
		, ToColor(InToColor)
		, OnFinishedDynamic(InOnFinished)
		, bFadeAudio(bInFadeAudio)
		, bFadeWhenPaused(bInFadeWhenPaused)
	{
	}
};
