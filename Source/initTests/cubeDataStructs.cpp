// Fill out your copyright notice in the Description page of Project Settings.

#include "cubeDataStructs.h"


/*int32 cubeDataStructs::twistMove[N_TWIST][N_MOVE];
int32 cubeDataStructs::flipMove[N_FLIP][N_MOVE];

int32 cubeDataStructs::FRtoBR_Move[N_FRtoBR][N_MOVE];
int32 cubeDataStructs::URFtoDLF_Move[N_URFtoDLF][N_MOVE];
int32 cubeDataStructs::URtoDF_Move[N_URtoDF][N_MOVE];

int32 cubeDataStructs::URtoUL_Move[N_URtoUL][N_MOVE];
int32 cubeDataStructs::UBtoDF_Move[N_UBtoDF][N_MOVE];
int32 cubeDataStructs::MergeURtoULandUBtoDF[336][336];

int32 cubeDataStructs::Slice_URFtoDLF_Parity_Prun[N_SLICE2 * N_URFtoDLF * N_PARITY / 2];
int32 cubeDataStructs::Slice_URtoDF_Parity_Prun[N_SLICE2 * N_URtoDF * N_PARITY / 2];
int32 cubeDataStructs::Slice_Twist_Prun[N_SLICE1 * N_TWIST / 2 + 1];
int32 cubeDataStructs::Slice_Flip_Prun[N_SLICE1 * N_FLIP / 2];

const int32 cubeDataStructs::parityMove[2][18] = {
    { 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
    { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 }
};//*/


const Facelet cubeDataStructs::cornerFacelet[8][3] = { 
    /*{Facelet::U3, Facelet::R1, Facelet::F3},  //U9
    {Facelet::U9, Facelet::F1, Facelet::L3},  //U7
    {Facelet::U7, Facelet::L1, Facelet::B3},  //U1
    {Facelet::U1, Facelet::B1, Facelet::R3},  //U3

    {Facelet::D7, Facelet::F9, Facelet::R7},//D3 
    {Facelet::D9, Facelet::L9, Facelet::F7}, //D1
    {Facelet::D3, Facelet::B9, Facelet::L7}, //D7
    {Facelet::D1, Facelet::R9, Facelet::B7},  //D9*/

    /*{Facelet::U9, Facelet::R3, Facelet::F9},  //U9
    {Facelet::U3, Facelet::B3, Facelet::R9},  //U3
    {Facelet::U1, Facelet::L3, Facelet::B9},  //U1
    {Facelet::U7, Facelet::F3, Facelet::L9},  //U7

    {Facelet::D1, Facelet::F7, Facelet::R1},//D3 
    {Facelet::D7, Facelet::L7, Facelet::F1}, //D1
    {Facelet::D9, Facelet::B7, Facelet::L1}, //D7
    {Facelet::D3, Facelet::R7, Facelet::B1}, //D9*/

    {Facelet::U1, Facelet::L3, Facelet::B9},  //U1
    {Facelet::U3, Facelet::B3, Facelet::R9},  //U3
    {Facelet::U9, Facelet::R3, Facelet::F9},  //U9
    {Facelet::U7, Facelet::F3, Facelet::L9},  //U7

    {Facelet::D9, Facelet::B7, Facelet::L1}, //D7
    {Facelet::D3, Facelet::R7, Facelet::B1}, //D9
    {Facelet::D1, Facelet::F7, Facelet::R1},//D3
    {Facelet::D7, Facelet::L7, Facelet::F1}, //D1//*/
    
};

const faceColours cubeDataStructs::cornerColour[8][3] = {

    /*{faceColours::U, faceColours::R, faceColours::F},
    { faceColours::U, faceColours::B, faceColours::R },
    { faceColours::U, faceColours::L, faceColours::B },
    { faceColours::U, faceColours::F, faceColours::L },

    { faceColours::D, faceColours::F, faceColours::R },
    { faceColours::D, faceColours::L, faceColours::F },
    { faceColours::D, faceColours::B, faceColours::L },
    { faceColours::D, faceColours::R, faceColours::B },//*/


    {faceColours::U, faceColours::L, faceColours::B},
    { faceColours::U, faceColours::B, faceColours::R },
    { faceColours::U, faceColours::R, faceColours::F },
    { faceColours::U, faceColours::F, faceColours::L },

    { faceColours::D, faceColours::B, faceColours::L },
    { faceColours::D, faceColours::R, faceColours::B },
    { faceColours::D, faceColours::F, faceColours::R },
    { faceColours::D, faceColours::L, faceColours::F },//*/
};

const Facelet cubeDataStructs::edgeFacelet[12][2] = { 
    /*{Facelet::U2, Facelet::R2},//U6
    { Facelet::U6, Facelet::F2 }, //U8
    { Facelet::U8, Facelet::L2 },//U4
    { Facelet::U4, Facelet::B2 },//U2
    
    { Facelet::D8, Facelet::F8 },//D2
    { Facelet::D6, Facelet::L8 },//D4
    { Facelet::D2, Facelet::B8 },//D8
    { Facelet::D4, Facelet::R8 },//D6

    { Facelet::F6, Facelet::R4 },
    { Facelet::F4, Facelet::L6 },
    { Facelet::B6, Facelet::L4 },
    { Facelet::B4, Facelet::R6 } //*/

    /*{Facelet::U8, Facelet::F6},//U4
    { Facelet::U6, Facelet::R6 }, //U8
    { Facelet::U2, Facelet::B6 },//U6
    { Facelet::U4, Facelet::L6 },//U2


    { Facelet::D4, Facelet::F4 },//D6
    { Facelet::D2, Facelet::R4 },//D8
    { Facelet::D6, Facelet::B4 },//D4
    { Facelet::D8, Facelet::L4 },//D2
    

    { Facelet::F8, Facelet::R2 },
    { Facelet::F2, Facelet::L8 },
    { Facelet::B2, Facelet::R8 },
    { Facelet::B8, Facelet::L2 },//*/

    {Facelet::U2, Facelet::B6},//U6
    { Facelet::U6, Facelet::R6 }, //U8
    {Facelet::U8, Facelet::F6},//U4
    { Facelet::U4, Facelet::L6 },//U2

    { Facelet::B8, Facelet::L2 },
    { Facelet::B2, Facelet::R8 },
    { Facelet::F8, Facelet::R2 },
    { Facelet::F2, Facelet::L8 },

    { Facelet::D6, Facelet::B4 },//D4
    { Facelet::D2, Facelet::R4 },//D8
    { Facelet::D4, Facelet::F4 },//D6
    { Facelet::D8, Facelet::L4 },//D2//*/
};

const faceColours cubeDataStructs::edgeColour[12][2] = {

    /*{faceColours::U, faceColours::F},
    { faceColours::U, faceColours::R },
    { faceColours::U, faceColours::B },
    { faceColours::U, faceColours::L },

    { faceColours::D, faceColours::F },
    { faceColours::D, faceColours::R },
    { faceColours::D, faceColours::B },
    { faceColours::D, faceColours::L },

    //UDSlice
    { faceColours::F, faceColours::R },
    { faceColours::F, faceColours::L },
    { faceColours::B, faceColours::R },
    { faceColours::B, faceColours::L },//*/

    {faceColours::U, faceColours::B},
    { faceColours::U, faceColours::R },
    { faceColours::U, faceColours::F },
    { faceColours::U, faceColours::L },
    
    //UDSlice
    { faceColours::B, faceColours::L },
    { faceColours::B, faceColours::R },
    { faceColours::F, faceColours::R },
    { faceColours::F, faceColours::L },

    { faceColours::D, faceColours::B },
    { faceColours::D, faceColours::R },
    { faceColours::D, faceColours::F },
    { faceColours::D, faceColours::L },//*/
};




/*void cubeDataStructs::SetUpTables()
{
    FCubieCube* a = getSolvedCubieCube();

    FCubieCube* moveCube = getMoveCubiesCube();

    /////twist Table
    for (int32 i = 0; i < N_TWIST; i++) {
        setTwist(a, i);
        for (uint8 j = 0; j < 6; j++) {
            for (uint8 k = 0; k < 3; k++) {
                cornerMultiply(a, &moveCube[j]);
                twistMove[i][3 * j + k] = getTwist(a);
            }
            cornerMultiply(a, &moveCube[j]);// 4. faceturn restores
        }
    }

    ///Flip move
    a = getSolvedCubieCube();
    for (int32 i = 0; i < N_FLIP; i++) {
        setFlip(a, i);
        for (int32 j = 0; j < 6; j++) {
            for (int32 k = 0; k < 3; k++) {
                edgeMultiply(a, &moveCube[j]);
                flipMove[i][3 * j + k] = getFlip(a);
            }
            edgeMultiply(a, &moveCube[j]);
        }
    }

    //FRtoBR
    a = getSolvedCubieCube();
    for (int32 i = 0; i < N_FRtoBR; i++) {
        setFRtoBR(a, i);
        for (int32 j = 0; j < 6; j++) {
            for (int32 k = 0; k < 3; k++) {
                edgeMultiply(a, &moveCube[j]);
                FRtoBR_Move[i][3 * j + k] = getFRtoBR(a);
            }
            edgeMultiply(a, &moveCube[j]);
        }
    }

    //URFtoDLF
    a = getSolvedCubieCube();
    for (int32 i = 0; i < N_URFtoDLF; i++) {
        setURFtoDLF(a, i);
        for (int32 j = 0; j < 6; j++) {
            for (int32 k = 0; k < 3; k++) {
                cornerMultiply(a, &moveCube[j]);
                URFtoDLF_Move[i][3 * j + k] = getURFtoDLF(a);
            }
            cornerMultiply(a, &moveCube[j]);
        }
    }

    //URtoDF
    a = getSolvedCubieCube();
    for (int32 i = 0; i < N_URtoDF; i++) {
        setURtoDF(a, i);
        for (int32 j = 0; j < 6; j++) {
            for (int32 k = 0; k < 3; k++) {
                edgeMultiply(a, &moveCube[j]);
                URtoDF_Move[i][3 * j + k] = (short)getURtoDF(a);
                // Table values are only valid for phase 2 moves!
                // For phase 1 moves, casting to short is not possible.
            }
            edgeMultiply(a, &moveCube[j]);
        }
    }

    //URtoUL
    a = getSolvedCubieCube();
    for (int32 i = 0; i < N_URtoUL; i++) {
        setURtoUL(a, i);
        for (int32 j = 0; j < 6; j++) {
            for (int32 k = 0; k < 3; k++) {
                edgeMultiply(a, &moveCube[j]);
                URtoUL_Move[i][3 * j + k] = getURtoUL(a);
            }
            edgeMultiply(a, &moveCube[j]);
        }
    }

    //UBtoDF
    a = getSolvedCubieCube();
    for (int32 i = 0; i < N_UBtoDF; i++) {
        setUBtoDF(a, i);
        for (int32 j = 0; j < 6; j++) {
            for (int32 k = 0; k < 3; k++) {
                edgeMultiply(a, &moveCube[j]);
                UBtoDF_Move[i][3 * j + k] = getUBtoDF(a);
            }
            edgeMultiply(a, &moveCube[j]);
        }
    }

    //MergeURtoULandUBtoDF
    for (int32 uRtoUL = 0; uRtoUL < 336; uRtoUL++) {
        for (int32 uBtoDF = 0; uBtoDF < 336; uBtoDF++) {
            MergeURtoULandUBtoDF[uRtoUL][uBtoDF] = (int32)getURtoDF_standalone(uRtoUL, uBtoDF);
        }
    }

    //Slice_URFtoDLF_Parity_Prun
    int32 depth = 0, done = 1;
    for (int32 i = 0; i < N_SLICE2 * N_URFtoDLF * N_PARITY / 2; i++)
        Slice_URFtoDLF_Parity_Prun[i] = -1;
    setPruning(Slice_URFtoDLF_Parity_Prun, 0, 0);
    // printf("1\n");
    while (done != N_SLICE2 * N_URFtoDLF * N_PARITY) {
        // printf("%d %d %d\n", done, N_SLICE2 * N_URFtoDLF * N_PARITY, depth);
        for (int32 i = 0; i < N_SLICE2 * N_URFtoDLF * N_PARITY; i++) {
            int parity = i % 2;
            int URFtoDLF = (i / 2) / N_SLICE2;
            int slice = (i / 2) % N_SLICE2;
            if (getPruning(Slice_URFtoDLF_Parity_Prun, i) == depth) {
                for (int32 j = 0; j < 18; j++) {
                    int newSlice;
                    int newURFtoDLF;
                    int newParity;
                    switch (j) {
                    case 3:
                    case 5:
                    case 6:
                    case 8:
                    case 12:
                    case 14:
                    case 15:
                    case 17:
                        continue;
                    default:
                        newSlice = FRtoBR_Move[slice][j];
                        newURFtoDLF = URFtoDLF_Move[URFtoDLF][j];
                        newParity = parityMove[parity][j];
                        if (getPruning(Slice_URFtoDLF_Parity_Prun, (N_SLICE2 * newURFtoDLF + newSlice) * 2 + newParity) == 0x0f) {
                            setPruning(Slice_URFtoDLF_Parity_Prun, (N_SLICE2 * newURFtoDLF + newSlice) * 2 + newParity,
                                (signed char)(depth + 1));
                            done++;
                        }
                    }
                }
            }
        }
        depth++;
    }

    ///Slice_URtoDF_Parity_Prun
    depth = 0, done = 1;
    for (int32 i = 0; i < N_SLICE2 * N_URtoDF * N_PARITY / 2; i++)
        Slice_URtoDF_Parity_Prun[i] = -1;
    setPruning(Slice_URtoDF_Parity_Prun, 0, 0);
    while (done != N_SLICE2 * N_URtoDF * N_PARITY) {
        for (int32 i = 0; i < N_SLICE2 * N_URtoDF * N_PARITY; i++) {
            int parity = i % 2;
            int URtoDF = (i / 2) / N_SLICE2;
            int slice = (i / 2) % N_SLICE2;
            if (getPruning(Slice_URtoDF_Parity_Prun, i) == depth) {
                for (int32 j = 0; j < 18; j++) {
                    int newSlice;
                    int newURtoDF;
                    int newParity;
                    switch (j) {
                    case 3:
                    case 5:
                    case 6:
                    case 8:
                    case 12:
                    case 14:
                    case 15:
                    case 17:
                        continue;
                    default:
                        newSlice = FRtoBR_Move[slice][j];
                        newURtoDF = URtoDF_Move[URtoDF][j];
                        newParity = parityMove[parity][j];
                        if (getPruning(Slice_URtoDF_Parity_Prun, (N_SLICE2 * newURtoDF + newSlice) * 2 + newParity) == 0x0f) {
                            setPruning(Slice_URtoDF_Parity_Prun, (N_SLICE2 * newURtoDF + newSlice) * 2 + newParity,
                                (signed char)(depth + 1));
                            done++;
                        }
                    }
                }
            }
        }
        depth++;
    }

    //Slice_Twist_Prun
    depth = 0, done = 1;
    for (int32 i = 0; i < N_SLICE1 * N_TWIST / 2 + 1; i++)
        Slice_Twist_Prun[i] = -1;
    setPruning(Slice_Twist_Prun, 0, 0);
    while (done != N_SLICE1 * N_TWIST) {
        for (int32 i = 0; i < N_SLICE1 * N_TWIST; i++) {
            int twist = i / N_SLICE1, slice = i % N_SLICE1;
            if (getPruning(Slice_Twist_Prun, i) == depth) {
                for (int32 j = 0; j < 18; j++) {
                    int newSlice = FRtoBR_Move[slice * 24][j] / 24;
                    int newTwist = twistMove[twist][j];
                    if (getPruning(Slice_Twist_Prun, N_SLICE1 * newTwist + newSlice) == 0x0f) {
                        setPruning(Slice_Twist_Prun, N_SLICE1 * newTwist + newSlice, (signed char)(depth + 1));
                        done++;
                    }
                }
            }
        }
        depth++;
    }

    //Slice_Flip_Prun
    depth = 0, done = 1;
    for (int32 i = 0; i < N_SLICE1 * N_FLIP / 2; i++)
        Slice_Flip_Prun[i] = -1;
    setPruning(Slice_Flip_Prun, 0, 0);
    while (done != N_SLICE1 * N_FLIP) {
        for (int32 i = 0; i < N_SLICE1 * N_FLIP; i++) {
            int flip = i / N_SLICE1, slice = i % N_SLICE1;
            if (getPruning(Slice_Flip_Prun, i) == depth) {
                for (int32 j = 0; j < 18; j++) {
                    int newSlice = FRtoBR_Move[slice * 24][j] / 24;
                    int newFlip = flipMove[flip][j];
                    if (getPruning(Slice_Flip_Prun, N_SLICE1 * newFlip + newSlice) == 0x0f) {
                        setPruning(Slice_Flip_Prun, N_SLICE1 * newFlip + newSlice, (signed char)(depth + 1));
                        done++;
                    }
                }
            }
        }
        depth++;
    }
}//*/

FCubieCube* cubeDataStructs::getSolvedCubieCube()
{
    FCubieCube* result = new FCubieCube;

    //static const corner_t   cp[8] = { URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB };
    //static const signed char       co[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    //static const edge_t     ep[12] = { UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR };
    //static const signed char       eo[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    result->cornerPosition = { cornerPieces::URF, cornerPieces::UFL, cornerPieces::ULB, cornerPieces::UBR, cornerPieces::DFR, cornerPieces::DLF, cornerPieces::DBL, cornerPieces::DRB };
    result->cornerOrientation = { 0, 0, 0, 0, 0, 0, 0, 0 };
    result->edgePosition = { edgePieces::UR, edgePieces::UF, edgePieces::UL, edgePieces::UB, edgePieces::DR, edgePieces::DF, edgePieces::DL, edgePieces::DB, edgePieces::FR, edgePieces::FL, edgePieces::BL, edgePieces::BR };
    result->edgeOrientation = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    return result;
}

FCubieCube* cubeDataStructs::getMoveCubiesCube()
{
    static FCubieCube moveCube[6];

    //U
    moveCube[0].cornerPosition = { cornerPieces::UBR, cornerPieces::URF, cornerPieces::UFL, cornerPieces::ULB, cornerPieces::DFR, cornerPieces::DLF, cornerPieces::DBL, cornerPieces::DRB };
    moveCube[0].cornerOrientation = { 0, 0, 0, 0, 0, 0, 0, 0 };
    moveCube[0].edgePosition = { edgePieces::UB, edgePieces::UR, edgePieces::UF, edgePieces::UL, edgePieces::DR, edgePieces::DF, edgePieces::DL, edgePieces::DB, edgePieces::FR, edgePieces::FL, edgePieces::BL, edgePieces::BR };
    moveCube[0].edgeOrientation = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    //R
    moveCube[1].cornerPosition = { cornerPieces::DFR, cornerPieces::UFL, cornerPieces::ULB, cornerPieces::URF, cornerPieces::DRB, cornerPieces::DLF, cornerPieces::DBL, cornerPieces::UBR };
    moveCube[1].cornerOrientation = { 2, 0, 0, 1, 1, 0, 0, 2 };
    moveCube[1].edgePosition = { edgePieces::FR, edgePieces::UF, edgePieces::UL, edgePieces::UB, edgePieces::BR, edgePieces::DF, edgePieces::DL,edgePieces::DB,edgePieces::DR,edgePieces::FL, edgePieces::BL, edgePieces::UR };
    moveCube[1].edgeOrientation = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    //F
    moveCube[2].cornerPosition = { cornerPieces::UFL, cornerPieces::DLF, cornerPieces::ULB,cornerPieces::UBR, cornerPieces::URF,cornerPieces::DFR,cornerPieces::DBL,cornerPieces::DRB };
    moveCube[2].cornerOrientation = { 1, 2, 0, 0, 2, 1, 0, 0 };
    moveCube[2].edgePosition = { edgePieces::UR, edgePieces::FL, edgePieces::UL,edgePieces::UB,edgePieces::DR, edgePieces::FR, edgePieces::DL, edgePieces::DB,edgePieces::UF,edgePieces::DF, edgePieces::BL, edgePieces::BR };
    moveCube[2].edgeOrientation = { 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 };

    //D
    moveCube[3].cornerPosition = { cornerPieces::URF, cornerPieces::UFL,cornerPieces::ULB, cornerPieces::UBR, cornerPieces::DLF, cornerPieces::DBL, cornerPieces::DRB, cornerPieces::DFR };
    moveCube[3].cornerOrientation = { 0, 0, 0, 0, 0, 0, 0, 0 };
    moveCube[3].edgePosition = { edgePieces::UR,edgePieces::UF, edgePieces::UL,edgePieces::UB,edgePieces::DF,edgePieces::DL,edgePieces::DB, edgePieces::DR,edgePieces::FR,edgePieces::FL,edgePieces::BL, edgePieces::BR };
    moveCube[3].edgeOrientation = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    //L
    moveCube[4].cornerPosition = { cornerPieces::URF, cornerPieces::ULB,cornerPieces::DBL, cornerPieces::UBR, cornerPieces::DFR, cornerPieces::UFL,cornerPieces::DLF,cornerPieces::DRB };
    moveCube[4].cornerOrientation = { 0, 1, 2, 0, 0, 2, 1, 0 };
    moveCube[4].edgePosition = { edgePieces::UR,edgePieces::UF,edgePieces::BL,edgePieces::UB, edgePieces::DR,edgePieces::DF,edgePieces::FL, edgePieces::DB,edgePieces::FR, edgePieces::UL, edgePieces::DL, edgePieces::BR };
    moveCube[4].edgeOrientation = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    //B
    moveCube[5].cornerPosition = { cornerPieces::URF, cornerPieces::UFL, cornerPieces::UBR, cornerPieces::DRB, cornerPieces::DFR, cornerPieces::DLF, cornerPieces::ULB, cornerPieces::DBL };
    moveCube[5].cornerOrientation = { 0, 0, 1, 2, 0, 0, 2, 1 };
    moveCube[5].edgePosition = { edgePieces::UR,edgePieces::UF,edgePieces::UL,edgePieces::BR,edgePieces::DR,edgePieces::DF,edgePieces::DL,edgePieces::BL,edgePieces::FR,edgePieces::FL,edgePieces::UB,edgePieces::DB };
    moveCube[5].edgeOrientation = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1 };

    return moveCube;
}

///____________________________________________________________________FUNCTIONS_____________________________________________
int32 cubeDataStructs::getTwist(FCubieCube* cubiecube)
{
    int32 ret = 0;
    uint8 i;
    for (i = (uint8)cornerPieces::URF; i < (uint8)cornerPieces::DRB; i++)
        ret = (int32)(3 * ret + cubiecube->cornerOrientation[i]);
    return ret;
}

void cubeDataStructs::setTwist(FCubieCube* cubiecube, int32 twist)
{
    int32 twistParity = 0;
    for (int8 i = (int8)cornerPieces::DRB - 1; i >= (int8)cornerPieces::URF; i--) {
        twistParity += cubiecube->cornerOrientation[i];
        cubiecube->cornerOrientation[i] = (twist % 3);
        twist /= 3;
    }
    cubiecube->cornerOrientation[(uint8)cornerPieces::DRB] = ((3 - twistParity % 3) % 3);
}


int32 cubeDataStructs::getFlip(FCubieCube* cubiecube)
{
    int32 ret = 0;
    for (uint8 i = (uint8)edgePieces::UR; i < (uint8)edgePieces::BR; i++)
        ret = (int32)(2 * ret + cubiecube->edgeOrientation[i]);
    return ret;
}

void cubeDataStructs::setFlip(FCubieCube* cubiecube, int32 flip)
{
    int flipParity = 0;
    for (int8 i = (int8)edgePieces::BR - 1; i >= (int8)edgePieces::UR; i--) {
        flipParity += cubiecube->edgeOrientation[i] = (signed char)(flip % 2);
        flip /= 2;
    }
    cubiecube->edgeOrientation[(uint8)edgePieces::BR] = (signed char)((2 - flipParity % 2) % 2);
}


int32 cubeDataStructs::cornerParity(FCubieCube* cubiecube)
{
    int32 s = 0;
    int8 i, j;
    for (i = (int8)cornerPieces::DRB; i >= (int8)cornerPieces::URF + 1; i--)
        //UE_LOG(LogTemp, Warning, TEXT("i---: %d"), i);
        for (j = i - 1; j >= (int8)cornerPieces::URF; j--)
            //UE_LOG(LogTemp, Warning, TEXT("   j: %d"), j);
            if (cubiecube->cornerPosition[j] > cubiecube->cornerPosition[i])
                s++;
    return (int32)(s % 2);
}

int32 cubeDataStructs::edgeParity(FCubieCube* cubiecube)
{
    uint8 i, j;
    int32 s = 0;
    for (i = (int8)edgePieces::BR; i >= (int8)edgePieces::UR + 1; i--)
        for (j = i - 1; j >= (int8)edgePieces::UR; j--)
            if (cubiecube->edgePosition[j] > cubiecube->edgePosition[i])
                s++;
    return (int32)(s % 2);
}



int32 cubeDataStructs::getFRtoBR(FCubieCube* cubiecube)
{
    int a = 0, x = 0;
    int b = 0;
    edgePieces edge4[4] = {(edgePieces)0,(edgePieces)0,(edgePieces)0,(edgePieces)0};
    // compute the index a < (12 choose 4) and the permutation array perm.
    for (int8 j = (int8)edgePieces::BR; j >= (int8)edgePieces::UR; j--)
        if (edgePieces::FR <= cubiecube->edgePosition[j] && cubiecube->edgePosition[j] <= edgePieces::BR) {
            a += Cnk(11 - j, x + 1);
            edge4[3 - x++] = cubiecube->edgePosition[j];
        }

    for (int8 j = 3; j > 0; j--)// compute the index b < 4! for the
    // permutation in perm
    {
        int k = 0;
        while ((uint8)edge4[j] != j + 8) {
            rotateLeft_edge(edge4, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (int32)(24 * a + b);
}

void cubeDataStructs::setFRtoBR(FCubieCube* cubiecube, int16 idx)
{
    int32 k, x;
    //int x, j, k, e;
    edgePieces sliceEdge[4] = { edgePieces::FR, edgePieces::FL, edgePieces::BL, edgePieces::BR };
    edgePieces otherEdge[8] = { edgePieces::UR, edgePieces::UF, edgePieces::UL, edgePieces::UB, edgePieces::DR, edgePieces::DF, edgePieces::DL, edgePieces::DB };
    int b = idx % 24; // Permutation
    int a = idx / 24; // Combination
    for (uint8 e = 0; e < 12; e++)
        cubiecube->edgePosition[e] = edgePieces::DB;// Use UR to invalidate all edges

    for (uint8 j = 1; j < 4; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(sliceEdge, 0, j);
    }

    x = 3;// generate combination and set slice edges
    for (uint8 j = (uint8)edgePieces::UR; j <= (uint8)edgePieces::BR; j++)
        if (a - Cnk(11 - j, x + 1) >= 0) {
            cubiecube->edgePosition[j] = sliceEdge[3 - x];
            a -= Cnk(11 - j, x-- + 1);
        }
    x = 0; // set the remaining edges UR..DB
    for (uint8 j = (uint8)edgePieces::UR; j <= (uint8)edgePieces::BR; j++)
        if (cubiecube->edgePosition[j] == edgePieces::DB)
            cubiecube->edgePosition[j] = otherEdge[x++];
}



int32 cubeDataStructs::getURFtoDLF(FCubieCube* cubiecube)
{
    int a = 0, x = 0, b = 0;
    cornerPieces corner6[6] = { (cornerPieces) 0 };
    // compute the index a < (8 choose 6) and the corner permutation.
    for (uint8 j = (uint8)cornerPieces::URF; j <= (uint8)cornerPieces::DRB; j++)
        if (cubiecube->cornerPosition[j] <= cornerPieces::DLF) {
            a += Cnk(j, x + 1);
            corner6[x++] = cubiecube->cornerPosition[j];
        }

    for (uint8 j = 5; j > 0; j--)// compute the index b < 6! for the
    // permutation in corner6
    {
        int k = 0;
        while ((uint8)corner6[j] != j) {
            rotateLeft_corner(corner6, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (int32)(720 * a + b);
}

void cubeDataStructs::setURFtoDLF(FCubieCube* cubiecube, int16 idx)
{
    int x;
    cornerPieces corner6[6] = { cornerPieces::URF, cornerPieces::UFL, cornerPieces::ULB, cornerPieces::UBR, cornerPieces::DFR, cornerPieces::DLF };
    cornerPieces otherCorner[2] = { cornerPieces::DBL, cornerPieces::DRB };
    int b = idx % 720; // Permutation
    int a = idx / 720; // Combination
    int32 k;
    for (uint8 c = 0; c < 8; c++)
        cubiecube->cornerPosition[c] = cornerPieces::DRB;// Use DRB to invalidate all corners

    for (uint8 j = 1; j < 6; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_corner(corner6, 0, j);
    }
    x = 5;// generate combination and set corners
    for (int8 j = (int8)cornerPieces::DRB; j >= 0; j--)
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->cornerPosition[j] = corner6[x];
            a -= Cnk(j, x-- + 1);
        }
    x = 0;
    for (int8 j = (int8)cornerPieces::URF; j <= (int8)cornerPieces::DRB; j++)
        if (cubiecube->cornerPosition[j] == cornerPieces::DRB)
            cubiecube->cornerPosition[j] = otherCorner[x++];
}





int32 cubeDataStructs::getURtoDF(FCubieCube* cubiecube)
{
    int32 a = 0, x = 0;
    int32 b = 0;
    edgePieces edge6[6] = { (edgePieces) 0 };
    // compute the index a < (12 choose 6) and the edge permutation.
    for (int8 j = (int8) edgePieces::UR; j <= (int8)edgePieces::BR; j++)
        if (cubiecube->edgePosition[j] <= edgePieces::DF) {
            a += Cnk(j, x + 1);
            edge6[x++] = cubiecube->edgePosition[j];
        }

    for (int8 j = 5; j > 0; j--)// compute the index b < 6! for the
    // permutation in edge6
    {
        int32 k = 0;
        while ((uint8) edge6[j] != j) {
            rotateLeft_edge(edge6, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return 720 * a + b;
}

void cubeDataStructs::setURtoDF(FCubieCube* cubiecube, int32 idx)
{
    int x, k;
    edgePieces edge6[6] = { edgePieces::UR, edgePieces::UF, edgePieces::UL, edgePieces::UB, edgePieces::DR, edgePieces::DF };
    edgePieces otherEdge[6] = { edgePieces::DL, edgePieces::DB, edgePieces::FR, edgePieces::FL, edgePieces::BL, edgePieces::BR };
    int b = idx % 720; // Permutation
    int a = idx / 720; // Combination

    for (uint8 e = 0; e < 12; e++)
        cubiecube->edgePosition[e] = edgePieces::BR;// Use BR to invalidate all edges

    for (uint8 j = 1; j < 6; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(edge6, 0, j);
    }
    x = 5;// generate combination and set edges
    for (int8 j = (int8)edgePieces::BR; j >= 0; j--)
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->edgePosition[j] = edge6[x];
            a -= Cnk(j, x-- + 1);
        }
    x = 0; // set the remaining edges DL..BR
    for (uint8 j = (uint8)edgePieces::UR; j <= (uint8)edgePieces::BR; j++)
        if (cubiecube->edgePosition[j] == edgePieces::BR)
            cubiecube->edgePosition[j] = otherEdge[x++];
}





int32 cubeDataStructs::getURtoUL(FCubieCube* cubiecube)
{
    int a = 0, b = 0, x = 0;
    edgePieces edge3[3] = { (edgePieces) 0 };
    // compute the index a < (12 choose 3) and the edge permutation.
    for (uint8 j = (uint8) edgePieces::UR; j <= (uint8)edgePieces::BR; j++)
        if (cubiecube->edgePosition[j] <= edgePieces::UL) {
            a += Cnk(j, x + 1);
            edge3[x++] = cubiecube->edgePosition[j];
        }

    for (int8 j = 2; j > 0; j--)// compute the index b < 3! for the
    // permutation in edge3
    {
        int k = 0;
        while ((uint8)edge3[j] != j) {
            rotateLeft_edge(edge3, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (int32)(6 * a + b);
}

void cubeDataStructs::setURtoUL(FCubieCube* cubiecube, int16 idx)
{
    int x, k;
    edgePieces edge3[3] = { edgePieces::UR, edgePieces::UF, edgePieces::UL };
    int b = idx % 6; // Permutation
    int a = idx / 6; // Combination
    for (uint8 e = 0; e < 12; e++) {
        cubiecube->edgePosition[e] = edgePieces::BR;// Use BR to invalidate all edges
    }

    for (uint8 j = 1; j < 3; j++) {// generate permutation from index b
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(edge3, 0, j);
    }
    x = 2;// generate combination and set edges
    for (int8 j = (int8)edgePieces::BR; j >= 0; j--) {
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->edgePosition[j] = edge3[x];
            a -= Cnk(j, x-- + 1);
        }
    }
}





int32 cubeDataStructs::getUBtoDF(FCubieCube* cubiecube)
{
    int a = 0, x = 0, b = 0;
    edgePieces edge3[3] = { (edgePieces) 0 };
    // compute the index a < (12 choose 3) and the edge permutation.
    for (uint8 j = (uint8) edgePieces::UR; j <= (uint8)edgePieces::BR; j++)
        if (edgePieces::UB <= cubiecube->edgePosition[j] && cubiecube->edgePosition[j] <= edgePieces::DF) {
            a += Cnk(j, x + 1);
            edge3[x++] = cubiecube->edgePosition[j];
        }

    for (int8 j = 2; j > 0; j--)// compute the index b < 3! for the
    // permutation in edge3
    {
        int k = 0;
        while ((uint8) edge3[j] != (uint8)edgePieces::UB + j) {
            rotateLeft_edge(edge3, 0, j);
            k++;
        }
        b = (j + 1) * b + k;
    }
    return (int32)(6 * a + b);
}

void cubeDataStructs::setUBtoDF(FCubieCube* cubiecube, int16 idx)
{
    int x, k;
    edgePieces edge3[3] = { edgePieces::UB, edgePieces::DR, edgePieces::DF };
    int b = idx % 6; // Permutation
    int a = idx / 6; // Combination
    for (uint8 e = 0; e < 12; e++)
        cubiecube->edgePosition[e] = edgePieces::BR;// Use BR to invalidate all edges

    for (uint8 j = 1; j < 3; j++)// generate permutation from index b
    {
        k = b % (j + 1);
        b /= j + 1;
        while (k-- > 0)
            rotateRight_edge(edge3, 0, j);
    }
    x = 2;// generate combination and set edges
    for (int8 j = (int8)edgePieces::BR; j >= 0; j--)
        if (a - Cnk(j, x + 1) >= 0) {
            cubiecube->edgePosition[j] = edge3[x];
            a -= Cnk(j, x-- + 1);
        }
}




int32 cubeDataStructs::Cnk(int n, int k)
{
    int32 i, j, s;
    if (n < k)
        return 0;
    if (k > n / 2)
        k = n - k;
    for (s = 1, i = n, j = 1; i != n - k; i--, j++) {
        s *= i;
        s /= j;
    }
    return s;
}

void cubeDataStructs::rotateLeft_corner(cornerPieces* arr, int l, int r)
// Left rotation of all array elements between l and r
{
    int i;
    cornerPieces temp = arr[l];
    for (i = l; i < r; i++)
        arr[i] = arr[i + 1];
    arr[r] = temp;
}

void cubeDataStructs::rotateRight_corner(cornerPieces* arr, int l, int r)
// Right rotation of all array elements between l and r
{
    int i;
    cornerPieces temp = arr[r];
    for (i = r; i > l; i--)
        arr[i] = arr[i - 1];
    arr[l] = temp;
}


void cubeDataStructs::rotateLeft_edge(edgePieces* arr, int l, int r)
// Left rotation of all array elements between l and r
{
    int i;
    edgePieces temp = arr[l];
    for (i = l; i < r; i++)
        arr[i] = arr[i + 1];
    arr[r] = temp;
}

void cubeDataStructs::rotateRight_edge(edgePieces* arr, int l, int r)
// Right rotation of all array elements between l and r
{
    int i;
    edgePieces temp = arr[r];
    for (i = r; i > l; i--)
        arr[i] = arr[i - 1];
    arr[l] = temp;
}

void cubeDataStructs::cornerMultiply(FCubieCube* cubiecube, FCubieCube* b)
{
    int32 corn;
    int32 oriA, oriB, ori;
    cornerPieces cPerm[8] = { (cornerPieces)0 };
    int32 cOri[8] = { 0 };
    for (corn = 0; corn < 8; corn++) {
        cPerm[corn] = cubiecube->cornerPosition[(uint8)b->cornerPosition[corn]];

        oriA = cubiecube->cornerOrientation[(uint8)b->cornerPosition[corn]];
        oriB = b->cornerOrientation[corn];
        ori = 0;

        if (oriA < 3 && oriB < 3) // if both cubes are regular cubes...
        {
            ori = oriA + oriB; // just do an addition modulo 3 here
            if (ori >= 3)
                ori -= 3; // the composition is a regular cube

            // +++++++++++++++++++++not used in this implementation +++++++++++++++++++++++++++++++++++
        }
        else if (oriA < 3 && oriB >= 3) // if cube b is in a mirrored
     // state...
        {
            ori = oriA + oriB;
            if (ori >= 6)
                ori -= 3; // the composition is a mirrored cube
        }
        else if (oriA >= 3 && oriB < 3) // if cube a is an a mirrored
     // state...
        {
            ori = oriA - oriB;
            if (ori < 3)
                ori += 3; // the composition is a mirrored cube
        }
        else if (oriA >= 3 && oriB >= 3) // if both cubes are in mirrored
     // states...
        {
            ori = oriA - oriB;
            if (ori < 0)
                ori += 3; // the composition is a regular cube
            // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        }
        cOri[corn] = ori;
    }
    for (corn = 0; corn < 8; corn++) {
        cubiecube->cornerPosition[corn] = cPerm[corn];
        cubiecube->cornerOrientation[corn] = cOri[corn];
    }
}

void cubeDataStructs::edgeMultiply(FCubieCube* cubiecube, FCubieCube* b)
{
    int edge;
    edgePieces ePerm[12] = { (edgePieces)0 };
    int32 eOri[12] = { 0 };

    for (edge = 0; edge < 12; edge++) {
        ePerm[edge] = cubiecube->edgePosition[(uint8)b->edgePosition[edge]];
        eOri[edge] = (b->edgeOrientation[edge] + cubiecube->edgeOrientation[(uint8)b->edgePosition[edge]]) % 2;
    }
    for (edge = 0; edge < 12; edge++) {
        cubiecube->edgePosition[edge] = ePerm[edge];
        cubiecube->edgeOrientation[edge] = eOri[edge];
    }
}

void cubeDataStructs::multiply(FCubieCube* cubiecube, FCubieCube* b)
{
    cornerMultiply(cubiecube, b);
    edgeMultiply(cubiecube, b);
}

int32 cubeDataStructs::getURtoDF_standalone(int32 idx1, int32 idx2)
{
    int32 res, i;
    FCubieCube* a = getSolvedCubieCube();
    FCubieCube* b = getSolvedCubieCube();
    setURtoUL(a, idx1);
    setUBtoDF(b, idx2);
    for (i = 0; i < 8; i++) {
        if (a->edgePosition[i] != edgePieces::BR) {
            if (b->edgePosition[i] != edgePieces::BR) {// collision
                return -1;
            }
            else {
                b->edgePosition[i] = a->edgePosition[i];
            }
        }
    }
    res = getURtoDF(b);
    free(a);
    free(b);
    return res;
}

void cubeDataStructs::setPruning(int32* table, int32 index, int32 value) {
    if ((index & 1) == 0)
        table[index / 2] &= 0xf0 | value;
    else
        table[index / 2] &= 0x0f | (value << 4);
}

int32 cubeDataStructs::getPruning(int32* table, int32 index) {
    int32 res;

    if ((index & 1) == 0)
        res = (table[index / 2] & 0x0f);
    else
        res = ((table[index / 2] >> 4) & 0x0f);

    return res;
}