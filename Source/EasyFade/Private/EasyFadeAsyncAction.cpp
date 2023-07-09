// Copyright 2023 Metaseven. All Rights Reserved.

#include "EasyFadeAsyncAction.h"
#include "EasyFadeFunctionLibrary.h"

void UEasyFadeAsyncAction::Activate()
{
	UEasyFadeFunctionLibrary::Fade(WorldContextObject.Get(), FadeParams, OwningPlayer.Get(), ZOrder);
}

UEasyFadeAsyncAction* UEasyFadeAsyncAction::AsyncFade(UObject* WorldContextObject, const FEasyFadeParams& FadeParams, APlayerController* OwningPlayer, const int32 ZOrder)
{
	UEasyFadeAsyncAction* AsyncAction = NewObject<UEasyFadeAsyncAction>();

	AsyncAction->RegisterWithGameInstance(WorldContextObject);
	AsyncAction->WorldContextObject = WorldContextObject;
	AsyncAction->FadeParams = FadeParams;
	AsyncAction->FadeParams.OnFinished.BindUObject(AsyncAction, &UEasyFadeAsyncAction::OnFadeFinished);
	AsyncAction->OwningPlayer = OwningPlayer;
	AsyncAction->ZOrder = ZOrder;

	return AsyncAction;
}

UEasyFadeAsyncAction* UEasyFadeAsyncAction::AsyncFadeIn(UObject* WorldContextObject, const float Time, const FLinearColor FromColor, const bool bFadeAudio, const bool bFadeWhenPaused, APlayerController* OwningPlayer, const int32 ZOrder)
{
	const FEasyFadeParams FadeParams(Time, FromColor, FLinearColor::Transparent, FEasyFadeDelegate(), bFadeAudio, bFadeWhenPaused);
	return AsyncFade(WorldContextObject, FadeParams, OwningPlayer, ZOrder);
}

UEasyFadeAsyncAction* UEasyFadeAsyncAction::AsyncFadeOut(UObject* WorldContextObject, const float Time, const FLinearColor ToColor, const bool bFadeAudio, const bool bFadeWhenPaused, APlayerController* OwningPlayer, const int32 ZOrder)
{
	const FEasyFadeParams FadeParams(Time, FLinearColor::Transparent, ToColor, FEasyFadeDelegate(), bFadeAudio, bFadeWhenPaused);
	return AsyncFade(WorldContextObject, FadeParams, OwningPlayer, ZOrder);
}

void UEasyFadeAsyncAction::OnFadeFinished()
{
	Finished.Broadcast();
	SetReadyToDestroy();
}
