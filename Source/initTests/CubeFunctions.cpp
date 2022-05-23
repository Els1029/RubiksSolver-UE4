// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeFunctions.h"
//#include <initTests/Kociemba/utils.cpp>
//#include "../../Include/Win64/Kociemba/search.h"
//#include "../include/algo.h"


//#define MIN(a, b) (((a)<(b))?(a):(b))
//#define MAX(a, b) (((a)>(b))?(a):(b))

const uint8 UCubeFunctions::TOP[] = {0,1,2};
const uint8 UCubeFunctions::MID[] = {3,4,5};
const uint8 UCubeFunctions::BOT[] = {6,7,8};

const uint8 UCubeFunctions::LEFT[] = {0,3,6};
const uint8 UCubeFunctions::CENTER[] = {1,4,7};
const uint8 UCubeFunctions::RIGHT[] = {2,5,8};


FCubeFace UCubeFunctions::rotateFaceCW(FCubeFace inputFace)
{
    TArray<int32> oldArray = inputFace.coloursOfFace;

    if (oldArray.Num() != 9) 
    {
        return inputFace;
    }

    FCubeFace returnFace;

    int32 newFace[] = { oldArray[6], oldArray[3], oldArray[0], oldArray[7], oldArray[4], oldArray[1], oldArray[8], oldArray[5], oldArray[2] };
    returnFace.coloursOfFace.Append(newFace, UE_ARRAY_COUNT(newFace));

    return returnFace;
}

void UCubeFunctions::rotateFaceCW2(FCubeFace inputFace)
{
}

FCubeFace UCubeFunctions::rotateFaceACW(FCubeFace inputFace)
{
    TArray<int32> oldArray = inputFace.coloursOfFace;

    if (oldArray.Num() != 9)
    {
        return inputFace;
    }

    FCubeFace returnFace;

    int32 newFace[] = { oldArray[2], oldArray[5], oldArray[8], oldArray[1], oldArray[4], oldArray[7], oldArray[0], oldArray[3], oldArray[6] };
    returnFace.coloursOfFace.Append(newFace, UE_ARRAY_COUNT(newFace));

    return returnFace;
}

void UCubeFunctions::rotateFaceACW2(FCubeFace inputFace)
{
}

void UCubeFunctions::rotateCube(UPARAM(ref) FCube& inputCube, ECubeMove move)
{

    switch (move) {
    case ECubeMove::F:
        inputCube.faces[0] = rotateFaceCW(inputCube.faces[0]);

        uint8 faceOrder[4] = { 1,2,3,4 };

        uint8 faceSlices[4][4] = { *TOP, *TOP, *TOP, *TOP};

        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                UE_LOG(LogTemp, Warning, TEXT("FaceSliceTEST: %d"), faceSlices[i][j]);
            }
        }

        /*TArray<int32> bottomFace = inputCube.faces[1].coloursOfFace;
        int32 lastRow[] = { bottomFace[0], bottomFace[1], bottomFace[2] };
        TArray<int32> rightFace = inputCube.faces[2].coloursOfFace;
        
        //inputCube.faces[2].coloursOfFace


        TArray<int32> topFace = inputCube.faces[3].coloursOfFace;
        TArray<int32> leftFace = inputCube.faces[4].coloursOfFace;//*/
    }

    /*if (move != F && move != F_ && move != B || move != B_)
    {
        return;
    }
    if (move == F && move != F_ && move != B || move != B_)
    {

    }//*/
}

FString UCubeFunctions::solutionKociemba2(FCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator)
{
    //char* solution = solution();
    //create_kociemba_algo(4);
    //char* cubeString;
    //char tempString[54];

    //cubeString = (formatCubeAsString(facelets, tempString));

    //patternize("","","");

    /*cube_t cube = getCubeData(formatCube(facelets));
    //prepareSearch* prs = new prepareSearch();
    
    UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    for (uint8 i = 0; i < 8; i++) {
        //UE_LOG(LogTemp, Warning, TEXT("cp %d"), cube.cp[i]);
    }
    UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    for (uint8 i = 0; i < 8; i++) {
        //UE_LOG(LogTemp, Warning, TEXT("co %d"), cube.co[i]);
    }
    UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    for (uint8 i = 0; i < 12; i++) {
        //UE_LOG(LogTemp, Warning, TEXT("ep %d"), cube.ep[i]);
    }
    UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    for (uint8 i = 0; i < 12; i++) {
        //UE_LOG(LogTemp, Warning, TEXT("eo %d"), cube.eo[i]);
    }

    //utils* uti = new utils();

    //if(uti->cubeVerify(cube))  
    {
        //prs->solve(cube);
        UE_LOG(LogTemp, Warning, TEXT("VALID"));
    }
    //else {
        UE_LOG(LogTemp, Warning, TEXT("INVALID"));
        UE_LOG(LogTemp, Warning, TEXT("INVALID"));
        UE_LOG(LogTemp, Warning, TEXT("INVALID"));
    }//*/

    /*solution(
        "UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB",
        24,
        1000,
        0,
        "cache"
    ); //*/

    FString solutionStr("sol");

    return solutionStr;
}

FString UCubeFunctions::solutionKociemba3(FCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator)
{

    /*OptimalSolver os(8);

    Cube cube = getCubeData2(formatCube(facelets));

    //std::cout << "** Sexy **" << std::endl;
    //os.solve("R U R' U'");

    //std::cout << "** Random (16 moves) **" << std::endl;
    //os.solve("R' L2 D' R' L B2 L2 F D' U F D' L D2 R2 D");

    std::cout << "THE ACTUAL CUBE (hopefully)" << std::endl;
    os.solve(cube);//*/

    FString solutionStr("sol");

    return solutionStr;
}

FString UCubeFunctions::solutionKociemba4(FCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator)
{

    FString returnString;

    int n_threads = 1;
    int tlim = 10;
    int n_sols = 1;
    int max_len = -1;
    int n_splits = 1;
    bool compress = true;
    int n_warmups = 0;

    solve::Engine solver(n_threads, tlim, n_sols, max_len, n_splits);

    //Get cube as string

    formatCube(facelets);

    cubie::cube c;
    std::string fcube = formatCubeAsString(facelets);
    std::vector<std::vector<int>> sols;

    //std::cout << fcube << std::endl;

    int err = face::to_cubie(fcube, c);
    if (err != 0) {
        std::cout << "Face-error " << err << "." << std::endl;
        return FString("Face Error");
    }
    err = cubie::check_c(c);
    if (err != 0) {
        std::cout << "Cubie-error " << err << "." << std::endl;
        return FString("Invalid Cube");
    }

    solver.solve(c, sols);

    for (std::vector<int>& sol : sols) {
        int len = sol.size(); // always print uncompressed length
        if (compress)
        {
            std::cout << move::compress(sol) << " ";
            returnString = FString(move::compress(sol).c_str());
        }
        else {
            for (int m : sol)
                std::cout << move::names[m] << " ";
        }
        std::cout << "(" << len << ")" << std::endl;
    }

    

    solver.finish();

    return returnString;
}


/*cube_t UCubeFunctions::getCubeData(FFormatedCube inputCube)
{
    cube_t* newCube = new cube_t();

    /*for (uint8 i = 0; i < 6; i++)
    {
        for (uint8 j = 0; j < 9; j++)
        {
            UE_LOG(LogTemp, Warning, TEXT("%d"), inputCube.face_Colours[(i * 9) + j]);
        }
        UE_LOG(LogTemp, Warning, TEXT("_____________________________________________"));
    }//______________________________________________________________________________________________________


    uint8 ori;
    faceColours col1, col2;

    for (uint8 i = 0; i < 8; i++) {
        for (ori = 0; ori < 3; ori++) {
            if (inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][ori]] == faceColours::U || inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][ori]] == faceColours::D)
                break;
        }

        UE_LOG(LogTemp, Warning, TEXT("__________Corner %d___________________________________"), i);
        UE_LOG(LogTemp, Warning, TEXT("ori : %d"), ori);

        col1 = inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][(ori + 1) % 3]];
        col2 = inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][(ori + 2) % 3]];

        UE_LOG(LogTemp, Warning, TEXT("__________Corner %d___________________________________"), i);

        for (uint8 j = 0; j < 8; j++) {
            if (col1 == cubeDataStructs::cornerColour[j][1] && col2 == cubeDataStructs::cornerColour[j][2]) {
                // in cornerposition i we have cornercubie j
                newCube->cp[i] = j;
                newCube->co[i] = ori % 3;
                break;
            }
        }
    }

    for (uint8 i = 0; i < 12; i++) {
        for (uint8 j = 0; j < 12; j++) {

            if (inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][0]] == cubeDataStructs::edgeColour[j][0] &&
                inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][1]] == cubeDataStructs::edgeColour[j][1]) {
                // in cornerposition i we have cornercubie j
                newCube->ep[i] = j;
                newCube->eo[i] = 0;
                break;
            }
            if (inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][0]] == cubeDataStructs::edgeColour[j][1] &&
                inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][1]] == cubeDataStructs::edgeColour[j][0]) {
                // in cornerposition i we have cornercubie j
                newCube->ep[i] = j;
                newCube->eo[i] = 1;
                break;
            }
        }
    }


    return *newCube;
}//*/
/*Cube UCubeFunctions::getCubeData2(FFormatedCube inputCube)
{
    Cube* newCube = new Cube(8);

    FCubieCube cubieCube = formattedToCubie(inputCube);
    /*for (uint8 i = 0; i < 6; i++)
    {
        for (uint8 j = 0; j < 9; j++)
        {
            UE_LOG(LogTemp, Warning, TEXT("%d"), inputCube.face_Colours[(i * 9) + j]);
        }
        UE_LOG(LogTemp, Warning, TEXT("_____________________________________________"));
    }//______________________________________________________________________________________________________*


    Corners corners;

    corners.coState = getCornerOrientation(cubieCube);
    UE_LOG(LogTemp, Warning, TEXT("coState: %d"), corners.coState);
    corners.cpState = getCornerPermutaion(cubieCube);
    UE_LOG(LogTemp, Warning, TEXT("cpState: %d"), corners.cpState);

    newCube->corners = corners;
    
    //UE_LOG(LogTemp, Warning, TEXT("CornersDone"));

    Edges* edges = new Edges();

    std::vector<int> newPerm;
    for (int i = 0; i < cubieCube.edgePosition.Num(); i++) {
        UE_LOG(LogTemp, Warning, TEXT("ep %d"), i);
        newPerm.push_back((int)cubieCube.edgePosition[i]);
        UE_LOG(LogTemp, Warning, TEXT("val %d"), newPerm[i]);
    }
    edges->edges_perm = newPerm;

    //UE_LOG(LogTemp, Warning, TEXT("newPerm"));

    std::vector<int> newOri;
    for (int i = 0; i < cubieCube.edgeOrientation.Num(); i++) {
        UE_LOG(LogTemp, Warning, TEXT("eo %d"), i);
        newOri.push_back((int)cubieCube.edgeOrientation[i]);
        UE_LOG(LogTemp, Warning, TEXT("val %d"), newOri[i]);
    }
    edges->edges_orient = newOri;

    newCube->edges = *edges;

    //UE_LOG(LogTemp, Warning, TEXT("newPerm"));

    Edges* edges2 = new Edges();

    std::vector<int> newPerm2;
    for (int i = (cubieCube.edgePosition.Num() / 2) - 1; i >=0; i--) {
        newPerm2.push_back((uint8)cubieCube.edgePosition[(i * 2)]);
        newPerm2.push_back((uint8)cubieCube.edgePosition[(i*2)+1]);
    }
    edges2->edges_perm = newPerm2;

    std::vector<int> newOri2;
    for (int i = (cubieCube.edgeOrientation.Num() / 2) - 1; i >=0 ; i--) {
        newOri2.push_back((uint8)cubieCube.edgeOrientation[(i * 2)]);
        newOri2.push_back((uint8)cubieCube.edgeOrientation[(i * 2) + 1]);
    }
    edges2->edges_orient = newOri2;

    

    newCube->edges2 = *edges2;

    return *newCube;
}//*/

int UCubeFunctions::getCornerPermutaion(FCubieCube inputCube)
{
    int permutaion = 0;

    for (int i = 1; i < 8; i++)
    {
        int countOfLargerCorners = 0;
        for (int j = (i-1); j >= 0; j--)
        {
            if ((int)inputCube.cornerPosition[j] > i)
            {
                UE_LOG(LogTemp, Warning, TEXT("True"));
                countOfLargerCorners++;
            }
                
        }
        //permutaion += (countOfLargerCorners) * factorial(i);
    }

    return permutaion;
}
int UCubeFunctions::getCornerOrientation(FCubieCube inputCube)
{
    int orientaion =0;

    for (int i = 0; i > 7; i++)
    {
        orientaion += inputCube.cornerOrientation[i] * pow(3, (6 - i));
    }

    return orientaion;
}
std::string UCubeFunctions::formatCubeAsString(FCube inputCube)
{
    /*std::string returnStr;

    char face[] = { 'U', 'L', 'F', 'R', 'B', 'D' }; //Structure of my cube
    int faceOrder[] = { 0, 3,  2, 5, 1,   4 };//{ 0, 1,  2, 3,4,   5 }; //{ 0, 5,  2, 3,4,   1 };//{ 0, 3,  2, 4,  5, 1 };//{ 3, 4, 2, 0, 5, 1 }; //{ 0, 3, 2, 5, 1, 4 };

    TMap<int32, faceColours> colourMap;
    TMap<int32, char> charMap;

    //UE_LOG(LogTemp, Warning, TEXT("length: %d"), inputCube.faces.Num());
    //set up colour map
    for (uint8 i = 0; i < 6; i++) {
        //inputCube.faces[i].coloursOfFace[4];
        //colourMap.Add(faceOrder[inputCube.faces[i].coloursOfFace[4]], (faceColours)i); //Set
        UE_LOG(LogTemp, Warning, TEXT("Loop_____________ %d"), i);
        UE_LOG(LogTemp, Warning, TEXT("Colour %d"), inputCube.faces[faceOrder[i]].coloursOfFace[4]);
        UE_LOG(LogTemp, Warning, TEXT("Side %s"), new FString(face[i]));
        charMap.Add(inputCube.faces[faceOrder[i]].coloursOfFace[4], face[i]);
        //charMap.Add(i, face[i]);
    }

    for (int i = 0; i < 6; i++) {
        //UE_LOG(LogTemp, Warning, TEXT("FACE %d"), i);
        for (int j = 0; j < 9; j++) {
            returnStr.push_back(face[(uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j])]);
            //returnStr.push_back(*charMap.Find(inputCube.faces[i].coloursOfFace[j]));
            //UE_LOG(LogTemp, Warning, TEXT("Cube: %s"), returnStr.c_str());
            //formatedCube.face_Colours.Add((faceColours)(uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]));
            //UE_LOG(LogTemp, Warning, TEXT("Colour %d"), (uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]));

            //formatedCube.face_Colours.Add((faceColours)(uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]));
            UE_LOG(LogTemp, Warning, TEXT("Colour %d"), (uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]));
        }
        //UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    }

    //UE_LOG(LogTemp, Warning, TEXT("Cube: %s") , returnStr.c_str());

    //UE_LOG(LogTemp, Warning, TEXT("Cube: %s"), TCHAR_TO_UTF8(*returnFstring));
    std::cout << returnStr << std::endl;
    return returnStr;//*/

    std::string returnStr;

    char face[] = { 'U', 'L', 'F', 'R', 'B', 'D' }; //Structure of my cube

    FFormatedCube formatedCube;

    TMap<int32, faceColours> colourMap;

    //UE_LOG(LogTemp, Warning, TEXT("length: %d"), inputCube.faces.Num());
    //set up colour map
    for (uint8 i = 0; i < 6; i++) {
        //inputCube.faces[i].coloursOfFace[4];
        colourMap.Add(inputCube.faces[i].coloursOfFace[4], (faceColours)i);
    }

    int faceOrder[] = { 0, 3,  2, 5, 1,   4 }; // face order of cubes

    for (int i = 0; i < 6; i++) {
        //This bit is needed as the cube detection is working off of a rotated cube but the faces are not rotated
        FCubeFace curFace;
        if (faceOrder[i] == 0) //U
            curFace = inputCube.faces[faceOrder[i]];
        else if (faceOrder[i] == 5) { //D needs rotating CW
            curFace = rotateFaceCW(inputCube.faces[faceOrder[i]]);
        }
        else { //Rest needs rotating ACW 
            curFace = rotateFaceACW(inputCube.faces[faceOrder[i]]);
        }

        for (int j = 0; j < 9; j++) {
            returnStr.push_back(face[(uint8)*colourMap.Find(curFace.coloursOfFace[j])]);
            //formatedCube.face_Colours.Add((faceColours)(uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]));
            //UE_LOG(LogTemp, Warning, TEXT("Colour %d"), (uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]));
        }
        //UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    }

    std::cout << returnStr << std::endl;
    return returnStr;

}
//*/

/*char* UCubeFunctions::formatCubeAsString(FCube inputCube, char* string)
{
    //FFormatedCube formatedCube;
    //char cubeString[54] = {0};

    TMap<int32, faceColours> colourMap;

    //set up colour map
    for (uint8 i = 0; i < 6; i++) {
        //inputCube.faces[i].coloursOfFace[4];
        colourMap.Add(inputCube.faces[i].coloursOfFace[4], (faceColours)i);
    }
    //UEnum::GetDisplayValueAsText(Notification).ToString()
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            string[(i * 9) + j] = UEnum::GetDisplayValueAsText((faceColours)(uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j])).ToString().GetCharArray()[0];
        }
    }

    return string;
}//*/

FFormatedCube UCubeFunctions::formatCube(FCube inputCube)
{
    FFormatedCube formatedCube;

    TMap<int32, faceColours> colourMap;

    //UE_LOG(LogTemp, Warning, TEXT("length: %d"), inputCube.faces.Num());
    //set up colour map
    for (uint8 i = 0; i < 6; i++) {
        //inputCube.faces[i].coloursOfFace[4];
        colourMap.Add(inputCube.faces[i].coloursOfFace[4], (faceColours) i);
    }

    for (int i = 0; i < 6; i++) {
        UE_LOG(LogTemp, Warning, TEXT("FACE %d"), i);
        for (int j = 0; j < 9; j++) {
            formatedCube.face_Colours.Add((faceColours)(uint8) *colourMap.Find(inputCube.faces[i].coloursOfFace[j]));
            //std::cout << TCHAR_TO_UTF8(*UEnum::GetDisplayValueAsText((faceColours)(uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]))) << std::endl;
            UE_LOG(LogTemp, Warning, TEXT("Colour %d"), (uint8)*colourMap.Find(inputCube.faces[i].coloursOfFace[j]));
        }
        UE_LOG(LogTemp, Warning, TEXT("____________________________________________________"));
    }

    return formatedCube;
}

FCubieCube UCubeFunctions::formattedToCubie(FFormatedCube inputCube)
{
    FCubieCube newCube;

    newCube.cornerPosition.SetNum(8);
    newCube.cornerOrientation.SetNum(8);

    newCube.edgePosition.SetNum(12);
    newCube.edgeOrientation.SetNum(12);

    uint8 ori;
    faceColours col1, col2;

    for (uint8 i = 0; i < 8; i++) {
        for (ori = 0; ori < 3; ori++) {
            if (inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][ori]] == faceColours::U || inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][ori]] == faceColours::D)
                break;
        }

        col1 = inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][(ori + 1) % 3]];
        col2 = inputCube.face_Colours[(uint8)cubeDataStructs::cornerFacelet[i][(ori + 2) % 3]];

        for (uint8 j = 0; j < 8; j++) {
            if (col1 == cubeDataStructs::cornerColour[j][1] && col2 == cubeDataStructs::cornerColour[j][2]) {
                // in cornerposition i we have cornercubie j
                newCube.cornerPosition[i] = (cornerPieces) j;
                newCube.cornerOrientation[i] = ori % 3;
                break;
            }
        }
    }

    for (uint8 i = 0; i < 12; i++) {
        for (uint8 j = 0; j < 12; j++) {

            if (inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][0]] == cubeDataStructs::edgeColour[j][0] &&
                inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][1]] == cubeDataStructs::cornerColour[j][1]) {
                // in cornerposition i we have cornercubie j
                newCube.edgePosition[i] = (edgePieces) j;
                newCube.edgeOrientation[i] = false;
                break;
            }
            if (inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][0]] == cubeDataStructs::edgeColour[j][1] &&
                inputCube.face_Colours[(uint8)cubeDataStructs::edgeFacelet[i][1]] == cubeDataStructs::cornerColour[j][0]) {
                // in cornerposition i we have cornercubie j
                newCube.edgePosition[i] = (edgePieces)j;
                newCube.edgeOrientation[i] = true;
                break;
            }
        }
    }


    return newCube;
}
FCoordCube UCubeFunctions::CubieToCoord(FCubieCube inputCube)
{
    FCoordCube* result = new FCoordCube;

    result->twist = cubeDataStructs::getTwist(&inputCube);
    result->flip = cubeDataStructs::getFlip(&inputCube);
    result->parity = cubeDataStructs::cornerParity(&inputCube);
    result->FRtoBR = cubeDataStructs::getFRtoBR(&inputCube);
    result->URFtoDLF = cubeDataStructs::getURFtoDLF(&inputCube);
    result->URtoUL = cubeDataStructs::getURtoUL(&inputCube);
    result->UBtoDF = cubeDataStructs::getUBtoDF(&inputCube);
    result->URtoDF = cubeDataStructs::getURtoDF(&inputCube);// only needed in phase2

    return *result;
}


/*TArray<ECubeMove> UCubeFunctions::solutionKociemba(FCubieCube facelets, int32 maxDepth, int32 timeOut, int32 useSeparator)
{
    FSolution* search = new FSolution;
    FCoordCube cC = CubieToCoord(facelets);
    FCoordCube* c = &cC;

    int32 s;
    int32 mv, n;
    int32 busy;
    int32 depthPhase1;
    //time_t tStart;
    // +++++++++++++++++++++check for wrong input +++++++++++++++++++++++++++++
    /*int count[6] = {0};


    for (i = 0; i < 54; i++)
        switch (facelets[i]) {
        case 'U':
            count[U]++;
            break;
        case 'R':
            count[R]++;
            break;
        case 'F':
            count[F]++;
            break;
        case 'D':
            count[D]++;
            break;
        case 'L':
            count[L]++;
            break;
        case 'B':
            count[B]++;
            break;
        }

    for (i = 0; i < 6; i++)
        if (count[i] != 9) {
            free(search);
            return NULL;
        }

    fc = get_facecube_fromstring(facelets);
    cc = toCubieCube(fc);
    if ((s = verify(cc)) != 0) {
        free(search);
        return NULL;
    }

    // +++++++++++++++++++++++ initialization +++++++++++++++++++++++++++++++++
    //c = (cc);

    search->po[0] = 0;
    search->ax[0] = 0;
    search->flip[0] = c->flip;
    search->twist[0] = c->twist;
    search->parity[0] = c->parity;
    search->slice[0] = c->FRtoBR / 24;
    search->URFtoDLF[0] = c->URFtoDLF;
    search->FRtoBR[0] = c->FRtoBR;
    search->URtoUL[0] = c->URtoUL;
    search->UBtoDF[0] = c->UBtoDF;

    search->minDistPhase1[1] = 1;// else failure for depth=1, n=0
    mv = 0;
    n = 0;
    busy = 0;
    depthPhase1 = 1;

    //tStart = time(NULL);

    // +++++++++++++++++++ Main loop ++++++++++++++++++++++++++++++++++++++++++
    do {
        do {
            if ((depthPhase1 - n > search->minDistPhase1[n + 1]) && !busy) {

                if (search->ax[n] == 0 || search->ax[n] == 3)// Initialize next move
                    search->ax[++n] = 1;
                else
                    search->ax[++n] = 0;
                search->po[n] = 1;
            }
            else if (++search->po[n] > 3) {
                do {// increment axis
                    if (++search->ax[n] > 5) {

                        //if (time(NULL) - tStart > timeOut)
                            //return *(new TArray<ECubeMove>);// NULL;

                        if (n == 0) {
                            if (depthPhase1 >= maxDepth)
                                return *(new TArray<ECubeMove>);// NULL;
                            else {
                                depthPhase1++;
                                search->ax[n] = 0;
                                search->po[n] = 1;
                                busy = 0;
                                break;
                            }
                        }
                        else {
                            n--;
                            busy = 1;
                            break;
                        }

                    }
                    else {
                        search->po[n] = 1;
                        busy = 0;
                    }
                } while (n != 0 && (search->ax[n - 1] == search->ax[n] || search->ax[n - 1] - 3 == search->ax[n]));
            }
            else
                busy = 0;
        } while (busy);

        // +++++++++++++ compute new coordinates and new minDistPhase1 ++++++++++
        // if minDistPhase1 =0, the H subgroup is reached
        mv = 3 * search->ax[n] + search->po[n] - 1;
        search->flip[n + 1] = cubeDataStructs::flipMove[search->flip[n]][mv];
        search->twist[n + 1] = cubeDataStructs::twistMove[search->twist[n]][mv];
        search->slice[n + 1] = cubeDataStructs::FRtoBR_Move[search->slice[n] * 24][mv] / 24;
        search->minDistPhase1[n + 1] = fmax(
            cubeDataStructs::getPruning(cubeDataStructs::Slice_Flip_Prun, N_SLICE1 * search->flip[n + 1] + search->slice[n + 1]),
            cubeDataStructs::getPruning(cubeDataStructs::Slice_Twist_Prun, N_SLICE1 * search->twist[n + 1] + search->slice[n + 1])
        );
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        // System.out.format("%d %d\n", n, depthPhase1);
        if (search->minDistPhase1[n + 1] == 0 && n >= depthPhase1 - 5) {
            search->minDistPhase1[n + 1] = 10;// instead of 10 any value >5 is possible
            if (n == depthPhase1 - 1 && (s = totalDepth(*search, depthPhase1, maxDepth)) >= 0) {
                if (s == depthPhase1
                    || (search->ax[depthPhase1 - 1] != search->ax[depthPhase1] && search->ax[depthPhase1 - 1] != search->ax[depthPhase1] + 3)) {
                    TArray<ECubeMove> res;
                    if (useSeparator) {
                        res = solutionToString(*search, s, depthPhase1);
                    }
                    else {
                        res = solutionToString(*search, s, -1);
                    }
                    free((void*)search);
                    return res;
                }
            }

        }
    } while (1);
}//*/

TArray<ECubeMove> UCubeFunctions::solutionToString(FSolution search, int32 length, int32 depthPhase1)
{
    TArray<ECubeMove> s;
    int32 cur = 0, i;
    for (i = 0; i < length; i++) {
        switch (search.ax[i]) {
        case 0:
            s.Add((ECubeMove)((int32)ECubeMove::U + (search.po[i] - 1)));
            break;
        case 1:
            s.Add((ECubeMove)((int32)ECubeMove::R + (search.po[i] - 1)));
            break;
        case 2:
            s.Add((ECubeMove)((int32)ECubeMove::F + (search.po[i] - 1)));
            break;
        case 3:
            s.Add((ECubeMove)((int32)ECubeMove::D + (search.po[i] - 1)));
            break;
        case 4:
            s.Add((ECubeMove)((int32)ECubeMove::L + (search.po[i] - 1)));
            break;
        case 5:
            s.Add((ECubeMove)((int32)ECubeMove::B + (search.po[i] - 1)));
            break;
        }
    }
    return s;
}


int32 UCubeFunctions::totalDepth(FSolution search, int32 depthPhase1, int32 maxDepth)
{
    //int32 mv = 0, d1 = 0, d2 = 0, i;
    /*int32 maxDepthPhase2 = MIN(10, maxDepth - depthPhase1);// Allow only max 10 moves in phase2
    int32 depthPhase2;
    int32 n;
    int32 busy;
    for (i = 0; i < depthPhase1; i++) {
        mv = 3 * search.ax[i] + search.po[i] - 1;
        // System.out.format("%d %d %d %d\n", i, mv, ax[i], po[i]);
        search.URFtoDLF[i + 1] = cubeDataStructs::URFtoDLF_Move[search.URFtoDLF[i]][mv];
        search.FRtoBR[i + 1] = cubeDataStructs::FRtoBR_Move[search.FRtoBR[i]][mv];
        search.parity[i + 1] = cubeDataStructs::parityMove[search.parity[i]][mv];
    }

    if ((d1 = cubeDataStructs::getPruning(cubeDataStructs::Slice_URFtoDLF_Parity_Prun,
        (N_SLICE2 * search.URFtoDLF[depthPhase1] + search.FRtoBR[depthPhase1]) * 2 + search.parity[depthPhase1])) > maxDepthPhase2)
        return -1;

    for (i = 0; i < depthPhase1; i++) {
        mv = 3 * search.ax[i] + search.po[i] - 1;
        search.URtoUL[i + 1] = cubeDataStructs::URtoUL_Move[search.URtoUL[i]][mv];
        search.UBtoDF[i + 1] = cubeDataStructs::UBtoDF_Move[search.UBtoDF[i]][mv];
    }
    search.URtoDF[depthPhase1] = cubeDataStructs::MergeURtoULandUBtoDF[search.URtoUL[depthPhase1]][search.UBtoDF[depthPhase1]];

    if ((d2 = cubeDataStructs::getPruning(cubeDataStructs::Slice_URtoDF_Parity_Prun,
        (N_SLICE2 * search.URtoDF[depthPhase1] + search.FRtoBR[depthPhase1]) * 2 + search.parity[depthPhase1])) > maxDepthPhase2)
        return -1;

    if ((search.minDistPhase2[depthPhase1] = MAX(d1, d2)) == 0)// already solved
        return depthPhase1;

    // now set up search

    depthPhase2 = 1;
    n = depthPhase1;
    busy = 0;
    search.po[depthPhase1] = 0;
    search.ax[depthPhase1] = 0;
    search.minDistPhase2[n + 1] = 1;// else failure for depthPhase2=1, n=0
    // +++++++++++++++++++ end initialization +++++++++++++++++++++++++++++++++
    do {
        do {
            if ((depthPhase1 + depthPhase2 - n > search.minDistPhase2[n + 1]) && !busy) {

                if (search.ax[n] == 0 || search.ax[n] == 3)// Initialize next move
                {
                    search.ax[++n] = 1;
                    search.po[n] = 2;
                }
                else {
                    search.ax[++n] = 0;
                    search.po[n] = 1;
                }
            }
            else if ((search.ax[n] == 0 || search.ax[n] == 3) ? (++search.po[n] > 3) : ((search.po[n] = search.po[n] + 2) > 3)) {
                do {// increment axis
                    if (++search.ax[n] > 5) {
                        if (n == depthPhase1) {
                            if (depthPhase2 >= maxDepthPhase2)
                                return -1;
                            else {
                                depthPhase2++;
                                search.ax[n] = 0;
                                search.po[n] = 1;
                                busy = 0;
                                break;
                            }
                        }
                        else {
                            n--;
                            busy = 1;
                            break;
                        }

                    }
                    else {
                        if (search.ax[n] == 0 || search.ax[n] == 3)
                            search.po[n] = 1;
                        else
                            search.po[n] = 2;
                        busy = 0;
                    }
                } while (n != depthPhase1 && (search.ax[n - 1] == search.ax[n] || search.ax[n - 1] - 3 == search.ax[n]));
            }
            else
                busy = 0;
        } while (busy);
        // +++++++++++++ compute new coordinates and new minDist ++++++++++
        mv = 3 * search.ax[n] + search.po[n] - 1;

        search.URFtoDLF[n + 1] = cubeDataStructs::URFtoDLF_Move[search.URFtoDLF[n]][mv];
        search.FRtoBR[n + 1] = cubeDataStructs::FRtoBR_Move[search.FRtoBR[n]][mv];
        search.parity[n + 1] = cubeDataStructs::parityMove[search.parity[n]][mv];
        search.URtoDF[n + 1] = cubeDataStructs::URtoDF_Move[search.URtoDF[n]][mv];

        search.minDistPhase2[n + 1] = fmax(cubeDataStructs::getPruning(cubeDataStructs::Slice_URtoDF_Parity_Prun, (N_SLICE2
            * search.URtoDF[n + 1] + search.FRtoBR[n + 1])
            * 2 + search.parity[n + 1]), cubeDataStructs::getPruning(cubeDataStructs::Slice_URFtoDLF_Parity_Prun, (N_SLICE2
                * search.URFtoDLF[n + 1] + search.FRtoBR[n + 1])
                * 2 + search.parity[n + 1]));
        // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    } while (search.minDistPhase2[n + 1] != 0);//*/
    return 0;//depthPhase1 + depthPhase2;
}

void UCubeFunctions::initData()
{
    face::init();
    move::init();
    coord::init();
    sym::init();
    if (prun::init(true)) {
        std::cout << "Error." << std::endl;
        exit(1);
    }
}

//*/
