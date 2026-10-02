// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior/Public/Characters/WarriorHeroCharacter.h"

#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Warrior/Public/WarriorDebugHelper.h"

AWarriorHeroCharacter::AWarriorHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	
	bUseControllerRotationPitch =false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	
	
	
	
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength=230.f;
	CameraBoom->SocketOffset=FVector(0.0f, 55.f, 65.0f);
	CameraBoom->bUsePawnControlRotation=true;
	
	FollowCamera=CreateDefaultSubobject<UCameraComponent>("Camera");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation=false;
	
	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed=400.f;
	GetCharacterMovement()->BrakingDecelerationFalling=2300.f;
}

void AWarriorHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AWarriorHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (WarriorAbilitySystemComponent && WarriorAttributeSet)
	{
		const FString ASCText=FString::Printf(TEXT("Owner Actor: %s, AvatarActor: %s"), *WarriorAbilitySystemComponent->GetOwnerActor()->GetActorLabel(), *WarriorAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
		Debug::Print(TEXT("Ability system component valid") + ASCText);
		Debug::Print(TEXT("Attribute Set valid") + ASCText);
	}
}
