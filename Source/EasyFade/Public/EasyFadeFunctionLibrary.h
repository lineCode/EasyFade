// Copyright 2023 Metaseven. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EasyFadeTypes.h"
#include "EasyFadeFunctionLibrary.generated.h"

UCLASS()
class EASYFADE_API UEasyFadeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Does a fade to/from a color.
	 * @param FadeParams - Parameters to set fade.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "EasyFade", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = 2))
	static void Fade(
		const UObject* WorldContextObject,
		const FEasyFadeParams& FadeParams,
		const APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);

	/**
	 * Does a fade from a color to transparent.
	 * @param Time - How long the fade should take, in seconds.
	 * @param FromColor - Color to fade from.
	 * @param OnFinished - Delegate executed when the fade is finished.
	 * @param bFadeAudio - True to fade audio volume along with the alpha of the color.
	 * @param bFadeWhenPaused - True to continue to fade when the game is paused.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	static void FadeIn(
		const UObject* WorldContextObject,
		const float Time = 1.0f,
		const FLinearColor& FromColor = FLinearColor::Black,
		const FEasyFadeDelegate& OnFinished = FEasyFadeDelegate(),
		const bool bFadeAudio = true,
		const bool bFadeWhenPaused = true,
		const APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);

	/**
	 * Does a fade from transparent to a color.
	 * @param Time - How long the fade should take, in seconds.
	 * @param ToColor - Color to fade to.
	 * @param OnFinished - Delegate executed when the fade is finished.
	 * @param bFadeAudio - True to fade audio volume along with the alpha of the color.
	 * @param bFadeWhenPaused - True to continue to fade when the game is paused.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	static void FadeOut(
		const UObject* WorldContextObject,
		const float Time = 1.0f,
		const FLinearColor& ToColor = FLinearColor::Black,
		const FEasyFadeDelegate& OnFinished = FEasyFadeDelegate(),
		const bool bFadeAudio = true,
		const bool bFadeWhenPaused = true,
		const APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);

private:
	/**
	 * Does a fade from a color to transparent.
	 * @param Time - How long the fade should take, in seconds.
	 * @param FromColor - Color to fade from.
	 * @param OnFinished - Event called when the fade is finished.
	 * @param bFadeAudio - True to fade audio volume along with the alpha of the color.
	 * @param bFadeWhenPaused - True to continue to fade when the game is paused.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "EasyFade", meta = (DisplayName = "Fade In", WorldContext = "WorldContextObject", Time = "1.0", FromColor = "(R=0.0,G=0.0,B=0.0,A=1.0)", AutoCreateRefTerm = "OnFinished", AdvancedDisplay = 4))
	static void K2_FadeIn(
		const UObject* WorldContextObject,
		const float Time,
		const FLinearColor FromColor,
		const FEasyFadeDynamicDelegate& OnFinished,
		const bool bFadeAudio = true,
		const bool bFadeWhenPaused = true,
		const APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);

	/**
	 * Does a fade from transparent to a color.
	 * @param Time - How long the fade should take, in seconds.
	 * @param ToColor - Color to fade to.
	 * @param OnFinished - Event called when the fade is finished.
	 * @param bFadeAudio - True to fade audio volume along with the alpha of the color.
	 * @param bFadeWhenPaused - True to continue to fade when the game is paused.
	 * @param OwningPlayer - The player to add the fade widget to.
	 * @param ZOrder - The Z-order index for this fade widget. Larger values will cause the widget to appear on top of widgets with lower values.
	 */
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "EasyFade", meta = (DisplayName = "Fade Out", WorldContext = "WorldContextObject", Time = "1.0", ToColor = "(R=0.0,G=0.0,B=0.0,A=1.0)", AutoCreateRefTerm = "OnFinished", AdvancedDisplay = 4))
	static void K2_FadeOut(
		const UObject* WorldContextObject,
		const float Time,
		const FLinearColor ToColor,
		const FEasyFadeDynamicDelegate& OnFinished,
		const bool bFadeAudio = true,
		const bool bFadeWhenPaused = true,
		const APlayerController* OwningPlayer = nullptr,
		const int32 ZOrder = 100);
};
