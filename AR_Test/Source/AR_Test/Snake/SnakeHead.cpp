#include "SnakeHead.h"
#include "SnakeGameMode.h"

// Sets default values
ASnakeHead::ASnakeHead()
{
	// 언리얼에서 프레임마다 Tick을 돌려야 하는 액터는
	// PrimaryActorTick.bCanEverTick = true; 로 만들어줘야 Tick을 돌릴수가 있습니다.

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 생성자에서 보통 설정해주는게 일반적인데. 
	// 틱을 돌릴거냐 말거냐
	PrimaryActorTick.bCanEverTick = true;
	// PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;
	Tags.Add("Head");

}

// Called when the game starts or when spawned
void ASnakeHead::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASnakeHead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ASnakeHead::LeftAction()
{
	PrevPartPos = GetActorLocation();
	FVector MovePos = FVector::LeftVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector * 100.0f);

	if (nullptr != Next)
	{
		ASnakePart* CurNextPart = Next;

		while (nullptr != CurNextPart)
		{
			CurNextPart->PrevPartPos = CurNextPart->GetActorLocation();
			CurNextPart->AddActorLocalOffset(FVector::LeftVector * 100.0f);
			CurNextPart = CurNextPart->NextPart;
		}
	}


	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		ASnakePart* Body = Cast<ASnakePart>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Body"));
		if (Body)
		{
			ASnakePart* LastPart = ASnakePart::LastSnakePart();
			LastPart->SetActorLocation(PrevPartPos);
			LastPart->PrevPartPos = PrevPartPos;
			LastPart->NextPart = Body;
			Body->PrevPart = LastPart;
			// Body 파트를 추가한 후에 호출해야 하는 함수
			GetSnakeGameMode()->CurBodyReset();
		}
	}
}

void ASnakeHead::RightAction()
{
	PrevPartPos = GetActorLocation();
	FVector MovePos = FVector::RightVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector * 100.0f);

	if (nullptr != Next)
	{
		ASnakePart* CurNextPart = Next;

		while (nullptr != CurNextPart)
		{
			CurNextPart->PrevPartPos = CurNextPart->GetActorLocation();
			CurNextPart->AddActorLocalOffset(FVector::RightVector * 100.0f);
			CurNextPart = CurNextPart->NextPart;
		}
	}

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		ASnakePart* Body = Cast<ASnakePart>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Body"));
		if (Body)
		{
			ASnakePart* LastPart = ASnakePart::LastSnakePart();
			LastPart->SetActorLocation(PrevPartPos);
			LastPart->PrevPartPos = PrevPartPos;
			LastPart->NextPart = Body;
			Body->PrevPart = LastPart;
			// Body 파트를 추가한 후에 호출해야 하는 함수
			GetSnakeGameMode()->CurBodyReset();
		}
	}
}

void ASnakeHead::UpAction()
{
	PrevPartPos = GetActorLocation();
	FVector MovePos = FVector::UpVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(FVector::UpVector * 100.0f);

	if (nullptr != Next)
	{
		ASnakePart* CurNextPart = Next;

		while (nullptr != CurNextPart)
		{
			CurNextPart->PrevPartPos = CurNextPart->GetActorLocation();
			CurNextPart->AddActorLocalOffset(FVector::UpVector * 100.0f);
			CurNextPart = CurNextPart->NextPart;
		}
	}

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		ASnakePart* Body = Cast<ASnakePart>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Body"));
		if (Body)
		{
			ASnakePart* LastPart = ASnakePart::LastSnakePart();
			LastPart->SetActorLocation(PrevPartPos);
			LastPart->PrevPartPos = PrevPartPos;
			LastPart->NextPart = Body;
			Body->PrevPart = LastPart;
			// Body 파트를 추가한 후에 호출해야 하는 함수
			GetSnakeGameMode()->CurBodyReset();
		}
	}
}

void ASnakeHead::DownAction()
{
	PrevPartPos = GetActorLocation();
	FVector MovePos = FVector::DownVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(FVector::DownVector * 100.0f);

	if (nullptr != Next)
	{
		ASnakePart* CurNextPart = Next;

		while (nullptr != CurNextPart)
		{
			CurNextPart->PrevPartPos = CurNextPart->GetActorLocation();
			CurNextPart->AddActorLocalOffset(FVector::DownVector * 100.0f);
			CurNextPart = CurNextPart->NextPart;
		}
	}

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		ASnakePart* Body = Cast<ASnakePart>(GetSnakeGameMode()->GetPart(GetActorLocation(), "Body"));
		if (Body)
		{
			ASnakePart* LastPart = ASnakePart::LastSnakePart();
			LastPart->SetActorLocation(PrevPartPos);
			LastPart->PrevPartPos = PrevPartPos;
			LastPart->NextPart = Body;
			Body->PrevPart = LastPart;
			// Body 파트를 추가한 후에 호출해야 하는 함수
			GetSnakeGameMode()->CurBodyReset();
		}
	}
}
