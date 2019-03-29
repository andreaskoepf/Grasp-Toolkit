#include "mexFunction.h"
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include "MexUtilities.h"

using namespace std;
using namespace orgQhull;

// global variables
const string rBoxString("rbox"), qhullString("qhull");
const string gDefaultRboxCommands("10 c D3"), gDefaultQhullCommands("Qt Qv Q3 Tv");
const char *gQhullResultStructFields[] = {"faces", "offsets", "normal", "neighboringFacets", "area", "volume"};
const int gQhullNumOfResStructFields = 6;
const char *gRboxResultStructFields[] = {"vertices"};
const int gRboxNumOfResStructFields = 1;
bool gExecutingRbox = false, gExecutingQhull = false;
int gNumOfDimensions, gNumOfVertices, gNumOfFacets;
map<int, int> gFacetIndexMap;


void mexFunction(int nlhs, mxArray *plhs[],int nrhs, const mxArray *prhs[])
{

	if(nlhs>1)
	{

		mexErrMsgTxt("too many output arguments");
		return;

	}

	// reseting all global variables
	gExecutingRbox = false;
	gExecutingQhull = false;
	gNumOfDimensions = 0;
	gNumOfVertices = 0;
	gNumOfFacets = 0;

	// extracting data
	string programCalled;
	string command;
	double *vertexData;



	for(int i = 0; i< nrhs; i++)
	{

		if(mxIsChar(prhs[i]))
		{

			programCalled = MexUtilities::mxArray_to_string(prhs[i]);

			if(programCalled.compare(rBoxString) == 0)
			{

				
				gExecutingRbox = true;
				gExecutingQhull = false;
				command = gDefaultRboxCommands;

			}
			else if(programCalled.compare(qhullString) == 0)
			{

				gExecutingRbox = false;
				gExecutingQhull = true;
				command = gDefaultQhullCommands;

			}
			else
			{
				
				
				command = MexUtilities::mxArray_to_string(prhs[i]);

			}
		}
		else if(mxIsNumeric(prhs[i]))
		{

			vertexData = MexUtilities::mxArray_to_double_array(prhs[i],APPEND_ROW_WISE);
			gNumOfDimensions = MexUtilities::mxArray_column_size(prhs[i]);
			gNumOfVertices = MexUtilities::mxArray_row_size(prhs[i]);		

			command = gDefaultQhullCommands;
			gExecutingRbox = false;
			gExecutingQhull = true;

		}
		else
		{

			mexErrMsgTxt("input must be a program name 'rbox' or 'qhull', a command entered as char or vertex data entered as double");

		}

	}

	if(gExecutingRbox)
	{

		RboxPoints rbox;
		try
		{

			rbox.appendPoints(command.c_str());

		}
		catch(QhullError &e)
		{

			mexErrMsgTxt((string("qhull error: ") + string(e.what())).c_str());
			return;

		}


		plhs[0] = gatherRboxResults(rbox);

		//delete [] rbox.coordinates();
		return;

	}
	else if(gExecutingQhull)
	{

		Qhull qhull;
	
		try
		{
			
			
			qhull.runQhull("QhullMex",gNumOfDimensions,gNumOfVertices,vertexData,command.c_str());
			

		}
		catch(QhullError &e)
		{

			mexErrMsgTxt((string("qhull error: ") + string(e.what())).c_str());
			//return;

		}

		plhs[0] = gatherQhullResults(qhull);
		delete [] vertexData;

		return;

	}
	else
	{
		
		mexErrMsgTxt("inputs did not select either 'rbox' or qhull' programs");

	}



}


mxArray* gatherQhullResults(orgQhull::Qhull &qhull)
{

		// result array holders
	vector< int > facesData;
	vector< double > offsetData;
	vector< double > normalData;
	vector< int > neighboringFacetsData;

	// reserving space
	gNumOfFacets = qhull.facetCount(); 
	facesData.reserve(qhull.facetCount()*gNumOfDimensions);
	offsetData.reserve(qhull.facetCount());
	normalData.reserve(qhull.facetCount()*gNumOfDimensions);
	neighboringFacetsData.reserve(qhull.facetCount()*gNumOfDimensions);

	// obtaining result data
	std::vector< QhullFacet> &facetVector = qhull.facetList().toStdVector();
	gFacetIndexMap.clear();
	
	// storing facet index into map
	int counter = 0;
	for(std::vector< QhullFacet >::iterator i = facetVector.begin(); i<facetVector.end(); i++)
	{

		QhullFacet &facet = *i;
		gFacetIndexMap.insert(make_pair(facet.id(),++counter));

	}
	
	
	// gathering results

	counter = 0;
	int dimensionCounter = 0;
	for(std::vector< QhullFacet >::iterator i = facetVector.begin(); i != facetVector.end(); i++)
	{

		QhullFacet &facet = *i;

		// accessing vertices in each facet
		vector< QhullVertex > &facetVertices = facet.vertices().toStdVector();

		for(std::vector< QhullVertex >::iterator i1 = facetVertices.begin(); i1 != facetVertices.end(); i1++)
		{

			QhullVertex &v = *i1;

			facesData.push_back(v.point().id(qhull.runId())+1);

		}

		// offset
		QhullHyperplane &hyperplane = facet.hyperplane();
		offsetData.push_back(hyperplane.offset());
		const double *normal = hyperplane.coordinates();

		// normal data
		for(int i1 = 0; i1 < gNumOfDimensions; i1++)
		{

			normalData.push_back(*(normal + i1));

		}

		vector< QhullFacet > &neighboringFacetVector = facet.neighborFacets().toStdVector();
		for(std::vector< QhullFacet >::iterator i1 = neighboringFacetVector.begin(); i1 != neighboringFacetVector.end(); i1++)
		{
			
			QhullFacet &f = *i1;
			neighboringFacetsData.push_back(gFacetIndexMap[f.id()]);

		}

	}


	mwSize arraySize[2];

	arraySize[0] = 1;
	arraySize[1] = 1;
	mxArray *outputStruct = mxCreateStructArray(2,&arraySize[0],gQhullNumOfResStructFields,gQhullResultStructFields);

	// entering data into each field
	mxSetFieldByNumber(outputStruct,0,mxGetFieldNumber(outputStruct,"faces"),MexUtilities::vector_to_mxMatrix(facesData,gNumOfFacets,gNumOfDimensions));
	mxSetFieldByNumber(outputStruct,0,mxGetFieldNumber(outputStruct,"offsets"),MexUtilities::vector_to_mxMatrix(offsetData,gNumOfFacets,1));
	mxSetFieldByNumber(outputStruct,0,mxGetFieldNumber(outputStruct,"normal"),MexUtilities::vector_to_mxMatrix(normalData,gNumOfFacets,gNumOfDimensions));
	mxSetFieldByNumber(outputStruct,0,mxGetFieldNumber(outputStruct,"neighboringFacets"),MexUtilities::vector_to_mxMatrix(neighboringFacetsData,gNumOfFacets,gNumOfDimensions));
	mxSetFieldByNumber(outputStruct,0,mxGetFieldNumber(outputStruct,"area"),MexUtilities::double_to_mxArray(qhull.area()));
	mxSetFieldByNumber(outputStruct,0,mxGetFieldNumber(outputStruct,"volume"),MexUtilities::double_to_mxArray(qhull.volume()));

	return outputStruct;

}

mxArray* gatherRboxResults(orgQhull::RboxPoints &rbox)
{

	mwSize arraySize[2];

	arraySize[0] = 1;
	arraySize[1] = 1;
	mxArray *outputStruct = mxCreateStructArray(2,&arraySize[0],gRboxNumOfResStructFields,gRboxResultStructFields);

	// entering data into each field
	mxSetFieldByNumber(outputStruct,0,mxGetFieldNumber(outputStruct,"vertices"),MexUtilities::doubleArray_to_mxMatrix(rbox.coordinates(),rbox.count(),rbox.dimension()));

	return outputStruct;

}
	
