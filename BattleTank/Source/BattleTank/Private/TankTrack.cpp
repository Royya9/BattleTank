// Free to Play. By SoNa Games.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Throttling at rate: %f"), *GetName(), Throttle);

	auto ForceApplied = GetForwardVector()*TrackMaxDrivingForce*Throttle;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


