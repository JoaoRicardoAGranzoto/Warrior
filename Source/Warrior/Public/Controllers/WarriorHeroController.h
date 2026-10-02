// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WarriorHeroController.generated.h"

class UDataAsset_InputConfig;

UCLASS()
class WARRIOR_API AWarriorHeroController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess="true"))
	UDataAsset_InputConfig* InputConfigDataAsset;




	virtual void SetupInputComponent() override;

	void Input_Move(const struct FInputActionValue& InputActionValue);
	void Input_Look(const struct FInputActionValue& InputActionValue);
	void Input_Jump();
	void Input_Sprint();
};