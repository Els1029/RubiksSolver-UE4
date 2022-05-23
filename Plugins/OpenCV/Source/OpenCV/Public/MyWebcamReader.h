// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CameraFrame.h" 

#include "opencv2/core.hpp" 
#include "opencv2/highgui.hpp" 	
#include "opencv2/imgproc.hpp" 
#include "opencv2/videoio.hpp" 
#include "opencv2/imgcodecs.hpp"

//#include "GameFramework/Actor.h" 
#include "Runtime/Engine/Classes/Engine/Texture2D.h" 


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyWebcamReader.generated.h"

UCLASS()
class OPENCV_API AMyWebcamReader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWebcamReader();

	virtual void BeginPlay() override;
	virtual void EndPlay(const  EEndPlayReason::Type EndPlayReason)  override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Webcam)
		int32 CameraID;

	//  If the webcam images should be resized every frame 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Webcam)
		bool  ShouldResize;

	//  The targeted resize width and height (width, height) 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Webcam)
		FVector2D ResizeDeminsions;

	//  The rate at which the color data array and video texture is updated (in frames per second) 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Webcam)
		float  RefreshRate;

	//  The refresh timer 
	UPROPERTY(BlueprintReadWrite, Category = Webcam)
		float  RefreshTimer;

	//  Blueprint Event called every time the video frame is updated 
	UFUNCTION(BlueprintImplementableEvent, Category = Webcam)
		void  OnNextVideoFrame();

	UPROPERTY(BlueprintReadWrite, Category = Webcam)
		FVector2D VideoSize;

	//  The current video frame's corresponding texture 
	UPROPERTY(BlueprintReadOnly, Category = Webcam)
		UTexture2D* VideoTexture;

	//  The current data array 
	UPROPERTY(BlueprintReadOnly, Category = Webcam)
		TArray <FColor> Data;

	//  If the stream has succesfully opened yet 
	UPROPERTY(BlueprintReadOnly, Category = Webcam)
		bool  isStreamOpen;

	//  OpenCV fields
	//UPROPERTY(BlueprintReadOnly, Category = Webcam)
	cv::Mat frame;
	//  cv::VideoCapture stream; 
	cv::Size size;

	//  OpenCV prototypes 
	void  UpdateFrame();
	virtual void  DoProcessing();
	void  UpdateTexture();

	UFUNCTION(BlueprintCallable, Category = Webcam)
		void BeginCapture();

	UFUNCTION(BlueprintCallable, Category = Webcam)
		void ReleaseCamera();

protected:
	// Called when the game starts or when spawned
	void  UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool  bFreeData);

	// Pointer to update texture region 2D struct 
	FUpdateTextureRegion2D* VideoUpdateTextureRegion;

	TSharedPtr<FCameraFrame> CameraFrame;
	std::vector<uchar> buffer;


	bool  bBeginCapture;
};
