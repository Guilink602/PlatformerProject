// Fill out your copyright notice in the Description page of Project Settings.


#include "AClimber.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <EnhancedInputComponent.h>

// Sets default values
AAClimber::AAClimber()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAClimber::BeginPlay()
{
	Super::BeginPlay();
	//Add Input Mapping Context

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(inputMappingContext, 0);
		}
	}
}

void AAClimber::Jump(const FInputActionValue& Value)
{
}

void AAClimber::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Error, TEXT("current input %s"), *MovementVector.ToString());
}

void AAClimber::Grappling(const FInputActionValue& Value)
{
}

// Called every frame
void AAClimber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAClimber::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AAClimber::Jump);

		//Moving
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAClimber::Move);

	
		//Grappling
			EnhancedInputComponent->BindAction(GrapplingAction, ETriggerEvent::Triggered, this, &AAClimber::Grappling);

	}
}

