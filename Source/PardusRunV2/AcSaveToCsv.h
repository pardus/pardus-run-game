// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AcSaveToCsv.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARDUSRUNV2_API UAcSaveToCsv : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAcSaveToCsv();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "CSV")
	static bool SaveStringToCSV(const FString& Phone, const FString& Name, const FString& Mail, const FString& Score, const FString& FilePath);
		
};
