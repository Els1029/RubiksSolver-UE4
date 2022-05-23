#ifndef CUBIECUBE_H
#define CUBIECUBE_H

#include <string.h>
#include <stdlib.h>

#include "corner.h" 
#include "edge.h"

//Cube on the cubie level
extern "C" CUBELIBRARY_API struct cubiecube {
    // initialize to Id-Cube
    // corner permutation
    corner_t cp[8];
    // corner orientation
    signed char co[8];
    // edge permutation
    edge_t ep[12];
    // edge orientation
    signed char eo[12];
};
extern "C" CUBELIBRARY_API typedef struct cubiecube cubiecube_t;

// forward declaration
extern "C" CUBELIBRARY_API struct facecube;

// this CubieCube array represents the 6 basic cube moves
extern "C" CUBELIBRARY_API cubiecube_t* get_moveCube(void);
extern "C" CUBELIBRARY_API cubiecube_t* get_cubiecube(void);

// n choose k
extern "C" CUBELIBRARY_API int Cnk(int n, int k);
extern "C" CUBELIBRARY_API void rotateLeft_corner(corner_t* arr, int l, int r);
extern "C" CUBELIBRARY_API void rotateRight_corner(corner_t* arr, int l, int r);
extern "C" CUBELIBRARY_API void rotateLeft_edge(edge_t* arr, int l, int r);
extern "C" CUBELIBRARY_API void rotateRight_edge(edge_t* arr, int l, int r);
extern "C" CUBELIBRARY_API struct facecube* toFaceCube(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void cornerMultiply(cubiecube_t* cubiecube, cubiecube_t* b);
extern "C" CUBELIBRARY_API void edgeMultiply(cubiecube_t* cubiecube, cubiecube_t* b);
extern "C" CUBELIBRARY_API void multiply(cubiecube_t* cubiecube, cubiecube_t* b);
extern "C" CUBELIBRARY_API void invCubieCube(cubiecube_t* cubiecube, cubiecube_t* c);
extern "C" CUBELIBRARY_API short getTwist(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setTwist(cubiecube_t* cubiecube, short twist);
extern "C" CUBELIBRARY_API short getFlip(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setFlip(cubiecube_t* cubiecube, short flip);
extern "C" CUBELIBRARY_API short cornerParity(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API short edgeParity(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API short getFRtoBR(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setFRtoBR(cubiecube_t* cubiecube, short idx);
extern "C" CUBELIBRARY_API short getURFtoDLF(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setURFtoDLF(cubiecube_t* cubiecube, short idx);
extern "C" CUBELIBRARY_API int getURtoDF(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setURtoDF(cubiecube_t* cubiecube, int idx);

extern "C" CUBELIBRARY_API short getURtoUL(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setURtoUL(cubiecube_t* cubiecube, short idx);
extern "C" CUBELIBRARY_API short getUBtoDF(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setUBtoDF(cubiecube_t* cubiecube, short idx);
extern "C" CUBELIBRARY_API int getURFtoDLB(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setURFtoDLB(cubiecube_t* cubiecube, int idx);
extern "C" CUBELIBRARY_API int getURtoBR(cubiecube_t* cubiecube);
extern "C" CUBELIBRARY_API void setURtoBR(cubiecube_t* cubiecube, int idx);

extern "C" CUBELIBRARY_API int verify(cubiecube_t* cubiecube);

extern "C" CUBELIBRARY_API int getURtoDF_standalone(short idx1, short idx2);

#endif
