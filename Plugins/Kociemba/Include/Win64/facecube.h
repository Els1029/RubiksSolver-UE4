#ifndef FACECUBE_H
#define FACECUBE_H

#include "facelet.h"
#include "color.h"
#include "corner.h"
#include "edge.h"

//Cube on the facelet level
extern "C" CUBELIBRARY_API struct facecube {
    color_t f[54];
};
extern "C" CUBELIBRARY_API typedef struct facecube facecube_t;

// forward declaration
extern "C" CUBELIBRARY_API struct cubiecube;

// Map the corner positions to facelet positions. cornerFacelet[URF.ordinal()][0] e.g. gives the position of the
// facelet in the URF corner position, which defines the orientation.<br>
// cornerFacelet[URF.ordinal()][1] and cornerFacelet[URF.ordinal()][2] give the position of the other two facelets
// of the URF corner (clockwise).
extern "C" CUBELIBRARY_API extern "C" facelet_t cornerFacelet[8][3];

// Map the edge positions to facelet positions. edgeFacelet[UR.ordinal()][0] e.g. gives the position of the facelet in
// the UR edge position, which defines the orientation.<br>
// edgeFacelet[UR.ordinal()][1] gives the position of the other facelet
extern "C" CUBELIBRARY_API facelet_t edgeFacelet[12][2];

// Map the corner positions to facelet colors.
extern "C" CUBELIBRARY_API color_t cornerColor[8][3];

// Map the edge positions to facelet colors.
extern "C" CUBELIBRARY_API color_t edgeColor[12][2];

extern "C" CUBELIBRARY_API facecube_t* get_facecube(void);
extern "C" CUBELIBRARY_API facecube_t* get_facecube_fromstring(char* cubeString);

extern "C" CUBELIBRARY_API void to_String(facecube_t* facecube, char* res);
extern "C" CUBELIBRARY_API struct cubiecube* toCubieCube(facecube_t* facecube);

#endif
