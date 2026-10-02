// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior/Public/Controllers/WarriorHeroController.h"
#include "EnhancedInputSubsystems.h"
#include "WarriorGameplayTags.h"
#include "Components/Input/WarriorInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "GameFramework/Character.h"

void AWarriorHeroController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	checkf(InputConfigDataAsset, TEXT("Forgot to set an InputConfigDataAsset"));

	UEnhancedInputLocalPlayerSubsystem* Subsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	check(Subsystem)
	
	
	
	
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultInputContext, 0);
	
	UWarriorInputComponent* WarriorInputComponent =	CastChecked<UWarriorInputComponent>(InputComponent);
	
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Jump, ETriggerEvent::Triggered, this, &ThisClass::Input_Jump);
	WarriorInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::Input_Sprint, ETriggerEvent::Triggered, this, &ThisClass::Input_Sprint);
}

void AWarriorHeroController::Input_Move(const struct FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector=InputActionValue.Get<FVector2D>();
	
	const FRotator MovementRotation(0.f, GetControlRotation().Yaw, 0.f );

	/*if (MovementVector.X != 0.f && GetPawn())
	{
		const FVector ForwardDirection=MovementRotation.RotateVector(FVector::ForwardVector);
		
		GetPawn()->AddMovementInput(ForwardDirection, MovementVector.X);
	}

	if (MovementVector.X != 0.f && GetPawn())
	{
		const FVector RightDirection=MovementRotation.RotateVector(FVector::RightVector);
		
		GetPawn()->AddMovementInput(RightDirection, MovementVector.Y);
	}*/
	
	const FVector ForwardDirection=MovementRotation.RotateVector(FVector::ForwardVector);
		
	GetPawn()->AddMovementInput(ForwardDirection, MovementVector.X);
	
	const FVector RightDirection=MovementRotation.RotateVector(FVector::RightVector);
		
	GetPawn()->AddMovementInput(RightDirection, MovementVector.Y);
}

void AWarriorHeroController::Input_Look(const struct FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector=InputActionValue.Get<FVector2D>();

	/*if (LookAxisVector.X != 0.f)
	
	
	
	{
		AddYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddPitchInput(LookAxisVector.Y);
	}*/
	
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AWarriorHeroController::Input_Jump()
{
	if (GetCharacter())
	{
		GetCharacter()->Jump();
	}
}

void AWarriorHeroController::Input_Sprint()
{
	
}