#include "generic.h"
/**********************************************************************************************
Local to Global Element - James Snuggs
Summer 2021 - Development of a 3D Unstructured Flow Solver

**********************************************************************************************/

/*In order to get a global element number (gelem) given a local element number (ielem) and element type (etype), we just do the following:*/


int LocalToGlobal(ElemType etype, int nelem[], int ielem)
{
   
 int gelem = ielem; 
  
  for (ElemType e = Triangle; e < etype; e++) 
  {
    gelem += nelem[e]; // equal to: gelem = gelem + nelem[e];     
    
  }
    return gelem;
}
