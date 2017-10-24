// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	void BeginPlay() override;
	
private:
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
	
};
