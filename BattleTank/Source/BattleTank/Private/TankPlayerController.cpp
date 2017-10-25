// Free to Play. By SoNa Games.

#include "TankPlayerController.h"
#include "Engine/World.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	GetControlledTank();
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrossHair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* MyTank = nullptr;
	MyTank = Cast<ATank>(GetPawn());
	if (!MyTank) 
	{
		UE_LOG(LogTemp, Error, TEXT("Did not find MyTank. It is nullptr."));
	}
	return MyTank;
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) //we hit something in the world.
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

// Gets HitLocation by line trace through cross hair. Returns true if valid trace hit.
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutLocation) const
{
	FVector LookDirection;
	if (GetLookDirection(LookDirection))
	{
		if (GetLookVectorHitLocation(OutLocation, LookDirection))
		{
			return true;
		}
	}
	return false;
}

//get cross hair location on the screen and De-project the cross hair location to get the direction in which we are looking
bool ATankPlayerController::GetLookDirection(FVector &LookDirection) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairLocationX, ViewportSizeY*CrossHairLocationY);
	FVector CameraWorldLocation; //This is being discarded but you can this as StartTrace in lieu of PlayerCameraManager->GetCameraLocation() in GetLookVectorHitLocation() function
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector &HitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	FCollisionQueryParams CQP;
//	CQP.AddIgnoredActor(this->GetPawn());
	FVector StartTrace = PlayerCameraManager->GetCameraLocation();
	FVector EndTrace = LookDirection*TankRange + StartTrace;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, CQP))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		return false;
	}
}