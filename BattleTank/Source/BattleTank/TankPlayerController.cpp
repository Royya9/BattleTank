// Free to Play. By SoNa Games.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

