#include "generic.h"
/**********************************************************************************************
Element Surrounding a Point "ESP" - James Snuggs
Summer 2021 - Development of a 3D Unstructured Flow Solver

 * Input:  Number of nodes (nnodes)
 * Input:  Number of elements (nelem[])
 * Input:  Element connectivity (*c2n[])
 * Output: An index array nnodes + 2 long (nesp[])
 * Output: List of elements surrounding a node (esp[]) 
**********************************************************************************************/

void ESP(int nnodes, int nelem[], const int * const c2n[], int* nesp, int** esp )
{
   
   
    int mnode, inode;
    int node;
    int nespi;
    int count=0;
   int counter=0;
   int counts=1;   
    // (1)Initialize nesp to 0.   
    // (2)Fill in the entries for nesp
    
    for (ElemType etype = Triangle; etype <= Hex; etype ++)
    {
        mnode = ElemTypeToMnode(etype);
        for(int ielem = 1; ielem <= nelem[etype]; ielem++)
        {
            for (inode =0; inode < mnode; inode++)
            {
               node = c2n[etype][mnode*ielem + inode];
               nesp[node + 1]++; 
               count++;
	      //std::cout<< " this is nesp nodes + 1 = "<<nesp[node+1]<<std::endl; 
            }
        }
    }
    //(3)Generate the offsets for the CRS array
    for (int i = 2; i <= (nnodes + 1); i++)
    {
        nesp[i] += nesp[i - 1];
	std::cout<<counts<<"nesp cleaned up "<<nesp[i]<<"this is i = " <<i<<std::endl;  
    counts++;
    }

    
   //(4)Allocate storage for esp  --  esp will be nesp[nnodes + 1] long 
       int indx;
       *esp=(int*)calloc(nesp[nnodes+1],sizeof(int));
      //printf("this is pointer of esp %p\n",*esp); 
      //std::cout<<"this is nnodes +1 = "<<nesp[nnodes+1]<<std::endl; 
    //(5)Repeat Step (2) above, but store data
      for (ElemType etype = Triangle; etype <= Hex; etype++) 
      {
          mnode=ElemTypeToMnode(etype); 
        for (int ielem = 1; ielem <= nelem[etype]; ielem++)  
        {
            for (inode = 0; inode <  mnode; inode++ ) 
            {
                node = c2n[etype][mnode*ielem + inode];
                indx = nesp[node];
		//printf("etype=%d this is ielem = %d, inode = %d, node = %d, index = %d\n",etype, ielem,inode,node,indx); 
               (*esp)[indx] = LocalToGlobal(etype, nelem, ielem);
                nesp[node]++; 
            }
        }
      }
      
 //(6)The CRS indices are shifted by 1 after Step (5), so shift them backLoop over nodes
    for (int i =(nnodes+1); i >= 1; i--)  
    {
        nesp[i] = nesp[i - 1];
	//std::cout<<nesp[i]<<std::endl;
    }
 //In order to access the list of elements surrounding a point, do the following:  
   for (int i = 0; i<= (nnodes+1); i++)
    {
        int indx1 = nesp[i + 0];    
        int indx2 = nesp[i + 1]; 
        for (indx = indx1; indx < indx2; indx++) 
        {
	    int gelem = (*esp)[indx];
	   //printf("this is gelem = %d, this is node %d", gelem, i);
        }
   
    }
   //printf("I successfully ran ESP.cpp\n");
}
