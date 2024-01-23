// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"
#include "AClimber.generated.h"

UCLASS()
class PLATFORMERPROJECT_API AAClimber : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAClimber();



	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
		UInputMappingContext* inputMappingContext;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
		UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
		UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
		UInputAction* GrapplingAction;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for jump input */
	void Jump(const FInputActionValue& Value);

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for grappling input */
	void Grappling(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, Category = "Camera")
		class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, Category = "Camera")
		class UCameraComponent* CameraComp;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
