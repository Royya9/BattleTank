// Free to Play. By SoNa Games.

#include "TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	ATank* MyTank = nullptr;
	MyTank = Cast<ATank>(GetPawn());
	if (MyTank) { UE_LOG(LogTemp, Warning, TEXT("AI Tank: %s reporting for duty"), *MyTank->GetName()); }
	else { UE_LOG(LogTemp, Error, TEXT("My Tank in TankAIController is null ptr.")); }
	return MyTank;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetControlledTank();
	GetPlayerTank();
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = nullptr;

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) { UE_LOG(LogTemp, Warning, TEXT("From TankAIController: Found PlayerController. Its possessed Tank name is: %s"), *PlayerTank->GetName()); }
	else { UE_LOG(LogTemp, Error, TEXT("Player Tank in TankAIController is nullptr.")); }
	return PlayerTank;
}