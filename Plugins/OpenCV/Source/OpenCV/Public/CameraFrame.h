#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include <vector>

#include "Templates/SharedPointer.h"

#if PLATFORM_ANDROID
#include <jni.h>
#include <errno.h>
#include <android/log.h>

#define ALOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "FCameraFrame", __VA_ARGS__))
#define ALOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "FCameraFrame", __VA_ARGS__))
#endif

using namespace std;


class OPENCV_API FCameraFrame {

public:
	FCameraFrame();

	bool captureCamera(int cameraId, int width, int height);
	bool getActualVideoSize(int& width, int& height);
	void releaseCamera();
	bool loadClassifierFile(const char* classifierFile);

	void update(std::vector<uchar>& buffer);
#if PLATFORM_WINDOWS
	cv::Mat androidFrame;
#elif PLATFORM_ANDROID
	static cv::Mat androidFrame;
#endif
	void getFrame(cv::Mat& frame);

private:

	cv::VideoCapture stream;
	bool m_isOpen;

	cv::CascadeClassifier faceCascade;
};


#if PLATFORM_ANDROID

extern "C" {
	JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved);
};

extern "C"
jboolean
Java_org_getid_facerecognition_AndroidCamera_FrameProcessing(
	JNIEnv * env, jobject thiz,
	jint width, jint height,
	jbyteArray NV21FrameData);

extern "C"
void
Java_org_getid_facerecognition_AndroidCamera_InitJNI(JNIEnv * env, jobject thiz);

#endif            
