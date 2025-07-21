// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

// Add camera component to PlayerChar
#include "Camera/CameraComponent.h"

// Add resource header
#include "Resource_M.h"
#include "PlayerChar.generated.h"

UCLASS()
class GAM312_BURLEY_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Add movement functions
	UFUNCTION()
	    void MoveForward(float InputAxis);

	UFUNCTION()
		void MoveRight(float InputAxis);

	UFUNCTION()
	    void StartJump();

	UFUNCTION()
	    void StopJump();

	UFUNCTION()
	    void FindObject();

	// Add FirstPersonCamera
	UPROPERTY(VisibleAnywhere)
	    UCameraComponent* PlayerCamComp;

    // Add player stats
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	    float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	    float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	    float Stamina = 100.0f;

	// Resources
	UPROPERTY(EditAnywhere, Category = "Resources")
		int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Stone;

	UPROPERTY(Editanywhere, Category = "Resources")
		int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
		TArray<FString> ResourcesNameArray;

	// Stat Functions
	UFUNCTION(BlueprintCallable)
		void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
		void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);

	UFUNCTION()
		void DecreaseStats();

	UFUNCTION()
	void GiveResource(float amount, FString resourceType);

};
