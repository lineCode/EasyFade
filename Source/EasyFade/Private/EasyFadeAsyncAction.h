// Copyright 2023 Metaseven. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "EasyFadeTypes.h"
#include "EasyFadeAsyncAction.generated.h"

UCLASS()
class UEasyFadeAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	void Activate() override;

private:
	/**
	 * Does a fade to/from a color.
	 * @param FadeParams - Parameters to set fade.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "EasyFade", meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", AdvancedDisplay = 2))
	static UEasyFadeAsyncAction* AsyncFade(
		UObject* WorldContextObject,
		const FEasyFadeParams& FadeParams,
		APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);

	/**
	 * Does a fade from a color to transparent.
	 * @param Time - How long the fade should take, in seconds.
	 * @param FromColor - Color to fade from.
	 * @param bFadeAudio - True to fade audio volume along with the alpha of the color.
	 * @param bFadeWhenPaused - True to continue to fade when the game is paused.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "EasyFade", meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", AdvancedDisplay = 3))
	static UEasyFadeAsyncAction* AsyncFadeIn(
		UObject* WorldContextObject,
		const float Time = 1.0f,
		const FLinearColor FromColor = FLinearColor::Black,
		const bool bFadeAudio = true,
		const bool bFadeWhenPaused = true,
		APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);

	/**
	 * Does a fade from transparent to a color.
	 * @param Time - How long the fade should take, in seconds.
	 * @param ToColor - Color to fade to.
	 * @param bFadeAudio - True to fade audio volume along with the alpha of the color.
	 * @param bFadeWhenPaused - True to continue to fade when the game is paused.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "EasyFade", meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", AdvancedDisplay = 3))
	static UEasyFadeAsyncAction* AsyncFadeOut(
		UObject* WorldContextObject,
		const float Time = 1.0f,
		const FLinearColor ToColor = FLinearColor::Black,
		const bool bFadeAudio = true,
		const bool bFadeWhenPaused = true,
		APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);

	void OnFadeFinished();

	TWeakObjectPtr<UObject> WorldContextObject;
	FEasyFadeParams FadeParams;
	TWeakObjectPtr<APlayerController> OwningPlayer;
	int32 ZOrder;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFinishedDelegate);

	/** Called when the fade is finished. */
	UPROPERTY(BlueprintAssignable)
	FFinishedDelegate Finished;
};
