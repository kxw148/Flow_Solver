#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define NUMBER_OF_ELEM_TYPES 7
typedef int ElemType;
#define Invalid_Element_Type -1
#define Edge     0
#define Triangle 1
#define Quad     2
#define Tet      3
#define Pyramid  4
#define Prism    5
#define Hex      6

#define MAX_ELEM_FACES 6
#define MAX_ELEM_EDGES 12
#define MAX_MNODE 8

#define Invalid_Element -999

#define ASSERT(x) {assert(x);}

#define UNSIO_FLOWTYPE_UNKNOWN        -1
#define UNSIO_FLOWTYPE_INCOMPRESSIBLE 0
#define UNSIO_FLOWTYPE_COMPRESSIBLE   1
#define UNSIO_FLOWTYPE_VARMACHRUP     2

// Some function prototypes

int ElemTypeToMnode(ElemType e);
int ElemTypeToFace(ElemType e); 
int ElemTypetoEdge(ElemType e);
void TranslateElementWinding(int *nodes, 
                             int translation[NUMBER_OF_ELEM_TYPES][MAX_MNODE],
                             ElemType etype, int to_other_format);
int DetectNumberOfSurfaceTags(const int nelem[],
                              const int* const ifactag[],
                              int **taglist, int *maxtag_);
int IsInList(const int *list, const int nlist, const int item, int *loc);

typedef struct {
  double mach_number;
  double reynolds_number;
  double angle_of_attack;
  double elapsed_time;
} FlowParameters;

int Read_asciiugrid_Grid(FILE *fp,
			 int *nnodes,
			 int nelem[],
			 double**xyz,
			 int*c2n[],
			 int*factag[]
			 );

int Write_Fieldview_Grid(const char *filename,
			 FILE *fp,
			 const int nnodes,
			 const int nelem[],
			 const double *xyz,
			 const int * const c2n[],
			 const int * const factag[],
			 const int nID,
			 const int * IDs,
			 const char* const *names,
			 const int nvariables,
			 const int flowtype_,
			 const FlowParameters *flp,
			 const double *qvars,
			 const int nbvariables,
			 const double * const bvariables[]
			 );


int compare_ints(const void* a, const void* b);
void GlobalToLocal(int gelem, int nelem[],int* ielem,int* etype);
int LocalToGlobal(ElemType etype,int nelem[],int ielem);
 
void ESP(int nnodes, int nelem[], const int* const c2n[],int* nesp, int** esp);
void PSP(int nnodes, int nelem[], const int * const c2n[], int nesp[],int esp[],int* npsp, int** psp);
void E2N(int nnodes, int psp[],int npsp[], int* e2n, int* nedge); 
void ESE(int nnodes, int nelem[], int esp[], int nesp[], const int* const c2n[],int** ese);
void E2E(int nnodes, int nedge, int nelem[], int npsp [] , int psp[], int e2n[] );
void ESN(int nnodes, int nedge, int nelem[], int npsp [] , int psp[], int e2n[] );


