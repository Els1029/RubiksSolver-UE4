// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string> 
#include <math.h> 
#include <limits.h>

#include "CoreMinimal.h"
#include "MyWebcamReader.h"
#include "OpenCV.h"
#include "cubeDetector.generated.h"


//using namespace std;

struct colourStruct
{
	cv::Scalar upper;
	cv::Scalar lower;
};

UENUM()
enum captureMode
{
	Detect			UMETA(DisplayName = "Detect"),
	Recalibrate     UMETA(DisplayName = "Recalibrate"),
};


/**
 * 
 */
UCLASS()
class OPENCV_API AcubeDetector : public AMyWebcamReader
{
	GENERATED_BODY()

public:
	AcubeDetector();
	virtual void  DoProcessing() override;
	virtual void EndPlay(const  EEndPlayReason::Type EndPlayReason)  override;
	
	UFUNCTION(BlueprintCallable, Category = Webcam)
		void  ChangeCaptureMode();
	UFUNCTION(BlueprintCallable, Category = Webcam)
		void  setColor();
	UFUNCTION(BlueprintCallable, Category = Webcam)
		void  captureFace();

	UFUNCTION(BlueprintImplementableEvent, Category = Webcam)
		void  colourUpdated();
	UFUNCTION(BlueprintImplementableEvent, Category = Webcam)
		void  targetColourUpdated();
	UFUNCTION(BlueprintImplementableEvent, Category = Webcam)
		void  cubeUpdated();
	UFUNCTION(BlueprintImplementableEvent, Category = Webcam)
		void  modeUpdated();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Webcam)
		void  faceDetected();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colors")
		TEnumAsByte<captureMode> currentMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Colors")
		bool flipImage;

	//UFUNCTION(BlueprintImplementableEvent, Category = Webcam)
		//void  SaveImages();//cv::String &name);
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Colors")
		TArray<FColor> colourTargets;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Detection")
		//vector<vector<cv::Point>> contours;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Colors")
		TArray<FColor> newColourTargets;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cube")
		FCubeFace currentFace;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cube")
		FCube currentCube;
protected:
	//houghLines
	vector<cv::Vec2f> lines;
	TMap <float, vector<cv::Vec2f>> paralleLines;
	void DoHoughLines();
	//houghLinesP
	vector<cv::Vec4i> linesP;
	void DoHoughLinesP();
	//contours
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Detection")
		std::vector<std::vector<cv::Point>> contours;
		std::vector<std::vector<cv::Point>> largeContours;
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Detection")
	//UPROPERTY()
		std::vector<std::vector<cv::Point>> hull;
	//TArray<std::vector<cv::Point>> hull;
	void DoContours();
	cv::Mat colourMask;
	cv::Mat colourMaskOpen;
	cv::Mat colourMaskClose;

	cv::Mat contoursMask;
	cv::Mat contoursMaskTemp;
	/*colourStruct white;
	colourStruct yellow;
	colourStruct orange;
	colourStruct red;//*/

	void DoContours2();
	void DoContours3();

	std::vector<cv::Point> approx;
	std::vector<cv::Point> newHull;
	double epsilon;
	double perimeter;
	double area;
	cv::RotatedRect rect;
	//cv::Point2f rectPoints;
	cv::Point2f rectPoints[4];
	std::vector< cv::Point2f> rects;
	std::vector<cv::Point> pointsOfRects;
	TMap <float, TArray<cv::RotatedRect>> paralleRects;



	cv::Mat HSV;
	cv::Mat open_kernel;
	cv::Mat close_kernel;


	std::vector<colourStruct> searchedColours;
	//std::vector<FcolourStruct> searchedColours;


	cv::Point rotatePoint(cv::Point p1, cv::Point center, float angle);
	bool pointWithIn(cv::Point p1, cv::Point center, float distance);
	bool hueInRange(int hue, int lowerBound, int upperBound);
	//
	int getColourNum(cv::Vec3b colour);
	//
	int getColourNum2(cv::Vec3b colour);

	double getColourDistancEuclideanRGB(cv::Vec3b colour, FColor targetColour);
	double getColourDistancEuclideanRGB(cv::Vec3b colour, cv::Vec3b targetColour);

	double getColourDistancCIEDE2000(cv::Vec3b colour, cv::Vec3b targetColour);
	//cv::Vec3b colourLAB;
	cv::Vec3b targetColourLAB;
	cv::Mat3b tarColourBGR;
	cv::Mat3b colourBGR;
	cv::Mat3b tarColourLAB;
	cv::Mat3b colourLAB;

	cv::Mat cannyEdge;
	cv::Mat greyScale;
};
