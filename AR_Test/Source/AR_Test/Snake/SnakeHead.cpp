#include "SnakeHead.h"
#include "SnakeGameMode.h"

// Sets default values
ASnakeHead::ASnakeHead()
{
	// �𸮾󿡼� �����Ӹ��� Tick�� ������ �ϴ� ���ʹ�
	// PrimaryActorTick.bCanEverTick = true; �� �������� Tick�� �������� �ֽ��ϴ�.

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// �����ڿ��� ���� �������ִ°� �Ϲ����ε�. 
	// ƽ�� �����ų� ���ų�
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


	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
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
			// Body ��Ʈ�� �߰��� �Ŀ� ȣ���ؾ� �ϴ� �Լ�
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

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
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
			// Body ��Ʈ�� �߰��� �Ŀ� ȣ���ؾ� �ϴ� �Լ�
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

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
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
			// Body ��Ʈ�� �߰��� �Ŀ� ȣ���ؾ� �ϴ� �Լ�
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

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
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
			// Body ��Ʈ�� �߰��� �Ŀ� ȣ���ؾ� �ϴ� �Լ�
			GetSnakeGameMode()->CurBodyReset();
		}
	}
}
