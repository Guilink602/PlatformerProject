// Fill out your copyright notice in the Description page of Project Settings.


#include "AClimber.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <EnhancedInputComponent.h>  
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AAClimber::AAClimber()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	
	//Assign SpringArm class variables.
	SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 400.f;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->CameraLagSpeed = 3.0f;
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
			UE_LOG(LogTemp, Error, TEXT("detected "));
			Subsystem->AddMappingContext(inputMappingContext, 0);		
		}
	}
}

void AAClimber::Jump(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Error, TEXT("detected "));
}

void AAClimber::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Error, TEXT("detected "));
	UE_LOG(LogTemp, Error, TEXT("current input %s"), *MovementVector.ToString());
}

void AAClimber::Grappling(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Error, TEXT("detected "));
}

// Called every frame
void AAClimber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAClimber::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Error, TEXT("detected setup "));
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		UE_LOG(LogTemp, Error, TEXT("detected in setup"));
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AAClimber::Jump);

		//Moving
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAClimber::Move);

	
		//Grappling
			EnhancedInputComponent->BindAction(GrapplingAction, ETriggerEvent::Triggered, this, &AAClimber::Grappling);

	}
}

