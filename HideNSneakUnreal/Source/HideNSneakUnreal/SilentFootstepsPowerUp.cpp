// Fill out your copyright notice in the Description page of Project Settings.


#include "SilentFootstepsPowerUp.h"

ASilentFootstepsPowerUp::ASilentFootstepsPowerUp(const FObjectInitializer& OI) : Super(OI) {

}

void ASilentFootstepsPowerUp::ApplyPowerUp_Implementation(ACharacter* Character)
{
	APickup::ApplyPowerUp_Implementation(Character);
	if (AHideNSneakCPPCharacter* Player = Cast<AHideNSneakCPPCharacter>(Character)) {
		Player->SetSilentFootsteps(true);
		PlayerQueue.push(Player);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, this, &ASilentFootstepsPowerUp::UnApplyPowerUp, PowerUpDuration, false);
	}
}

void ASilentFootstepsPowerUp::UnApplyPowerUp_Implementation()
{
	APickup::UnApplyPowerUp_Implementation();
	AHideNSneakCPPCharacter* Player = PlayerQueue.front();
	PlayerQueue.pop();
	Player->SetSilentFootsteps(false);
}
