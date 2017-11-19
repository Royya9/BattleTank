// Free to Play. By SoNa Games

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

float ATank::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	int32 DamageToApply = FMath::Clamp(FPlatformMath::RoundToInt(ActualDamage), 0, CurrentHealth);

	if (DamageToApply > 0)
	{
		CurrentHealth -= DamageToApply;
	}
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
		SetLifeSpan(0.001f);
	}
	/*UE_LOG(LogTemp, Warning, TEXT("Damage to Apply is %i and Current Health is %i"), DamageToApply, CurrentHealth);*/
	return ActualDamage;
}

float ATank::GetHealthPercent() const
{
	return ((float)CurrentHealth / (float)MaxHealth);
}
