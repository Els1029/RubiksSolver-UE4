// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OpenCV.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "cubeDataStructs.generated.h"


/*#define N_TWIST     2187
#define N_FLIP      2048
#define N_SLICE1    495
#define N_SLICE2    24
#define N_PARITY    2
#define N_URFtoDLF  20160
#define N_FRtoBR    11880
#define N_URtoUL    1320
#define N_UBtoDF    1320
#define N_URtoDF    20160
#define N_URFtoDLB  40320
#define N_URtoBR    479001600
#define N_MOVE      18//*/


UENUM()
enum class faceColours : uint8 {
	/*U	UMETA(DisplayName = "U"),
	D	UMETA(DisplayName = "D"),
	F	UMETA(DisplayName = "F"),
	B	UMETA(DisplayName = "B"),
	R	UMETA(DisplayName = "R"),
	L	UMETA(DisplayName = "L"),*/

	U	UMETA(DisplayName = "U"),
	L	UMETA(DisplayName = "L"),
	F	UMETA(DisplayName = "F"),
	R	UMETA(DisplayName = "R"),
	B	UMETA(DisplayName = "B"),
	D	UMETA(DisplayName = "D"),
	
};

USTRUCT(BlueprintType)
struct FArrayWrapper
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Array") //BlueprintReadWrite, Category = "Cube"
		TArray<int32> innerArray;
};


/**
 * <pre>
 * The names of the facelet positions of the cube
 *|************|
 *|*U1**U2**U3*|
 *|************|
 *|*U4**U5**U6*|
 *|************|
 *|*U7**U8**U9*|
 *|************|
 * ************|************|************|************|
 * *L1**L2**L3*|*F1**F2**F3*|*R1**R2**R3*|*B1**B2**B3*|
 * ************|************|************|************|
 * *L4**L5**L6*|*F4**F5**F6*|*R4**R5**R6*|*B4**B5**B6*|
 * ************|************|************|************|
 * *L7**L8**L9*|*F7**F8**F9*|*R7**R8**R9*|*B7**B8**B9*|
 * ************|************|************|************|
 *                                       |************|
 *                                       |*D1**D2**D3*|
 *                                       |************|
 *                                       |*D4**D5**D6*|
 *                                       |************|
 *                                       |*D7**D8**D9*|
 *                                       |************|
 * </pre>
 * */


UENUM()
enum class Facelet : uint8 {
	U1	UMETA(DisplayName = "U1"),
	U2	UMETA(DisplayName = "U2"),
	U3	UMETA(DisplayName = "U3"),
	U4	UMETA(DisplayName = "U4"),
	U5	UMETA(DisplayName = "U5"),
	U6	UMETA(DisplayName = "U6"),
	U7	UMETA(DisplayName = "U7"),
	U8	UMETA(DisplayName = "U8"),
	U9	UMETA(DisplayName = "U9"),

	L1	UMETA(DisplayName = "L1"),
	L2	UMETA(DisplayName = "L2"),
	L3	UMETA(DisplayName = "L4"),
	L4	UMETA(DisplayName = "L4"),
	L5	UMETA(DisplayName = "L5"),
	L6	UMETA(DisplayName = "L6"),
	L7	UMETA(DisplayName = "L7"),
	L8	UMETA(DisplayName = "L8"),
	L9	UMETA(DisplayName = "L9"),

	F1	UMETA(DisplayName = "F1"),
	F2	UMETA(DisplayName = "F2"),
	F3	UMETA(DisplayName = "F3"),
	F4	UMETA(DisplayName = "F4"),
	F5	UMETA(DisplayName = "F5"),
	F6	UMETA(DisplayName = "F6"),
	F7	UMETA(DisplayName = "F7"),
	F8	UMETA(DisplayName = "F8"),
	F9	UMETA(DisplayName = "F9"),

	R1	UMETA(DisplayName = "R1"),
	R2	UMETA(DisplayName = "R2"),
	R3	UMETA(DisplayName = "R3"),
	R4	UMETA(DisplayName = "R4"),
	R5	UMETA(DisplayName = "R5"),
	R6	UMETA(DisplayName = "R6"),
	R7	UMETA(DisplayName = "R7"),
	R8	UMETA(DisplayName = "R8"),
	R9	UMETA(DisplayName = "R9"),

	B1	UMETA(DisplayName = "B1"),
	B2	UMETA(DisplayName = "B2"),
	B3	UMETA(DisplayName = "B4"),
	B4	UMETA(DisplayName = "B4"),
	B5	UMETA(DisplayName = "B5"),
	B6	UMETA(DisplayName = "B6"),
	B7	UMETA(DisplayName = "B7"),
	B8	UMETA(DisplayName = "B8"),
	B9	UMETA(DisplayName = "B9"),

	D1	UMETA(DisplayName = "D1"),
	D2	UMETA(DisplayName = "D2"),
	D3	UMETA(DisplayName = "D3"),
	D4	UMETA(DisplayName = "D4"),
	D5	UMETA(DisplayName = "D5"),
	D6	UMETA(DisplayName = "D6"),
	D7	UMETA(DisplayName = "D7"),
	D8	UMETA(DisplayName = "D8"),
	D9	UMETA(DisplayName = "D9"),
};

UENUM()
enum class edgePieces : uint8 {
	UF	UMETA(DisplayName = "UF"),
	UR	UMETA(DisplayName = "UR"),
	UB	UMETA(DisplayName = "UB"),
	UL	UMETA(DisplayName = "UL"),

	DF	UMETA(DisplayName = "DF"),
	DR	UMETA(DisplayName = "DR"),
	DB	UMETA(DisplayName = "DB"),
	DL	UMETA(DisplayName = "DL"),

	FR	UMETA(DisplayName = "FR"),
	FL	UMETA(DisplayName = "FL"),
	BR	UMETA(DisplayName = "BR"),
	BL	UMETA(DisplayName = "BL"),
};

UENUM()
enum class cornerPieces : uint8 {
	/*URF	UMETA(DisplayName = "URF"),
	UBR	UMETA(DisplayName = "UBR"),
	ULB	UMETA(DisplayName = "ULB"),
	UFL	UMETA(DisplayName = "UFL"),

	DFR	UMETA(DisplayName = "DFR"),
	DLF	UMETA(DisplayName = "DLF"),
	DBL	UMETA(DisplayName = "DBL"),
	DRB	UMETA(DisplayName = "DRB"),//*/

	ULB	UMETA(DisplayName = "ULB"),
	UBR	UMETA(DisplayName = "UBR"),
	URF	UMETA(DisplayName = "URF"),
	UFL	UMETA(DisplayName = "UFL"),

	DBL	UMETA(DisplayName = "DBL"),
	DRB	UMETA(DisplayName = "DRB"),
	DFR	UMETA(DisplayName = "DFR"),
	DLF	UMETA(DisplayName = "DLF"),
};


USTRUCT(BlueprintType)
struct FFormatedCube
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Colours") //BlueprintReadWrite, Category = "Cube"
		TArray<faceColours> face_Colours;
};


USTRUCT(BlueprintType)
struct FCubieCube
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Position") //BlueprintReadWrite, Category = "Cube"
		TArray<cornerPieces> cornerPosition;
	UPROPERTY(BlueprintReadWrite, Category = "Position") //BlueprintReadWrite, Category = "Cube"
		TArray<edgePieces> edgePosition;

	UPROPERTY(BlueprintReadWrite, Category = "Orientation") //BlueprintReadWrite, Category = "Cube"
		TArray<int32> cornerOrientation;
	UPROPERTY(BlueprintReadWrite, Category = "Orientation") //BlueprintReadWrite, Category = "Cube"
		TArray<int32> edgeOrientation;
};


USTRUCT(BlueprintType)
struct FCoordCube
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 twist;
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 flip;
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 parity;
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 FRtoBR;
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 URFtoDLF;
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 URtoUL;
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 UBtoDF;
	UPROPERTY(BlueprintReadWrite, Category = "Coordinates")
		int32 URtoDF;
};


USTRUCT(BlueprintType)
struct FSolution
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Solution") //BlueprintReadWrite, Category = "Cube"
		TArray<ECubeMove> solution;
	UPROPERTY(BlueprintReadWrite, Category = "Data") //BlueprintReadWrite, Category = "Cube"
		TArray<FCoordCube> cubes;

	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> ax;             // The axis of the move
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> po;             // The power of the move
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> flip;           // phase1 coordinates
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> twist;
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> slice;
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> parity;         // phase2 coordinates
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> URFtoDLF;
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> FRtoBR;
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> URtoUL;
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> UBtoDF;
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> URtoDF;
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> minDistPhase1;  // IDA* distance do goal estimations
	UPROPERTY(BlueprintReadWrite, Category = "Data")
		TArray<int32> minDistPhase2;
};




/**
 * 
 */
class INITTESTS_API cubeDataStructs : public UBlueprintFunctionLibrary
{
public:
	UPROPERTY()
	static const Facelet cornerFacelet[8][3];
	UPROPERTY()
	static const faceColours cornerColour[8][3];

	UPROPERTY()
	static const Facelet edgeFacelet[12][2];
	UPROPERTY()
	static const faceColours edgeColour[12][2];


	/// <summary>
	/// //////////////////////////////////////////////////////////////////////
	/// </summary>
	/*UPROPERTY()
	static int32 twistMove[N_TWIST][N_MOVE];
	UPROPERTY()
	static int32 flipMove[N_FLIP][N_MOVE];
	UPROPERTY()
	static const int32 parityMove[2][18];

	UPROPERTY()
	static int32 FRtoBR_Move[N_FRtoBR][N_MOVE];
	UPROPERTY()
	static int32 URFtoDLF_Move[N_URFtoDLF][N_MOVE];
	UPROPERTY()
	static int32 URtoDF_Move[N_URtoDF][N_MOVE];

	UPROPERTY()
	static int32 URtoUL_Move[N_URtoUL][N_MOVE];
	UPROPERTY()
	static int32 UBtoDF_Move[N_UBtoDF][N_MOVE];
	UPROPERTY()
	static int32 MergeURtoULandUBtoDF[336][336];

	UPROPERTY()
	static int32 Slice_URFtoDLF_Parity_Prun[N_SLICE2 * N_URFtoDLF * N_PARITY / 2];
	UPROPERTY()
	static int32 Slice_URtoDF_Parity_Prun[N_SLICE2 * N_URtoDF * N_PARITY / 2];
	UPROPERTY()
	static int32 Slice_Twist_Prun[N_SLICE1 * N_TWIST / 2 + 1];
	UPROPERTY()
	static int32 Slice_Flip_Prun[N_SLICE1 * N_FLIP / 2];

	UFUNCTION(BlueprintCallable, Category = Setup)
		static void SetUpTables();
//*/
	UFUNCTION()
	static FCubieCube* getSolvedCubieCube();
	UFUNCTION()
	static FCubieCube* getMoveCubiesCube();



	/// GET COORDINATES FOR CUBE FOR SOLVING
	UFUNCTION()
	static int32 getTwist(FCubieCube* cubiecube);
	UFUNCTION()
	static void setTwist(FCubieCube* cubiecube, int32 twist);
	UFUNCTION()
	static int32 getFlip(FCubieCube* cubiecube);
	UFUNCTION()
	static void setFlip(FCubieCube* cubiecube, int32 flip);
	UFUNCTION()
	static int32 cornerParity(FCubieCube* cubiecube);
	UFUNCTION()
	static int32 edgeParity(FCubieCube* cubiecube);

	UFUNCTION()
	static int32 getFRtoBR(FCubieCube* cubiecube);
	UFUNCTION()
		static void setFRtoBR(FCubieCube* cubiecube, int16 idx);
	UFUNCTION()
	static int32 getURFtoDLF(FCubieCube* cubiecube);
	UFUNCTION()
		static void setURFtoDLF(FCubieCube* cubiecube, int16 idx);
	UFUNCTION()
	static int32 getURtoDF(FCubieCube* cubiecube);
	UFUNCTION()
		static void setURtoDF(FCubieCube* cubiecube, int32 idx);
	UFUNCTION()
	static int32 getURtoUL(FCubieCube* cubiecube);
	UFUNCTION()
		static void setURtoUL(FCubieCube* cubiecube, int16 idx);
	UFUNCTION()
	static int32 getUBtoDF(FCubieCube* cubiecube);
	UFUNCTION()
		static void setUBtoDF(FCubieCube* cubiecube, int16 idx);
private:
	//UPROPERTY(BlueprintReadWrite, Category = "PositionTables") //BlueprintReadWrite, Category = "Cube"
		//twistTable
	UFUNCTION()
	static int32 Cnk(int n, int k);
	UFUNCTION()
	static void rotateLeft_corner(cornerPieces* arr, int l, int r);
	UFUNCTION()
	static void rotateRight_corner(cornerPieces* arr, int l, int r);
	UFUNCTION()
	static void rotateLeft_edge(edgePieces* arr, int l, int r);
	UFUNCTION()
	static void rotateRight_edge(edgePieces* arr, int l, int r);

	UFUNCTION()
	static void cornerMultiply(FCubieCube* cubiecube, FCubieCube* b);
	UFUNCTION()
	static void edgeMultiply(FCubieCube* cubiecube, FCubieCube* b);
	UFUNCTION()
	static void multiply(FCubieCube* cubiecube, FCubieCube* b);

	UFUNCTION()
	static int32 getURtoDF_standalone(int32 idx1, int32 idx2);

public:
	UFUNCTION()
	static void setPruning(int32* table, int32 index, int32 value);
	UFUNCTION()
	static int32 getPruning(int32* table, int32 index);

};
