// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenCV.h"
#include "cubeDataStructs.h"

//#include "ckociemba/search.h"
//#include "preparation.h"
//#include "prunetable_helpers.h"



//#include "Kociemba/utils.h"
//#include "Kociemba/preparation.h"

//#include "newKociemba/optimal_solver.h"

#include "src/cubie.h"
#include "src/coord.h"
#include "src/face.h"
#include "src/move.h"
#include "src/prun.h"
#include "src/solve.h"
#include "src/sym.h"


#include "Chaos/Utilities.h"
//#include "Test/include/search.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CubeFunctions.generated.h"

#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))

/**
 * 
 */
UCLASS()
class INITTESTS_API UCubeFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = Cube)
		static FCubeFace rotateFaceCW(FCubeFace inputFace);

	UFUNCTION(BlueprintCallable, Category = Cube)
		static void rotateFaceCW2(FCubeFace inputFace);

	UFUNCTION(BlueprintCallable, Category = Cube)
		static FCubeFace rotateFaceACW(FCubeFace inputFace);

	UFUNCTION(BlueprintCallable, Category = Cube)
		static void rotateFaceACW2(FCubeFace inputFace);

	/*UFUNCTION(BlueprintCallable, Category = Cube)
		static void rotateFaceCW(FCubeFace inputFace);

	UFUNCTION(BlueprintCallable, Category = Cube)
		static void rotateFaceACW(FCubeFace inputFace);//*/

	UFUNCTION(BlueprintCallable, Category = Cube)
		static void rotateCube(UPARAM(ref) FCube& inputCube, ECubeMove move);

	
	UFUNCTION(BlueprintCallable, Category = Cube)
		static FFormatedCube formatCube(FCube inputCube);

	UFUNCTION(BlueprintCallable, Category = Cube)
		static FCubieCube formattedToCubie(FFormatedCube inputCube);
	UFUNCTION(BlueprintCallable, Category = Cube)
		static FCoordCube CubieToCoord(FCubieCube inputCube);
	
	/*UFUNCTION(BlueprintCallable, Category = Cube)
		static TArray<ECubeMove> solutionKociemba(FCubieCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator);//*/
	//*/
	UFUNCTION(BlueprintCallable, Category = Cube)
		static FString solutionKociemba2(FCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator);

	UFUNCTION(BlueprintCallable, Category = Cube)
		static FString solutionKociemba3(FCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator);

	UFUNCTION(BlueprintCallable, Category = Cube)
		static FString solutionKociemba4(FCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator);
	
	UFUNCTION(BlueprintCallable, Category = Cube)
		static TArray<ECubeMove> solutionToString(FSolution search, int32 length, int32 depthPhase1);
	UFUNCTION(BlueprintCallable, Category = Cube)
		static int32 totalDepth(FSolution search, int32 depthPhase1, int32 maxDepth);


	UFUNCTION(BlueprintCallable, Category = Cube)
		static void initData();
	//*/


	/*UFUNCTION(BlueprintCallable, Category = Cube)
		static void setUpTables();
	//*/

private:
	static const uint8 TOP[];
	static const uint8 MID[];
	static const uint8 BOT[];
	
	static const uint8 LEFT[];
	static const uint8 CENTER[];
	static const uint8 RIGHT[];

	static void rotateCubeEdgeHandler(FCube inputCube, uint8* faceOrder, uint8* rowColOfFace);

	//static cube_t getCubeData(FFormatedCube inputCube);
	//static Cube getCubeData2(FFormatedCube inputCube);

	static int getCornerPermutaion(FCubieCube inputCube);
	static int getCornerOrientation(FCubieCube inputCube);
	//static cube_t getCubeData(FCube inputCube);
	//static char* formatCubeAsString(FCube inputCube);
	//static char* formatCubeAsString(FCube inputCube, char* string);
	static std::string formatCubeAsString(FCube inputCube);
};
