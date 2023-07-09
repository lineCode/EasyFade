// Copyright 2023 Metaseven. All Rights Reserved.

#include "EasyFadeFunctionLibrary.h"
#include "EasyFadeSubsystem.h"
#include "Engine/Engine.h"

void UEasyFadeFunctionLibrary::Fade(const UObject* WorldContextObject, const FEasyFadeParams& FadeParams, const APlayerController* OwningPlayer, const int32 ZOrder)
{
	if (GEngine)
	{
		if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UEasyFadeSubsystem* Subsystem = World->GetGameInstance()->GetSubsystem<UEasyFadeSubsystem>();
			Subsystem->AddFadeWidget(FadeParams, OwningPlayer, ZOrder);
		}
	}
}

void UEasyFadeFunctionLibrary::FadeIn(const UObject* WorldContextObject, const float Time, const FLinearColor& FromColor, const FEasyFadeDelegate& OnFinished, const bool bFadeAudio, const bool bFadeWhenPaused, const APlayerController* OwningPlayer, const int32 ZOrder)
{
	const FEasyFadeParams FadeParams(Time, FromColor, FLinearColor::Transparent, OnFinished, bFadeAudio, bFadeWhenPaused);
	Fade(WorldContextObject, FadeParams, OwningPlayer, ZOrder);
}

void UEasyFadeFunctionLibrary::FadeOut(const UObject* WorldContextObject, const float Time, const FLinearColor& ToColor, const FEasyFadeDelegate& OnFinished, const bool bFadeAudio, const bool bFadeWhenPaused, const APlayerController* OwningPlayer, const int32 ZOrder)
{
	const FEasyFadeParams FadeParams(Time, FLinearColor::Transparent, ToColor, OnFinished, bFadeAudio, bFadeWhenPaused);
	Fade(WorldContextObject, FadeParams, OwningPlayer, ZOrder);
}

void UEasyFadeFunctionLibrary::K2_FadeIn(const UObject* WorldContextObject, const float Time, const FLinearColor FromColor, const FEasyFadeDynamicDelegate& OnFinished, const bool bFadeAudio, const bool bFadeWhenPaused, const APlayerController* OwningPlayer, const int32 ZOrder)
{
	const FEasyFadeParams FadeParams(Time, FromColor, FLinearColor::Transparent, OnFinished, bFadeAudio, bFadeWhenPaused);
	Fade(WorldContextObject, FadeParams, OwningPlayer, ZOrder);
}

void UEasyFadeFunctionLibrary::K2_FadeOut(const UObject* WorldContextObject, const float Time, const FLinearColor ToColor, const FEasyFadeDynamicDelegate& OnFinished, const bool bFadeAudio, const bool bFadeWhenPaused, const APlayerController* OwningPlayer, const int32 ZOrder)
{
	const FEasyFadeParams FadeParams(Time, FLinearColor::Transparent, ToColor, OnFinished, bFadeAudio, bFadeWhenPaused);
	Fade(WorldContextObject, FadeParams, OwningPlayer, ZOrder);
}
