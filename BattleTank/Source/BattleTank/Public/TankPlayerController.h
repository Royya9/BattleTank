// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:

	ATank* GetControlledTank() const;

	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector &OutLocation) const;

	bool GetLookDirection(FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector &HitLocation, FVector LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairLocationX = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairLocationY = 0.33333f;

	UPROPERTY(EditAnywhere)
	float TankRange = 100000;
};
