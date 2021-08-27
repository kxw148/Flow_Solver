#include "generic.h" 


//edge surrounding node

//tri
int node1edgetri[3]={2,0,2}; 
int node2edgetri[3]={2,1,0}; 
int node3edgetri[3]={2,2,1}; 
int* nodetoedgetri[3]={node1edgetri,node2edgetri,node3edgetri}; 


//quad 
int node1edgequad[3]={2,0,3}; 
int node2edgequad[3]={2,1,0};
int node3edgequad[3]={2,2,1}; 
int node4edgequad[3]={2,3,2};
int* nodetoedgequad[4]={node1edgequad,node2edgequad,node3edgequad,node4edgequad}; 

//tet
int node1edgetet[4]={3,1,0,2}; 
int node2edgetet[4]={3,1,3,4}; 
int node3edgetet[4]={3,3,1,5}; 
int node4edgetet[4]={3,2,5,4}; 
int* nodetoedgetet[4]={node1edgetet,node2edgetet,node3edgetet,node4edgetet}; 

//pyramid 
int node1edgepyr[4]={3,1,0,2}; 
int node2edgepyr[4]={3,0,3,4}; 
int node3edgepyr[4]={3,3,5,6}; 
int node4edgepyr[4]={3,5,1,7}; 
int node5edgepyr[5]={4,2,7,6,4};
int* nodetoedgepyr[5]={node1edgepyr,node2edgepyr,node3edgepyr,node4edgepyr,node5edgepyr}; 

//prism 
int node1edgepr[4]={3,1,0,2};  
int node2edgepr[4]={3,0,3,4}; 
int node3edgepr[4]={3,3,1,5};
int node4edgepr[4]={3,6,8,4}; 
int node5edgepr[4]={3,6,8,4};
int node6edgepr[4]={3,8,7,5}; 
int* nodetoedgepr[6]={node1edgepr,node2edgepr,node3edgepr,node4edgepr,node5edgepr,node6edgepr}; 


//hex 
int node1edgehex[4]={3,1,0,2}; 
int node2edgehex[4]={3,0,3,4}; 
int node3edgehex[4]={3,3,5,6};
int node4edgehex[4]={3,5,1,7};
int node5edgehex[4]={3,9,8,2};
int node6edgehex[4]={3,8,10,4};
int node7edgehex[4]={3,10,11,6};
int node8edgehex[4]={3,11,9,7}; 
int* nodetoedgehex[8]={node1edgehex,node2edgehex,node3edgehex,node4edgehex,node5edgehex,node6edgehex,node7edgehex,node8edgehex}; 
int** nodetoedge[6]={nodetoedgetri,nodetoedgequad,nodetoedgetet,nodetoedgepyr,nodetoedgepr,nodetoedgehex}; 



void E2E(int nnodes, int nedge, int nelem[], int npsp [] , int psp[], int e2n[] )
{
int iedge=0;
int inode; 
int indx1; 
int indx2; 
int indx; 
int gelem;
int elem_edge=0;
int temp_edge; 
int local_edge;
int mnode;  
int z=0; 
int etype; 
int ielem; 
int E2E; 
for (iedge; iedge<nedge; iedge++)
{
    for(inode=1; inode<=nnodes; inode++)
    {
        indx1=npsp[inode-1];
        indx2=npsp[inode+0]; 
        for(indx=indx1; indx<indx2; indx++)
        {
         gelem=psp[indx]; 
         GlobalToLocal(gelem,nelem,&etype,&ielem);
         mnode=ElemTypeToMnode(etype);
         for(elem_edge; elem_edge<mnode; elem_edge++)
         {
             temp_edge=e2n[mnode*ielem+elem_edge];
             if(iedge=temp_edge)
             {
                 local_edge=elem_edge; 
                 for (z; z>nodetoedge[etype-1][elem_edge][0]; z++)
                 {
                     E2E=e2n[mnode*ielem+nodetoedge[etype-1][elem_edge][z+1]];
                     printf("this is E2E = %d\n",E2E);
                 }
             }


         }
         
        
        
        }


    }



}











} 	
