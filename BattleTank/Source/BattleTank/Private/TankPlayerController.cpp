// Free to Play. By SoNa Games.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* MyTank = nullptr;
	MyTank = Cast<ATank>(GetPawn());
	if (MyTank) { UE_LOG(LogTemp, Warning, TEXT("Found MyTank. Name is %s."), *MyTank->GetName()); }
	else { UE_LOG(LogTemp, Error, TEXT("Did not find MyTank. It is nullptr.")); }
	return MyTank;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	GetControlledTank();
}