#include "MyGameState.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "CoinItem.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"

AMyGameState::AMyGameState()
	: Score(0)
	, SpawnedCoinCount(0)
	, CollectedCoinCount(0)
	, CurrentLevelIndex(0)
	, MaxLevels(3)
	, CurrentWaveIndex(0)
	, MaxWaves(3)
	, WaveDuration(20.f)
	, ItemsToSpawnPerWave({ 20, 30, 40 })
	, SpikeTrapClass(nullptr)
{
}

void AMyGameState::BeginPlay()
{
	Super::BeginPlay();

	StartLevel();

	GetWorldTimerManager().SetTimer(
		HUDUpdateTimerHandle,
		this,
		&ThisClass::UpdateHUD,
		0.1f,
		true
	);
}

int32 AMyGameState::GetScore() const
{
	return Score;
}

void AMyGameState::AddScore(int32 Amount)
{
	if (UMyGameInstance* MyGameInstance = GetMyGameInstance())
	{
		MyGameInstance->AddToScore(Amount);
	}
}

void AMyGameState::StartLevel()
{
	if (AMyPlayerController* MyPlayerController = GetMyPlayerController())
	{
		MyPlayerController->ShowGameHUD();
	}

	if (UMyGameInstance* MyGameInstance = GetMyGameInstance())
	{
		CurrentLevelIndex = MyGameInstance->CurrentLevelIndex;
	}

	CurrentWaveIndex = 0;
	StartWave();
}

void AMyGameState::StartWave()
{
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	for (AActor* Item : CurrentWaveItems)
	{
		if (Item && Item->IsValidLowLevelFast())
		{
			Item->Destroy();
		}
	}

	CurrentWaveItems.Empty();

	int32 ItemToSpawn = (ItemsToSpawnPerWave.IsValidIndex(CurrentWaveIndex)) ? ItemsToSpawnPerWave[CurrentWaveIndex] : 20;

	if (ASpawnVolume* SpawnVolume = GetSpawnVolume())
	{
		for (int32 i = 0; i < ItemToSpawn; i++)
		{
			if (AActor* SpawnedActor = SpawnVolume->SpawnRandomItem())
			{
				if (SpawnedActor->IsA(ACoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
				}

				CurrentWaveItems.Add(SpawnedActor);
			}
		}
	}

	if (CurrentWaveIndex == 1)
	{
		EnableWave2();
	}
	else if (CurrentWaveIndex == 2)
	{
		EnableWave3();
	}

	if (AMyPlayerController* MyPlayerController = GetMyPlayerController())
	{
		if (UUserWidget* HUDWidget = MyPlayerController->GetHUDWidget())
		{
			UFunction* PlayAnimFunc = HUDWidget->FindFunction(FName("PlayShowWaveNotifyAnim"));

			if (PlayAnimFunc)
			{
				HUDWidget->ProcessEvent(PlayAnimFunc, nullptr);
			}

			if (UTextBlock* WaveNotifyText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName("WaveNotifyText")))
			{
				WaveNotifyText->SetText(FText::FromString(
					FString::Printf(TEXT("Wave %d ¹ß»ý!"), CurrentWaveIndex + 1)));
			}
		}
	}

	GetWorldTimerManager().SetTimer(
		WaveTimerHandle,
		this,
		&ThisClass::OnWaveTimeUp,
		WaveDuration,
		false
	);
}

void AMyGameState::OnWaveTimeUp()
{
	EndWave();
}

void AMyGameState::EndWave()
{
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);

	++CurrentWaveIndex;
	if (CurrentWaveIndex >= MaxWaves)
	{
		EndLevel();
	}
	else
	{
		StartWave();
	}
}

void AMyGameState::OnCoinCollected()
{
	CollectedCoinCount++;
	UE_LOG(LogTemp, Warning, TEXT("Coin Collected: %d / %d"), CollectedCoinCount, SpawnedCoinCount);

	if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
	{
		EndWave();
	}
}

void AMyGameState::EndLevel()
{
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);

	if (UMyGameInstance* MyGameInstance = GetMyGameInstance())
	{
		AddScore(Score);
		CurrentLevelIndex++;
		MyGameInstance->CurrentLevelIndex = CurrentLevelIndex;

		if (CurrentLevelIndex >= MaxLevels)
		{
			OnGameOver();
			return;
		}

		if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
		{
			UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
		}
		else
		{
			OnGameOver();
		}
	}
}

void AMyGameState::OnGameOver()
{
	if (AMyPlayerController* MyPlayerController = GetMyPlayerController())
	{
		MyPlayerController->SetPause(true);
		MyPlayerController->ShowMainMenu(true);
	}
}

void AMyGameState::UpdateHUD()
{
	if (AMyPlayerController* MyPlayerController = GetMyPlayerController())
	{
		if (UUserWidget* HUDWidget = MyPlayerController->GetHUDWidget())
		{
			if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Time"))))
			{
				float RemainingTime = GetWorldTimerManager().GetTimerRemaining(WaveTimerHandle);
				TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: %.1f"), RemainingTime)));
			}

			if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score"))))
			{
				if (UMyGameInstance* MyGameInstance = GetMyGameInstance())
				{
					ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), MyGameInstance->TotalScore)));
				}
			}

			if (UTextBlock* LevelText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level"))))
			{
				LevelText->SetText(FText::FromString(FString::Printf(TEXT("Level: %d"), CurrentLevelIndex + 1)));
			}

			if (UTextBlock* WaveText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Wave"))))
			{
				WaveText->SetText(FText::FromString(FString::Printf(TEXT("Wave: %d / %d"), CurrentWaveIndex + 1, MaxWaves)));
			}
		}
	}
}

void AMyGameState::EnableWave2()
{
	const FString Msg = TEXT("Wave 2");
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Msg);
	}

}

void AMyGameState::EnableWave3()
{
	const FString Msg = TEXT("Wave 3");
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Msg);
	}
}


ASpawnVolume* AMyGameState::GetSpawnVolume() const
{
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);
	return (FoundVolumes.Num() > 0) ? Cast<ASpawnVolume>(FoundVolumes[0]) : nullptr;
}

AMyPlayerController* AMyGameState::GetMyPlayerController() const
{
	return Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

UMyGameInstance* AMyGameState::GetMyGameInstance() const
{
	return Cast<UMyGameInstance>(GetGameInstance());
}
