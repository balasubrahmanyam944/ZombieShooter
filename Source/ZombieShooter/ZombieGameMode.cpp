// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieGameMode.h"
#include "Kismet/GameplayStatics.h"

void AZombieGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountDownTimerHandle, this,
		&AZombieGameMode::CountdownTimer, 1.0f, true, 1.0f);
}

void AZombieGameMode::RestartGameplay(bool Won)
{
	if (Won)
	{
		ResetLevel();
	}
	else
	{
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this,
			&AZombieGameMode::ResetLevel, 6.0f);
	}
}

void AZombieGameMode::ResetLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Demo_Streets");
}

void AZombieGameMode::CountdownTimer()
{
	TimerCount--;

	if (TimerCount == 0)
	{
		GetWorldTimerManager().ClearTimer(CountDownTimerHandle);
		ResetLevel();
	}
}

