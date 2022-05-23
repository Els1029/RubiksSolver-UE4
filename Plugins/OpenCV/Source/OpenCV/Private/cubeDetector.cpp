// Fill out your copyright notice in the Description page of Project Settings.


#include "cubeDetector.h"
using namespace cv;
AcubeDetector::AcubeDetector()
{
    /*namedWindow("image");
    createTrackbar("HMin", "image", 0, 179);
    createTrackbar("SMin", "image", 0, 255);
    createTrackbar("VMin", "image", 0, 255);
    createTrackbar("HMax", "image", 0, 179);
    createTrackbar("SMax", "image", 0, 255);
    createTrackbar("VMax", "image", 0, 255);//*/

    tarColourBGR = Mat::zeros(Size(1,1), CV_8UC3);
    colourBGR = Mat::zeros(Size(1, 1), CV_8UC3);

    /*open_kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
    close_kernel = getStructuringElement(MORPH_RECT, Size(3, 3));//*/

    open_kernel = getStructuringElement(MORPH_ELLIPSE, Size(7, 7));
    close_kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));

    currentCube.cubeSize = FVector(3, 3, 3);



    /*//WHITE
    white.upper = Scalar(255, 35, 255);
    white.lower = Scalar(0, 0, 120);
    searchedColours.push_back(white);//*/

    /*//YELLOW
    yellow.upper = Scalar(45, 255, 255);
    yellow.lower = Scalar(21, 100, 84); //80, 100, 84
    searchedColours.push_back(yellow);//*/
    /*//
    orange.upper = Scalar(17, 255, 255);
    orange.lower = Scalar(4, 130, 125);
    searchedColours.push_back(orange);//*/

    /*//
    red.upper = Scalar(179, 255, 255);
    red.lower = Scalar(170, 110, 110); //358, 77, 39
    searchedColours.push_back(red);//*/

    /*//
    colourStruct redLowerEnd;
    redLowerEnd.upper = Scalar(6, 255, 255);
    redLowerEnd.lower = Scalar(0, 110, 110); //358, 77, 39
    searchedColours.push_back(redLowerEnd);//*/

}

void AcubeDetector::DoProcessing()
{

    if (!flipImage)//CameraFrame flip image by default for some reason
    {
        flip(frame, frame, 1);
    }

	//Store canny image in greyScale
	cvtColor(frame, greyScale, COLOR_BGR2GRAY);

    //blur(greyScale, greyScale, Size(5, 5), 0);//blur image for better edge detection
    //GaussianBlur(greyScale, greyScale,Size(5,5),0);//blur image for better edge detection

    //Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
    //int kernel[3][3] = { {-1, -1, -1 }, { -1, 9, -1 }, { -1, -1, -1 }};
    //filter2D(greyScale, greyScale, -1, kernel);

    Mat blured;
    //BetterSharperning 
    GaussianBlur(greyScale, blured, cv::Size(0, 0), 3);
    addWeighted(greyScale, 1.5, blured, -1, 0, greyScale);

	Canny(greyScale, cannyEdge, 50, 75);


    if (currentMode == Detect) {
        //DoHoughLines();
        //DoHoughLinesP();
        //DoContours();
        //DoContours2();
        DoContours3();
    }
    else if (currentMode == Recalibrate) {
        //Need to change a colours
        //DRAW CROSS
        int crossSize  = 25;
        int centreSize =  5;
        line(frame, Point((frame.cols / 2) - crossSize, frame.rows / 2), Point((frame.cols / 2) - centreSize, frame.rows / 2), Scalar(0, 0, 0), 3);
        line(frame, Point((frame.cols / 2), (frame.rows / 2) - crossSize), Point((frame.cols / 2), (frame.rows / 2) - centreSize), Scalar(0, 0, 0), 3);

        line(frame, Point((frame.cols / 2) + centreSize, frame.rows / 2), Point((frame.cols / 2) + crossSize, frame.rows / 2), Scalar(0, 0, 0), 3);
        line(frame, Point((frame.cols / 2), (frame.rows / 2) + centreSize), Point((frame.cols / 2), (frame.rows / 2) + crossSize), Scalar(0, 0, 0), 3);

    }
    

    //Show frames in popup windows
    //imshow("Test", frame);
    //imshow("edge", cannyEdge);

    //imshow("sharpen image", blured);
}

void AcubeDetector::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    /*delete& contours;
    delete& largeContours;
    delete& hull;//*/
    Super::EndPlay(EndPlayReason);
}

void AcubeDetector::ChangeCaptureMode()
{
    if (currentMode == Detect) {
        newColourTargets.Empty();
        currentCube = FCube{};
        currentMode = Recalibrate;
        modeUpdated();
    }
    else if (currentMode == Recalibrate) {
        newColourTargets.Empty();
        currentCube = FCube{};
        currentCube.colourTargets = colourTargets;
        currentMode = Detect;
        modeUpdated();
    }
}

void AcubeDetector::setColor()
{
    if (newColourTargets.Num() < 6)
    {
        Vec3b newColour = frame.at<Vec3b>(Point(frame.cols / 2, frame.rows / 2));

        newColourTargets.Add(FColor(newColour[2], newColour[1], newColour[0], 255));
        //UE_LOG(LogTemp, Warning, TEXT("________________NEW COLOUR______________________"));
        //UE_LOG(LogTemp, Warning, TEXT("R: %d  G: %d  B: %d"), newColour[2], newColour[1], newColour[0]);
        colourUpdated();
    }
    else if (newColourTargets.Num() == 6) {
        colourTargets = newColourTargets;
        currentCube.colourTargets = colourTargets;
        targetColourUpdated();
        ChangeCaptureMode();
    }
    else {
        ChangeCaptureMode();
    }

}

void AcubeDetector::captureFace()
{
    if (currentCube.faces.Num() < 6)
    {
        currentCube.faces.Add(currentFace);
        currentFace = FCubeFace{};
        cubeUpdated();
    }
    else if (currentCube.faces.Num() == 6) {

    }
    else {

    }
}

void AcubeDetector::DoHoughLines()
{
    //
    HoughLines(cannyEdge, lines, 1, CV_PI / 180, 100, 0, 0); // runs the actual detection

    paralleLines.Empty();
    
    //group lines based on angles(within 4degrees of the first detetcted line)
    for (size_t i = 0; i < lines.size(); i++)
    {
        bool found = false;
        for (auto& Elem : paralleLines)
        {
            if (Elem.Key > lines[i][1] - (CV_PI / 90) && Elem.Key < lines[i][1] + (CV_PI / 90))
            {
                Elem.Value.push_back(lines[i]);
                found = true;
            }
            
        }
        if (!found) {
            vector<cv::Vec2f> newVector;
            newVector.push_back(lines[i]);
            paralleLines.Add(lines[i][1], newVector);
        }
    }

    for (auto& Elem : paralleLines)
    {
        Scalar colour = Scalar(rand() % 256, rand() % 256, rand() % 256); // random colour
        // Draw the lines
        for (size_t i = 0; i < Elem.Value.size(); i++)
        {
            float rho = Elem.Value[i][0], theta = Elem.Value[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a * rho, y0 = b * rho;
            pt1.x = cvRound(x0 + 2000 * (-b));
            pt1.y = cvRound(y0 + 2000 * (a));
            pt2.x = cvRound(x0 - 2000 * (-b));
            pt2.y = cvRound(y0 - 2000 * (a));
            line(frame, pt1, pt2, colour, 3, LINE_AA);
        }
    }




    // Draw the lines
    /*for (size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 2000 * (-b));
        pt1.y = cvRound(y0 + 2000 * (a));
        pt2.x = cvRound(x0 - 2000 * (-b));
        pt2.y = cvRound(y0 - 2000 * (a));
        line(frame, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
    }*/
}

void AcubeDetector::DoHoughLinesP()
{
    //CV_PI / 180

    //change last value so lines can be detected at further ranges
    HoughLinesP(cannyEdge, linesP, 1, CV_PI / 180, 50, 50, 20); // runs the actual detection
// Draw the lines
    for (size_t i = 0; i < linesP.size(); i++)
    {
        Vec4i l = linesP[i];
        line(frame, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(100, 100, 100), 3, LINE_AA);
        line(frame, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0,255), 2, LINE_AA);
    }
}

void AcubeDetector::DoContours()
{
    //Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(2, 2));
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    //morphologyEx(greyScale, greyScale , MORPH_OPEN, kernel);
    morphologyEx(greyScale, greyScale ,MORPH_CLOSE, kernel, Point(-1,-1), 2);

    //origianl 3rd value = 20
    adaptiveThreshold(greyScale, greyScale, 10, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 5, 0);

    findContours(greyScale, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
    drawContours(frame, contours, -1, (0, 255, 0), 3);
    //imshow("contours", contours);
}

//BASED ON:
//https://stackoverflow.com/questions/24916870/python-opencv-rubiks-cube-solver-color-extraction
void AcubeDetector::DoContours2()
{
    cvtColor(frame, HSV, COLOR_BGR2HSV);
    
    contoursMask = Mat::zeros(size, CV_8UC3);

    /*for (size_t i = 0; i < searchedColours.size(); i++)
    {
        
        inRange(HSV, searchedColours[i].lower, searchedColours[i].upper, colourMask);
        morphologyEx(colourMask, colourMaskOpen, MORPH_OPEN, open_kernel, Point(-1, -1), 1);
        morphologyEx(colourMaskOpen, colourMaskClose, MORPH_CLOSE, close_kernel, Point(-1, -1), 5);
        vector<Mat> channels;
        channels.push_back(colourMaskClose);
        channels.push_back(colourMaskClose);
        channels.push_back(colourMaskClose);
        merge(channels, colourMask);
        //threshold(colourMask, colourMask, 0, 255.0, THRESH_BINARY);
        //UE_LOG(LogTemp, Warning, TEXT("ColourMask Channels: %d"), colourMask.channels());
        //UE_LOG(LogTemp, Warning, TEXT("contoursMask Channels: %d"), contoursMask.channels());
        bitwise_or(contoursMask, colourMask, contoursMask);
        //searchedColours[i]
    }//*/
    
    inRange(HSV, Scalar(getTrackbarPos("HMin", "image"), getTrackbarPos("SMin", "image"), getTrackbarPos("VMin", "image")), Scalar(getTrackbarPos("HMax", "image"), getTrackbarPos("SMax", "image"), getTrackbarPos("VMax", "image")), colourMask);
    morphologyEx(colourMask, colourMaskOpen, MORPH_OPEN, open_kernel, Point(-1, -1), 1);
    morphologyEx(colourMaskOpen, colourMaskClose, MORPH_CLOSE, close_kernel, Point(-1, -1), 5);
    vector<Mat> channels;
    channels.push_back(colourMaskClose);
    channels.push_back(colourMaskClose);
    channels.push_back(colourMaskClose);
    merge(channels, colourMask);
    bitwise_or(contoursMask, colourMask, contoursMask);
    //searchedColours[i]//*/

    cvtColor(contoursMask, contoursMask, COLOR_BGR2GRAY);
    findContours(contoursMask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(frame, contours, -1, Scalar(0, 0, 255), 3);

    //imshow("HSV", contoursMask);
    //imshow("HSV2", HSV);
}
//BASED ON:
//https://github.com/VickneshB/RubiksCube/blob/master/main.py
void AcubeDetector::DoContours3()
{
    Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2)); //MORPH_ELLIPSE
    morphologyEx(greyScale, greyScale , MORPH_OPEN, kernel);
    morphologyEx(greyScale, greyScale, MORPH_CLOSE, kernel);//, Point(-1, -1), 2);

    //origianl 3rd value = 20 // 40 WAS A NICE VAL
    adaptiveThreshold(greyScale, greyScale, 30, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 1);//5, 0);
    //threshold(greyScale, greyScale, 160, 255, THRESH_BINARY_INV);
    //imshow("thershold", greyScale);

    findContours(greyScale, contours, RETR_CCOMP, CHAIN_APPROX_NONE);

    //std::vector<std::vector<Point>> hull;
    //hull.resize(contours.size());
    while (!hull.empty())
    {
        hull.pop_back();
    }

    while (!largeContours.empty())
    {
        largeContours.pop_back();
    }

    paralleRects.Empty();

    for (size_t i = 0; i < contours.size(); i++) {
        area = contourArea(contours[i]);
        
        if (area > 1000 && area < 15000) { // would have to add scaling based on image size
            perimeter = arcLength(contours[i], true);
            epsilon = 0.1 * perimeter;
            approxPolyDP(contours[i], approx, epsilon, true);
            //convexHull(contours[i], newHull);
            //perimeter = arcLength(newHull, true);
            //area = contourArea(newHull);
            //hull.push_back(contours[i]);
            //drawContours(frame, hull, (int)i, Scalar(0, 0, 255),3);
            rect = minAreaRect(contours[i]);

            rect.points(rectPoints);

            /*//DRAW RECTANGLES
            line(frame, rectPoints[0], rectPoints[1], Scalar(0, 255, 0));
            line(frame, rectPoints[1], rectPoints[2], Scalar(0, 255, 0));
            line(frame, rectPoints[2], rectPoints[3], Scalar(0, 255, 0));
            line(frame, rectPoints[3], rectPoints[0], Scalar(0, 255, 0));//*/

            //UE_LOG(LogTemp, Warning, TEXT("Angle: %f"), rect.angle);


            //boxPoints(rect, );
            //rects.push_back(*rectPoints);
            //rectPoints->


            //CHECK if bound rect is square
            if (norm(rect.size.height - rect.size.width) < 30) { // if square shaped
                largeContours.push_back(contours[i]);

                bool found = false;
                for (auto& Elem : paralleRects)
                {
                    if (Elem.Key > rect.angle - 6 && Elem.Key < rect.angle + 6)
                    {
                        Elem.Value.Add(rect);
                        found = true;
                    }

                }
                if (!found) {
                    TArray<cv::RotatedRect> newVector;
                    newVector.Add(rect);
                    paralleRects.Add(rect.angle, newVector);
                }//*/
            }



            //if (norm(((perimeter / 4) * (perimeter / 4)) - area) < 100) {//150) { // is this square shaped
                //hull.push_back(newHull);
                //rect = boundingRect(contours[i]);
                //drawContours(frame, contours, (int)i, Scalar(255, 0, 0), 2);
                //drawContours(frame, approx, 0, Scalar(0, 0, 255), 2);
                //drawContours(frame, hull, (int)i, Scalar(0, 255, 0), 1);

                //UE_LOG(LogTemp, Warning, TEXT("Area: %f"), area);
                //UE_LOG(LogTemp, Warning, TEXT("Squareness: %f"), norm(((perimeter / 4) * (perimeter / 4)) - area));

            //}
        }
    }//*/
    //drawContours(frame, hull, -1, Scalar(0, 0, 255),3);
    //drawContours(frame, largeContours, -1, Scalar(255, 0, 0));
    //drawContours(frame, hull, -1, Scalar(0, 0, 255), 3);

    for (auto& Elem : paralleRects)
    {
        
        //if (norm(rect.size.height - rect.size.width) < 30) { // if square shaped
        if (Elem.Value.Num() >= 9) {
            pointsOfRects.clear();
            //Scalar colour = Scalar(rand() % 256, rand() % 256, rand() % 256); // random colour0
            TMap <float, TArray<cv::RotatedRect>> groupByArea;
            //float elemArea = Elem.Value[0].size.height * ;
            for (int i = 0; i < Elem.Value.Num(); i++)
            {
                bool found = false;
                float elemArea = Elem.Value[i].size.height * Elem.Value[i].size.width;
                for (auto& areaMap : groupByArea)
                {
                    if (areaMap.Key > elemArea - 250 && areaMap.Key < elemArea + 250)
                    {
                        areaMap.Value.Add(Elem.Value[i]);
                        found = true;
                    }

                }
                if (!found) {
                    TArray<cv::RotatedRect> newVector;
                    newVector.Add(Elem.Value[i]);
                    groupByArea.Add(elemArea, newVector);
                }//
            }

            UE_LOG(LogTemp, Warning, TEXT("Frame__________________________________________"));
            for (auto& curRects : groupByArea)
            {
                // Draw the lines
                //UE_LOG(LogTemp, Warning, TEXT("Groupsize: %d"), curRects.Value.Num());

                Scalar colour = Scalar(rand() % 256, rand() % 256, rand() % 256);
                //if (norm(rect.size.height - rect.size.width) < 30) { // if square shaped
                //if (curRects.Value.Num() >= 9) {
                    for (int i = 0; i < curRects.Value.Num(); i++)
                    {

                        curRects.Value[i].points(rectPoints);

                        //DRAW RECTANGLES
                        line(frame, rectPoints[0], rectPoints[1], colour);
                        line(frame, rectPoints[1], rectPoints[2], colour);
                        line(frame, rectPoints[2], rectPoints[3], colour);
                        line(frame, rectPoints[3], rectPoints[0], colour);//

                        //pointsOfRects.
                        
                        //unsigned dataArraySize = sizeof(rectPoints) / sizeof(Point2f);
                        pointsOfRects.insert(pointsOfRects.end(), &rectPoints[0], &rectPoints[4]);
                        

                        //circle(frame, Elem.Value[i].center, 10, colour, -1);
                        //putText(frame, std::to_string(curRects.Value[i].angle), curRects.Value[i].center, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 3);

                        /*
                        float rho = Elem.Value[i][0], theta = Elem.Value[i][1];
                        Point pt1, pt2;
                        double a = cos(theta), b = sin(theta);
                        double x0 = a * rho, y0 = b * rho;
                        pt1.x = cvRound(x0 + 2000 * (-b));
                        pt1.y = cvRound(y0 + 2000 * (a));
                        pt2.x = cvRound(x0 - 2000 * (-b));
                        pt2.y = cvRound(y0 - 2000 * (a));
                        line(frame, pt1, pt2, colour, 3, LINE_AA);//*/
                    }

                    rect = minAreaRect(pointsOfRects);
                    rect.points(rectPoints);
                    //DRAW RECTANGLES

                    //CHECK RECTANGLE IS 
                    if (norm(rect.size.height - rect.size.width) < 10){// && (rect.size.width < Elem.Value[0].size.width * 3.05) && (rect.size.width < Elem.Value[0].size.width * 3.05)) {
                        //UE_LOG(LogTemp, Warning, TEXT("GOT TO RECT VALIDATION"));
                        //line(frame, rectPoints[0], rectPoints[1], colour, 3);
                        //line(frame, rectPoints[1], rectPoints[2], colour, 3);
                        //line(frame, rectPoints[2], rectPoints[3], colour, 3);
                        //line(frame, rectPoints[3], rectPoints[0], colour, 3);//
                        bool cubiesFound[9];
                        Point cubieCenters[9];
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                cubiesFound[(i * 3) + j] = false;
                                cubieCenters[(i * 3) + j] = rotatePoint(Point(rect.center.x +((j-1)* (rect.size.width / 3)), rect.center.y + ((i - 1) * (rect.size.height / 3))), rect.center, rect.angle>45? rect.angle-90 : rect.angle);
                                //circle(frame, cubieCenters[(i * 3) + j], 20, colour, 2);
                            }
                        }
                        for (int i = 0; i < curRects.Value.Num(); i++)
                        {
                            for (int j = 0; j < 9; j++)
                            {
                                //circle(frame, curRects.Value[i].center, 5, colour, -1);
                                if (pointWithIn(curRects.Value[i].center, cubieCenters[j], 40)) {
                                    cubiesFound[j] = true;
                                    break;
                                }
                            }
                        }
                        bool foundAll = true;
                        for (int i = 0; i < 9; i++)
                        {
                            if (!cubiesFound[i]) {
                                foundAll = false;
                                break;
                            }
                        }

                        if (foundAll)
                        {
                            UE_LOG(LogTemp, Warning, TEXT("____________________________VALID__________________________________________"));

                            //group by colour
                            FCubeFace newFace;

                            for (int i = 0; i < 9; i++)
                            {
                                //cvtColor(frame, HSV, COLOR_BGR2HSV);
                                Vec3b pixel = frame.at<Vec3b>(cubieCenters[i]);
                                
                                int b, g, r;
                                //int h, s, v;
                                /*b = pixel[0];
                                s = pixel[1];
                                v = pixel[2];//*/
                                b = pixel[0];
                                g = pixel[1];
                                r = pixel[2];
                                //UE_LOG(LogTemp, Warning, TEXT("B: %d, G: %d, R: %d"), b, g, r);
                                //circle(frame, cubieCenters[i], 7, Scalar(0, 0, 0), -1);
                                //circle(frame, cubieCenters[i], 5, Scalar(b, g, r), -1);
                                //putText(frame, std::to_string(getColourNum2(pixel)), cubieCenters[i], FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 3);

                                line(frame, rectPoints[0], rectPoints[1], colour, 3);
                                line(frame, rectPoints[1], rectPoints[2], colour, 3);
                                line(frame, rectPoints[2], rectPoints[3], colour, 3);
                                line(frame, rectPoints[3], rectPoints[0], colour, 3);//


                                newFace.coloursOfFace.Add(getColourNum2(pixel));
                            }
                            currentFace = newFace;
                            faceDetected();
                        }

                        //UE_LOG(LogTemp, Warning, TEXT("Frame_"));
                    }

                //}
            }
        }//*/



        /*if (Elem.Value.Num() >= 9) {
            Scalar colour = Scalar(rand() % 256, rand() % 256, rand() % 256); // random colour
            for (int i = 0; i < Elem.Value.Num(); i++)
            {
                
                Elem.Value[i].points(rectPoints);

                //DRAW RECTANGLES
                line(frame, rectPoints[0], rectPoints[1], colour);
                line(frame, rectPoints[1], rectPoints[2], colour);
                line(frame, rectPoints[2], rectPoints[3], colour);
                line(frame, rectPoints[3], rectPoints[0], colour);//

                //circle(frame, Elem.Value[i].center, 10, colour, -1);
                putText(frame, std::to_string(i), Elem.Value[i].center, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0), 3);

                
                /*float rho = Elem.Value[i][0], theta = Elem.Value[i][1];
                Point pt1, pt2;
                double a = cos(theta), b = sin(theta);
                double x0 = a * rho, y0 = b * rho;
                pt1.x = cvRound(x0 + 2000 * (-b));
                pt1.y = cvRound(y0 + 2000 * (a));
                pt2.x = cvRound(x0 - 2000 * (-b));
                pt2.y = cvRound(y0 - 2000 * (a));
                line(frame, pt1, pt2, colour, 3, LINE_AA);///
            }
        }//*/
    }

    //UE_LOG(LogTemp, Warning, TEXT("PAUSE: %d"), contours.size());
    //drawContours(frame, contours, -1, Scalar(0, 0, 255), 3);
}



cv::Point AcubeDetector::rotatePoint(cv::Point p1, cv::Point center, float angle)
{
    angle = angle * CV_PI / 180;
    float x2 = ((p1.x - center.x) * cos(angle)) - ((p1.y - center.y) * sin(angle)) + center.x;
    float y2 = ((p1.x - center.x) * sin(angle)) + ((p1.y - center.y) * cos(angle)) + center.y;
    return cv::Point(x2, y2);
}

bool AcubeDetector::pointWithIn(cv::Point p1, cv::Point center, float distance)
{
    //distance = distance / 2;

    if (norm(p1.x - center.x) > distance) return false;
    if (norm(p1.y - center.y) > distance) return false;
    return true;
}

bool AcubeDetector::hueInRange(int hue, int lowerBound, int upperBound)
{
    if(hue > lowerBound && upperBound > hue) return true;
    if(lowerBound > upperBound && (hue > lowerBound || upperBound > hue)) return true;
    return false;
}

int AcubeDetector::getColourNum(cv::Vec3b colour)
{
    if (colour[0] > 120 && colour[1] > 120 && colour[2] > 100) return 1;
    if (colour[0] < 100 && colour[1] > 120 && colour[2] > 120 && norm(colour[1] - colour[2]) < 30) return 2;
    if (colour[0] > colour[1] && colour[1] > colour[2]) return 3;
    if (colour[1] > colour[0] && colour[1] > colour[2] && norm(colour[0] - colour[2]) < 30) return 4;
    if (colour[2] > colour[0] && colour[2] > colour[1] && norm(colour[0] - colour[1]) < 30 && colour[0] < 80) return 5;
    if (colour[1] < colour[2] && colour[0] < colour[1] && colour[2] > 120) return 6;
    return 0;
}

int AcubeDetector::getColourNum2(cv::Vec3b colour)
{
    cv::Vec3b listOfTargetColours[6];
    //ADDCOLOURS
    /*listOfTargetColours[0] = Vec3b(150, 0, 0); //RED
    listOfTargetColours[1] = Vec3b(0, 150, 0); //GREEN
    listOfTargetColours[2] = Vec3b(0, 0, 150); //BLUE
    listOfTargetColours[3] = Vec3b(255, 70, 50); // ORANGE
    listOfTargetColours[4] = Vec3b(150, 150, 150); // WHITE
    listOfTargetColours[5] = Vec3b(150, 150, 50); // YELLOW//*/


    double distanceFromLastTarget = DBL_MAX;
    int bestTargetIndex = -1;

    
    colourBGR.at<Vec3b>(Point(0, 0)) = colour;
    cvtColor(colourBGR, colourLAB, COLOR_BGR2Lab);

    for (int i = 0; i < 6; i++)
    {
        //double currentDistance = getColourDistancEuclideanRGB(colour, colourTargets[i]);
        ////////////////////////////////////////////////////////////
        tarColourBGR.at<Vec3b>(Point(0, 0)) = Vec3b(colourTargets[i].B, colourTargets[i].G, colourTargets[i].R);
        
        cvtColor(tarColourBGR, tarColourLAB, COLOR_BGR2Lab);

        double currentDistance = getColourDistancCIEDE2000(colourLAB.at<Vec3b>(0, 0), tarColourLAB.at<Vec3b>(0,0));
        if (distanceFromLastTarget > currentDistance) {
            bestTargetIndex = i;
            distanceFromLastTarget = currentDistance;
        }
    }

    return bestTargetIndex;
}

double AcubeDetector::getColourDistancEuclideanRGB(cv::Vec3b colour, FColor targetColour)
{
    return getColourDistancEuclideanRGB(colour, Vec3b(targetColour.R, targetColour.G, targetColour.B));
}

double AcubeDetector::getColourDistancEuclideanRGB(cv::Vec3b colour, cv::Vec3b targetColour)
{
    return std::sqrt(((targetColour[0]- colour[0])* (targetColour[0] - colour[0]))+ ((targetColour[1] - colour[1]) * (targetColour[1] - colour[1])) + ((targetColour[2] - colour[2]) * (targetColour[2] - colour[2])));
}

double AcubeDetector::getColourDistancCIEDE2000(cv::Vec3b colour, cv::Vec3b targetColour)
{
    int L = 0, a = 1, b = 2;

    double L_ = colour[L] - targetColour[L];
    double a_ = colour[a] - targetColour[a];
    double b_ = colour[b] - targetColour[b];
    double C1 = std::sqrt((colour[a] * colour[a]) + (colour[b] * colour[b]));
    double C2 = std::sqrt((targetColour[a] * targetColour[a]) + (targetColour[b] * targetColour[b]));

    double C_ab = C1 - C2;

    double H_ab = std::sqrt((a_ * a_));

    double K_L = 1; // 2
    double K1 = 0.045; //0.048
    double K2 = 0.015; //0.014

    double S_L = 1;

    double S_c = 1 + (K1 * C1);
    double S_h = 1 + (K2 * C1);

    // _______________2000__________________
    double L__ = targetColour[L] - colour[L];
    double L_avg = (targetColour[L] + colour[L])/2;

    double C_25_7 = 6103515625;
    double C_avg = (C1 + C2) / 2;
    double C_avg_7 = pow(C_avg, 7);
    double G = 0.5 * (1- std::sqrt(C_avg_7/ (C_avg_7*C_25_7)));

    double a1 = colour[a] + (colour[a] * G);
    double a2 = targetColour[a] + (targetColour[a] * G);

    double C_a1 = std::sqrt((a1 * a1) + (colour[b] * colour[b]));
    double C_a2 = std::sqrt((a2 * a2) + (targetColour[b] * targetColour[b]));
    double C__ = C_a2 - C_a1;

    double C__avg = (C_a1 + C_a2)/2;

    double h_1 = std::fmod(atan2(colour[b], a1) ,2*PI); // GOT TO CHANGE
    double h_2 = std::fmod(atan2(targetColour[b], a2), 2 * PI); //

    double h__;
    if (abs(h_1 - h_2) <= PI) h__ = h_2 - h_1;
    else if(abs(h_1 - h_2) > PI && h_1>=h_2) h__ = h_2 - h_1 + (2*PI);
    else if (abs(h_1 - h_2) > PI && h_1 < h_2) h__ = h_2 - h_1 - (2 * PI);
    //h_1 = h_1 % 360;
    //double H__ = 2* std::sqrt(C_a1 * C_a2);

    double H__ = 2 * std::sqrt(C_a1*C_a2) * sin(h__/2);

    double H_avg;
    if (abs(h_1 + h_2) <= 180) H_avg = (h_2 + h_1)/2;
    else if (abs(h_1 + h_2) > 180 && h_1 + h_2 < 360) H_avg = (h_2 + h_1 + 360)/2;
    else if (abs(h_1 + h_2) > 180 && h_1 + h_2 >= 360) H_avg = (h_2 + h_1 - 360)/2;

    double T_ = 1 - (0.17 * cos(H_avg - PI/6)) + (0.24 * cos(2 * H_avg)) + (0.32 * cos((3 * H_avg) + PI/30)) - (0.2 *cos((4*H_avg) - (63 * PI/180)));

    double Sl = 1 + ((0.015*pow((L_avg - 50),2))/std::sqrt(20+ pow((L_avg - 50), 2)));
    double Sc = 1 + (0.045 * C__avg);
    double Sh = 1 + (0.015 * C__avg * T_);
    double Rt = (-2*std::sqrt(pow(C__avg,7)/(pow(C__avg, 7) + C_25_7))) * sin((PI/3)*exp(-pow((H_avg-(275 * (PI/180))/2), 2)));

    int  k_L = 1, k_C = 1, k_H = 1;

    return std::sqrt(pow((L__/(k_L * Sl)), 2) + pow((C__ / (k_C * Sc)), 2) + pow((H__ / (k_H * Sh)), 2) + (Rt * (C__ / (k_C * Sc)) * (H__ / (k_H * Sh))));
}

//cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE
