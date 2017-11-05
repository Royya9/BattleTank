// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class UTankAimingComponent;

/**
 *  Responsible for controlling the Tank
 */

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector &OutLocation) const;

	bool GetLookDirection(FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector &HitLocation, FVector LookDirection) const;

	UTankAimingComponent* AimingComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationX = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationY = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float TankRange = 100000;

};
