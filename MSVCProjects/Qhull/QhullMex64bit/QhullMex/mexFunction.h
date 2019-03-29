#ifndef MEXFUNCTION_H
#define MEXFUNCTION_H

#include "mex.h"
#include "math.h"
#include "matrix.h"

#include "RboxPoints.h"
#include "QhullError.h"
#include "QhullQh.h"
#include "QhullFacet.h"
#include "QhullFacetList.h"
#include "QhullFacetSet.h"
#include "QhullLinkedList.h"
#include "QhullVertexSet.h"
#include "QhullVertex.h"
#include "Qhull.h"

mxArray* gatherQhullResults(orgQhull::Qhull &qhull);

mxArray* gatherRboxResults(orgQhull::RboxPoints &rbox);


#endif