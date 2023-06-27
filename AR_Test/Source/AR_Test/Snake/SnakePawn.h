// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SnakePawn.generated.h"

UCLASS()
class AR_TEST_API ASnakePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakePawn();

	UFUNCTION(BlueprintCallable)
		FORCEINLINE void SetHead(AActor* _Head)
	{
		Head = _Head;
	}
	FORCEINLINE AActor* GetHead() const
	{
		return Head;
	}
	UFUNCTION(BlueprintCallable)
		void HeadPositionToCenter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// �̳༮�� �ƿ� �������Ʈ���� �����ְ� ����� ���.
	AActor* Head;

};
