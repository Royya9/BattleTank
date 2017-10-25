// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAIController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	void BeginPlay() override;

	void AimTowardsPlayer();

	virtual void Tick(float DeltaTime) override;
	
private:
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
	
};
