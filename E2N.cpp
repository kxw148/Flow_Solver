#include "generic.h"
void E2N(int nnodes, int* psp, int* npsp,int* e2n,int* nedge) 
{
*nedge=0;
int jnode; 
int inode; 
int indxp; 
int indxp1; 
int indxp2; 
int e2n_count=0; 
 for (inode=1; inode<=nnodes; inode++) //continueing edits 8/16
  {
    indxp;
    indxp1 = npsp[inode-1];
    indxp2 = npsp[inode];
  for (indxp = indxp1; indxp < indxp2; indxp++)
  {
   jnode=psp[indxp];
   //printf("psp  = %d this is node %d this is npsp[j] %d and npsp[j-1] %d\n  ",jnode, inode,npsp[inode],npsp[inode-1]); 
  if(jnode > inode) 
   {
    (*nedge)++; 
    e2n[2*(*nedge)+0]=inode; 
    e2n[2*(*nedge)+1]=jnode;
  printf("%d inode = %d, jnode = %d\n",e2n_count,inode,jnode); 
   e2n_count++;  
   }
   
   }

  }
for (int t=2; t<(npsp[nnodes]+2); t++)
{
e2n[t-2]=e2n[t]; 
}

 } 
 
  

