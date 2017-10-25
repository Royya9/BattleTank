// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimingAtLocation(FVector AimLocation, float LaunchSpeed);

	void SetBarrelRef(UTankBarrel* BarrelToSet);

private:

	UTankBarrel* Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
	
};
