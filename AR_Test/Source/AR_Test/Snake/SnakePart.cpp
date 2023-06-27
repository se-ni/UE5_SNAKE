// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakePart.h"
#include "Kismet/GameplayStatics.h"
#include "SnakeGameMode.h"
#include "SnakePawn.h"

// Sets default values
ASnakePart::ASnakePart()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("SnakePart");
}

// Called when the game starts or when spawned
void ASnakePart::BeginPlay()
{
	Super::BeginPlay();

	AGameModeBase* GameModePtr = UGameplayStatics::GetGameMode(GetWorld());
	if (nullptr == GameModePtr)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == GameMode)"), __FUNCTION__, __LINE__);
		return;
	}

	// 내가 여기 인자로 들어가 있는 액터보다 나중에 Tick을 돌릴께.
	// 나는 벽인데 GameModePtr보다 나중에 tick을 돌릴께.
	AddTickPrerequisiteActor(GameModePtr);
}

// Called every frame
void ASnakePart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PrevPart)
	{
		// 헤드의 위치를 따라다니도록 Body 파트를 이동시킴
		SetActorLocation(PrevPart->PrevPartPos);

		if (PrevPart->PrevPart)
		{
			// 두 번째로 생성된 Body인 경우 PrevPart의 PrevPartPos를 현재 위치로 설정하여 첫 번째 Body와 연결
			PrevPart->PrevPartPos = GetActorLocation();
		}
	}
}



ASnakeGameMode* ASnakePart::GetSnakeGameMode()
{
	AGameModeBase* GameModePtr = UGameplayStatics::GetGameMode(GetWorld());
	if (nullptr == GameModePtr)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == GameMode)"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	if (false == GameModePtr->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == GameMode)"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	ASnakeGameMode* SnakeGameMode = Cast<ASnakeGameMode>(GameModePtr);

	if (nullptr == SnakeGameMode && false == SnakeGameMode->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == SnakeGameMode && false == SnakeGameMode->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return SnakeGameMode;
}

ASnakePart* ASnakePart::LastSnakePart()
{
	ASnakePart* LastPart = this;

	while (LastPart->PrevPart != nullptr)
	{
		LastPart = LastPart->PrevPart;
	}

	return LastPart;
}