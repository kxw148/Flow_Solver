#include "generic.h" 
//face map
static int triface1[4]={3,0,1,2};

static int* triangleface[3] = {triface1};

static int quadface1[5] = {4,0,1,2,3};

static int* quadface[4] = { quadface1};


static int tetface1[4] = {3,0,1,2};
static int tetface2[4] = {3,0,3,1};
static int tetface3[4] = {3,0,2,3};
static int tetface4[4] = {3,1,3,2};
static int* tetface[4] = { tetface1,tetface2,tetface3,tetface4 };

static int pryface1[5] = {4,0,1,2,3};
static int pryface2[4] = {3,0,4,1}; 
static int pryface3[4] = {3,0,3,4}; 
static int pryface4[4] = {3,1,4,2};
static int pryface5[4] = {3,2,4,3}; 
static int* pryface[5] = {pryface1, pryface2, pryface3, pryface4, pryface5};


static int prismface1[4] = {3,0,1,2};
static int prismface2[5] = {4,0,3,4,1};
static int prismface3[5] = {4,0,2,5,3};
static int prismface4[5] = {4,1,4,5,2};
static int prismface5[4] = {3,3,5,4}; 
static int* prismface[5] = { prismface1,prismface2,prismface3,prismface4,prismface5 };

static int hexface1[5] = {4,0,1,2,3};
static int hexface2[5] = {4,0,4,5,1};
static int hexface3[5] = {4,0,3,7,4};
static int hexface4[5] = {4,1,5,6,2};
static int hexface5[5] = {4,2,6,7,3};
static int hexface6[5] = {4,4,7,6,5};
static int* hexface[6] = { hexface1,hexface2,hexface3,hexface4,hexface5,hexface6 };

static int** face[6] = { triangleface,quadface,tetface,pryface,prismface,hexface };
 

void ESE(int nnodes, int nelem[], int esp[], int nesp[], const int* const c2n[], int **ese) 
{
int size=(nelem[3]*4+nelem[4]*5*5+nelem[5]*5*6+nelem[6]*6*8);
(*ese)=(int*)calloc(size,sizeof(int)); 
int etype; 
int ielem; 
int mface;
int mnode;
int elem_face;
int count=0;
int counter=0; 
int i;
int temp_node;
int* temp_array=(int*)calloc(100,sizeof(int));
int j=0; 
int gelem; 
int indx; 
int indx1;
int indx2;
int counts=0;
int t=0;
int kcounts=0;
int k =0;
int l=0;  
int ese_counts=0; 
int testcount=0;
int hits=1;
int m=1;  
int ese_count=0; 

for (etype=Tet; etype <= Hex; etype++) 
{	
  for(ielem=1; ielem <= nelem[etype]; ielem++)  
  {	  
        mnode=ElemTypeToMnode(etype);
        mface=ElemTypeToFace(etype);
    for (elem_face=0; elem_face < mface; elem_face++) //face loop
     {          
       int* temp_array2=(int*)calloc(1000,sizeof(int));
       for(i=0; i<face[etype-1][elem_face][0]; i++)
       {
         temp_node=c2n[etype][ielem*mnode+face[etype-1][elem_face][i+1]]; 
         temp_array[count]=temp_node; 
         //printf( "%d  this is etype = %d this is the the elements face %d this is the ielem %d this is the global node %d\n",count,etype,elem_face,ielem,temp_array[count]);
                
        indx1=nesp[temp_array[count]];
        indx2=nesp[temp_array[count]+1];
        //std::cout<<" this is count = "<<j<< " this is indx1 = "<<indx1<<" this is indx2 = "<<indx2<< " this is temp_array[j] = "<<temp_array[count]<<std::endl; 
          for(indx=indx1; indx<indx2; indx++)
              { 
               gelem=esp[indx]; //elems surrounding each point 
		           temp_array2[testcount]=gelem;
              //std::cout<<count<<" This is the global node number = "<<temp_array[count]<<" this is the global element number = " <<temp_array2[testcount]<< " this is etype = "<<etype<< " this is the face = " <<elem_face<<" testcount: "<<testcount<<std::endl;
	             testcount++;
              }
          count++; 
        }

        int current_gelem=LocalToGlobal(etype,nelem,ielem);//find current global element number 
        //std::cout<<"this is current gelem = "<<current_gelem<<" and this is the count: "<<testcount<<std::endl; 
        qsort(temp_array2,testcount,sizeof(int),compare_ints); 
 
        for (m; m<=testcount; m++) //this for loop searches for faces occuring either 3 or 4 times to determine if faces touch one another  
	      {   
           
           if (temp_array2[m]==temp_array2[m-1] && temp_array2[m]!=current_gelem)  
	          { 
                //printf("%d = number of hits %d temp_array2[m-1]= %d\n ",hits, m,temp_array2[m-1]);//temp_array2[m-1]);
                hits++;
            if(hits==face[etype-1][elem_face][0])
	            {
		          //std::cout<<ese_count<<" = ese_counts and equals number of hits " << hits <<" these meet the nesscary amount of hits"<<temp_array2[m]<<std::endl;
		          (*ese)[ese_count]=temp_array2[m];
              ese_count++; 
              }  
            }else
            {
              hits=1; 
            } 
          }
      }
  }
} 
}
   

