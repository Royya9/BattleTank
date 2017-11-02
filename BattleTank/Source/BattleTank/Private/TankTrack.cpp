// Free to Play. By SoNa Games.

#include "TankTrack.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float Throttle)
{


	auto ForceApplied = GetForwardVector()*TrackMaxDrivingForce*Throttle;
	auto ForceLocation = GetComponentLocation();
// 	auto NewForceLocation = ForceLocation;
// 	NewForceLocation.X = ForceLocation.X + GetForwardVector().X + 200.f;
// 	

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

// 	DrawDebugLine(GetWorld(), NewForceLocation, ForceLocation, FColor::Red);
// 	UE_LOG(LogTemp, Warning, TEXT("Force Loc: %s New Force Loc: %s"), *ForceLocation.ToString(),*NewForceLocation.ToString());
}


