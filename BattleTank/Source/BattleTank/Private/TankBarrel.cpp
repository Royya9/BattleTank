// Free to Play. By SoNa Games.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
// 	float Time = GetWorld()->GetTimeSeconds();
// 	UE_LOG(LogTemp, Warning, TEXT("%f : Barrel Aiming at Degrees : %f"), Time, RelativeSpeed);

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed*DegreesPerSecond*(GetWorld()->DeltaTimeSeconds);
	
	auto RawElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp(RawElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

