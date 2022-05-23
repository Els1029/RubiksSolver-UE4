// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "OpenCV.generated.h"

USTRUCT(BlueprintType)
struct FCubeFace
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Student")
		TArray<int32> coloursOfFace; //a 1d array cause //value is index of colourTarget
	//[ 0, 1, 2
	//  3, 4, 5
	//  6, 7, 8]
};

USTRUCT(BlueprintType)
struct FCube
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Cube")
		TArray<FCubeFace> faces;
	UPROPERTY(BlueprintReadWrite, Category = "Cube")
		TArray<FColor> colourTargets;
	UPROPERTY(BlueprintReadWrite, Category = "Cube")
		FVector cubeSize;
};

UENUM(BlueprintType)
enum class ECubeMove : uint8 {
	INVALID = 0  UMETA(DisplayName = "INVALID"),
	// 3x3 notation
	F	UMETA(DisplayName = "F"), //Front // 1
	F2  UMETA(DisplayName = "F2"), //Front 180
	F_  UMETA(DisplayName = "F'"), //Front ACW
	B	UMETA(DisplayName = "B"), //Back  // 6
	B2	UMETA(DisplayName = "B2"), //Back 180
	B_	UMETA(DisplayName = "B'"), //Back ACW
	R	UMETA(DisplayName = "R"), //Right
	R2	UMETA(DisplayName = "R2"), //Right 180
	R_	UMETA(DisplayName = "R'"), //Right ACW
	L	UMETA(DisplayName = "L"), //Left
	L2	UMETA(DisplayName = "L2"), //Left 180
	L_	UMETA(DisplayName = "L'"), //Left ACW
	U	UMETA(DisplayName = "U"), //Up
	U2	UMETA(DisplayName = "U2"), //Up 180
	U_	UMETA(DisplayName = "U'"), //Up ACW
	D	UMETA(DisplayName = "D"), //Down
	D2	UMETA(DisplayName = "D2"), //Down 180
	D_	UMETA(DisplayName = "D'"), //Down ACW

	M	UMETA(DisplayName = "M"), //Middle ////LEFT-RIGHT SLICE IN LEFT DIRECTION
	M2	UMETA(DisplayName = "M2"), //Middle
	M_	UMETA(DisplayName = "M'"), //Middle ACW
	E	UMETA(DisplayName = "E"), //Equator ////UP-DOWN SLICE IN DOWN DIRECTION
	E2	UMETA(DisplayName = "E2"), //Equator
	E_	UMETA(DisplayName = "E'"), //Equator ACW
	S	UMETA(DisplayName = "S"), //Standing ///FRONT-BACK SLICE IN FRONT DIRECTION 
	S2	UMETA(DisplayName = "S2"), //Standing 180
	S_	UMETA(DisplayName = "S'"), //Standing ACW

	X	UMETA(DisplayName = "X"), //Rotate on R
	X2	UMETA(DisplayName = "X2"), //Rotate on R 180
	X_	UMETA(DisplayName = "X'"), //Rotate on R ACW
	Y	UMETA(DisplayName = "Y"), //Rotate on U
	Y2	UMETA(DisplayName = "Y2"), //Rotate on U 180
	Y_	UMETA(DisplayName = "Y'"), //Rotate on U ACW
	Z	UMETA(DisplayName = "Z"), //Rotate on F
	Z2	UMETA(DisplayName = "Z2"), //Rotate on F 180
	Z_	UMETA(DisplayName = "Z'"), //Rotate on F ACW
};

class FOpenCVModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;


private:
	void* OpenCV_World_Handler;
	void* OpenCV_WorldD_Handler;
	void* OpenCV_FFmpeg_Handler;
};
