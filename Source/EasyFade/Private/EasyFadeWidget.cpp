// Copyright 2023 Metaseven. All Rights Reserved.

#include "EasyFadeWidget.h"
#include "AudioDevice.h"
#include "Launch/Resources/Version.h"

void SEasyFadeWidget::Construct(const FArguments& InArgs)
{
	FadeParams = InArgs._FadeParams;
}

void SEasyFadeWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	if (!FadeParams.bFadeWhenPaused && IsGamePaused())
	{
		return;
	}

	TimeRemaining = FMath::Max(TimeRemaining - InDeltaTime, 0.0f);

	if (TimeRemaining == 0.0f)
	{
		FinishFade();
		return;
	}

	const FLinearColor NextColor = FadeParams.ToColor - (FadeParams.ToColor - FadeParams.FromColor) * TimeRemaining / FadeParams.Time;
	ApplyFade(NextColor);
}

void SEasyFadeWidget::StartFade()
{
	SetImage(FCoreStyle::Get().GetBrush("WhiteBrush"));

	if (FadeParams.Time <= 0.0f)
	{
		FinishFade();
		return;
	}

	TimeRemaining = FadeParams.Time;
	ApplyFade(FadeParams.FromColor);

	SetCanTick(true);
}

void SEasyFadeWidget::FinishFade()
{
	ApplyFade(FadeParams.ToColor);

	OnFadeFinished.ExecuteIfBound();
	FadeParams.OnFinished.ExecuteIfBound();
	FadeParams.OnFinishedDynamic.ExecuteIfBound();

	SetCanTick(false);
}

void SEasyFadeWidget::ApplyFade(const FLinearColor& NextColor)
{
	SetColorAndOpacity(NextColor);

	if (FadeParams.bFadeAudio)
	{
		SetPrimaryVolume(1.0f - NextColor.A);
	}
}

UWorld* SEasyFadeWidget::GetWorld() const
{
	if (GEngine)
	{
		if (const UGameViewportClient* GameViewport = GEngine->GameViewport)
		{
			return GameViewport->GetWorld();
		}
	}

	return nullptr;
}

bool SEasyFadeWidget::IsGamePaused() const
{
	if (const UWorld* World = GetWorld())
	{
		return World->IsPaused();
	}

	return false;
}

void SEasyFadeWidget::SetPrimaryVolume(const float Volume)
{
	if (UWorld* World = GetWorld())
	{
		if (FAudioDevice* AudioDevice = World->GetAudioDeviceRaw())
		{
#if ENGINE_MAJOR_VERSION < 5 || ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION < 1
			AudioDevice->SetTransientMasterVolume(Volume);
#else
			AudioDevice->SetTransientPrimaryVolume(Volume);
#endif
		}
	}
}
