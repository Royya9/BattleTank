// Free to Play. By SoNa Games.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ATank* MyTank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());


	if (MyTank && PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		MyTank->AimAt(PlayerTank->GetActorLocation());
	//	MyTank->Fire();
	}
}
