// Free to Play. By SoNa Games.

#include "TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	ATank* MyTank = nullptr;
	MyTank = Cast<ATank>(GetPawn());
	if (MyTank) { return MyTank; }
	else { UE_LOG(LogTemp, Error, TEXT("My Tank in TankAIController is null ptr.")); }
	return MyTank;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetControlledTank();
	GetPlayerTank();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		//TODO move towards the player

		AimTowardsPlayer();

		//TODO Fire when ready
	}
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = nullptr;

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) { return PlayerTank; }
	else { UE_LOG(LogTemp, Error, TEXT("Player Tank in TankAIController is nullptr.")); }
	return PlayerTank;
}

void ATankAIController::AimTowardsPlayer()
{
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}