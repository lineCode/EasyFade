// Copyright 2023 Metaseven. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EasyFadeSubsystem.generated.h"

class SWidget;
class UGameViewportClient;
struct FEasyFadeParams;

UCLASS()
class UEasyFadeSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void AddFadeWidget(const FEasyFadeParams& InFadeParams, const APlayerController* OwningPlayer = nullptr, const int32 ZOrder = 100);

private:
	void RemoveFadeWidget(const APlayerController* OwningPlayer, const int32 ControllerID);
	void RemoveFadeWidget(const int32 ControllerID);

	UGameViewportClient* GetGameViewport() const;
	int32 GetPlayerControllerID(const APlayerController* PlayerController) const;
	APlayerController* GetPlayerControllerFromID(const int32 ControllerID) const;

	TMap<int32, TWeakPtr<SWidget>> FadeWidgetsForID;
};
