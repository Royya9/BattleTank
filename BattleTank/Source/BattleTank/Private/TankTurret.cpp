// Free to Play. By SoNa Games.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed*DegreesPerSecond*(GetWorld()->DeltaTimeSeconds);

	auto Rotation = RelativeRotation.Yaw + RotationChange;

	
	SetRelativeRotation(FRotator(0, Rotation, 0));
}


