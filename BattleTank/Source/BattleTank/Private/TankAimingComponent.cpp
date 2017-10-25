// Free to Play. By SoNa Games.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimingAtLocation(FVector AimLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	// Calculate OutLaunchVelocity

	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, AimLocation, LaunchSpeed, false, 0.f, 0, ESuggestProjVelocityTraceOption::TraceFullPath, FCollisionResponseParams::DefaultResponseParam, TArray<AActor*>(), true))
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);

	}

}

void UTankAimingComponent::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;
	Barrel->Elevate(); 
}

