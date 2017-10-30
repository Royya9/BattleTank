// Free to Play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:

	UPROPERTY(EditAnywhere, Category = "Setup")
	float DegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevationDegrees = 40; 

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinElevationDegrees = 0; 
};
