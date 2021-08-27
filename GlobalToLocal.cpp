#include "generic.h"
/**********************************************************************************************
Global to Local Element - James Snuggs
Summer 2021 - Development of a 3D Unstructured Flow Solver

**********************************************************************************************/

/*In order to get a global element number (gelem) given a local element number (ielem) and element type (etype), we just do the following:*/

void GlobalToLocal(int gelem, int nelem[],int* ielem,int* etype)
{
  // Given a global element number (gelem), we do the opposite to get the local element number (ielem) and element type (etype):      

   *ielem = gelem;
  
   for (ElemType e = Triangle; e <= Hex; e++)            
    {     
      if (*ielem <= nelem[e])            
      {                 
         *etype = e;
        break;     
      }
      else                 
      {                          
        *ielem -= nelem[e];   // equal to: ielem = ielem - nelem[e];                
      }             
      
    }
  
}
