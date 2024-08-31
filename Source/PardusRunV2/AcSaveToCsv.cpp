// Fill out your copyright notice in the Description page of Project Settings.


#include "AcSaveToCsv.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Internationalization/Text.h"

// Sets default values for this component's properties
UAcSaveToCsv::UAcSaveToCsv()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAcSaveToCsv::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAcSaveToCsv::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UAcSaveToCsv::SaveStringToCSV(const FString& Phone, const FString& Name, const FString& Mail, const FString& Score, const FString& FilePath)
{
	FString CSVString = Name + "," + Phone + "," + Mail + "," + Score + "\n";

	// Convert the string to UTF-8 encoded data
	const TCHAR* TextToAppendUTF8 = *CSVString;
	TArray<uint8> TextData;
	FTCHARToUTF8 Converter(TextToAppendUTF8);
	TextData.Append((uint8*)Converter.Get(), Converter.Length());

	// Use the EFileWrite::FILEWRITE_Append flag to append to an existing file
    return FFileHelper::SaveArrayToFile(TextData, *FilePath, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}