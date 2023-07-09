# Easy Fade

[Easy Fade in Code Plugins - UE Marketplace](https://www.unrealengine.com/marketplace/en-US/product/easy-fade)

## Blueprint

![EasyFade_Nodes](https://github.com/suramaru517/EasyFade/assets/50897830/d00c3c96-6385-4e87-984b-5137de75caf0)

### Example:

![EasyFade_Example](https://github.com/suramaru517/EasyFade/assets/50897830/229d546e-5c14-4f5e-a33a-c20c71850801)

## C++

### EasyFadeFunctionLibrary.h

```cpp
static void Fade(
	const UObject* WorldContextObject,
	const FEasyFadeParams& FadeParams,
	const APlayerController* OwningPlayer = nullptr,
	const int32 ZOrder = 100);

static void FadeIn(
	const UObject* WorldContextObject,
	const float Time = 1.0f,
	const FLinearColor& FromColor = FLinearColor::Black,
	const FEasyFadeDelegate& OnFinished = FEasyFadeDelegate(),
	const bool bFadeAudio = true,
	const bool bFadeWhenPaused = true,
	const APlayerController* OwningPlayer = nullptr,
	const int32 ZOrder = 100);

static void FadeOut(
	const UObject* WorldContextObject,
	const float Time = 1.0f,
	const FLinearColor& ToColor = FLinearColor::Black,
	const FEasyFadeDelegate& OnFinished = FEasyFadeDelegate(),
	const bool bFadeAudio = true,
	const bool bFadeWhenPaused = true,
	const APlayerController* OwningPlayer = nullptr,
	const int32 ZOrder = 100);
```

### Example:

```cpp
#include "MyActor.h"
#include "EasyFadeFunctionLibrary.h"

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UEasyFadeFunctionLibrary::FadeIn(this, 1.0f, FLinearColor::Black, FEasyFadeDelegate::CreateUObject(this, &AMyActor::OnFadeInFinished));
}

void AMyActor::OnFadeInFinished()
{
	UE_LOG(LogTemp, Log, TEXT("Fade in finished"));

	UEasyFadeFunctionLibrary::FadeOut(this, 1.0f, FLinearColor::Black, FEasyFadeDelegate::CreateLambda([]()
		{
			UE_LOG(LogTemp, Log, TEXT("Fade out finished"));
		}
	));
}
```
