// Free to Play. By SoNa Games.

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::AimingAtLocation(FVector AimLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	// Calculate OutLaunchVelocity
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, AimLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace, FCollisionResponseParams::DefaultResponseParam, TArray<AActor*>(), false);

	if (bHaveAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	//	RotateTurret(AimDirection);
	}
	if (!bHaveAimSolution)
	{
		//float Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT(" Barrel is not Aiming"));
	}

}

void UTankAimingComponent::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { UE_LOG(LogTemp, Error, TEXT("Barrel to Set is null ptr in TankAimingComponent.cpp")); return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretRef(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { UE_LOG(LogTemp, Error, TEXT("Turret to Set is null ptr in TankAimingComponent.cpp")); return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{

	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;
	Barrel->Elevate(DeltaRotation.Pitch); 
	Turret->Rotate(DeltaRotation.Yaw);
//	float Time = GetWorld()->GetTimeSeconds();
//	UE_LOG(LogTemp, Warning, TEXT("%f : Aim Direction : %f"), Time, DeltaRotation.Pitch);
}



