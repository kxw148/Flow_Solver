#include "generic.h" 



void ESN(int nnodes, int nedge, int nelem[], int npsp [] , int psp[], int e2n[] )
{
    int inode;
    int indx;
    int indx1;
    int indx2; 
    int count = 0;
    int node1; 
    int node2; 
    int global_node; 
    
    
    int (*esn) = (int*)calloc(npsp[nnodes+1],sizeof(int));
    
    
    for (int iedge=0; iedge<nedge; iedge++)//edge loop
    {
        node1 = e2n[2*iedge + 0];
        node2 = e2n[2*iedge + 1];
        
        std::cout<<"\n\n****************************************break*****************************************\n\n"<<std::endl; 
        indx1 = npsp[node1 - 1];
        indx2 = npsp[node1 +0];
        
        for(indx=indx1; indx<indx2; indx++)
           {
           global_node = psp[indx]; //global node number 
           if (global_node == node2) 
           {
               esn[indx] = iedge;
               std::cout<<" this is global node = "<<global_node<<" this is edge 1 = "<<esn[indx]<<std::endl; 
           } 
           }
        
        indx1 = npsp[node2 - 1];
        indx2 = npsp[node2 + 0];
        
        for(indx=indx1; indx<indx2; indx++)
           {
           global_node = psp[indx]; //global node number 
           if (global_node == node1) 
           {
               esn[indx] = iedge;
               std::cout<<" this is global node = "<<global_node<<" this is edge 2 = "<<esn[indx]<<std::endl; 
           }
           }
             
    }






free(esn);

}
