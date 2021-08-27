#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include "generic.h"


int main()
{
  // Variables needed for reading in a grid
  
 
  int nnodes;
  int nelem[NUMBER_OF_ELEM_TYPES];
  int *c2n[NUMBER_OF_ELEM_TYPES] = {NULL, NULL, NULL, NULL, NULL, NULL};
  int *factag[NUMBER_OF_ELEM_TYPES] = {NULL, NULL, NULL, NULL, NULL, NULL};
  double *xyz = NULL;
  FILE *fp_in = NULL;
  int i; 
  int counting=0; 
  int test=0;
  // Grid to read in

  fp_in = fopen("13-node-orig.ugrid","r");
  
  // Read in the grid (ugrid format)

  Read_asciiugrid_Grid(fp_in, &nnodes, nelem, &xyz, c2n, factag);
  
  fclose(fp_in);
  

  // Write out the grid (Fieldview format)

  Write_Fieldview_Grid("test.b4.fv", NULL, nnodes, nelem, xyz, c2n, factag,
		       0, NULL, NULL, 0, -1, NULL, NULL, 0, NULL);
  int* nesp = (int*)calloc((nnodes+2),sizeof(int));
  int* esp = NULL;
  int* npsp=(int*)calloc((nnodes+2),sizeof(int));
  int* psp=NULL;
  int* ese=NULL; 
  int*** edge=NULL; 




printf("\n******************* this is ESP********************\n"); 
ESP(nnodes, nelem, c2n, nesp, &esp);
 for (int i = 0; i<= (nnodes+1); i++) 
    { 
        int indx; 
        int indx1 = nesp[i + 0];
        int indx2 = nesp[i + 1]; 
        for (indx = indx1; indx < indx2; indx++) 
        {
            int gelem = esp[indx];
           printf("this is indx1 %d and this is indx2 %d this is gelem = %d, this is node %d\n",indx1,indx2, gelem, i);
        }
    
    }


printf("\n******************* this is PSP********************\n"); 
PSP(nnodes,nelem,c2n,nesp,esp,npsp,&psp);
  for (int j=0; j<= (nnodes+1); j++)//changed here as well 8/16 
 {
   int indxp; 
   int indxp1 = npsp[j+0];
   int indxp2 = npsp[j+1]; 
  for (indxp = indxp1; indxp < indxp2; indxp++)
  {
  
 int point=psp[indxp]; 	 
printf("%d = count this is node %d it is surrounded by node %d in index 1 [j] %d and this is index 2 [j+1] %d\n  ",counting,(j+1), point,indxp1,indxp2); 
counting++; 
  }
} 

printf("\n******************* this is E2N********************\n"); 
int* e2n = (int*)calloc((npsp[nnodes]+2), sizeof(int));
int nedge;
 
E2N(nnodes,psp,npsp,e2n,&nedge);        
  
for (int i=0; i<npsp[nnodes]; i++)
{
printf("this is e2n[%d] = %d\n",i,e2n[i]);
}



printf("\n******************* this is ESE********************\n"); 

ESE(nnodes,nelem,esp,nesp,c2n,&ese);
   
for (int p=0; p<20; p++)
{ 
printf("ese[%d] = %d\n",p,ese[p]); 

}


  std::cout<<" this is the number of edges = "<<nedge<<std::endl; 
  std::cout<<" this is npsp[13] = "<<npsp[13]<<std::endl;
  
E2E(nnodes,nedge,nelem,npsp,psp,e2n); 

printf("\n******************* this is ESN********************\n"); 

ESN(nnodes, nedge, nelem, npsp,psp, e2n);

// Free memory
  free(xyz);
  free(nesp); 
  free(esp);
  free(psp); 
  free(npsp);
  free(e2n);
  free(ese); 
  for (i = 0; i < NUMBER_OF_ELEM_TYPES; i++)
    {
      free(c2n[i]);
      free(factag[i]);
    }

  return 0;
}
