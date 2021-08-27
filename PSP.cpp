#include "generic.h" 
//static triangle 
static int row1tr[3]={2,2,1}; 
static int row2tr[3]={2,0,2}; 
static int row3tr[3]={2,1,0}; 
static int * tri[3]={row1tr,row2tr,row3tr}; 

//static int quad 
static int row1q[3]={2,3,1}; 
static int row2q[3]={2,0,2};
static int row3q[3]={2,1,3}; 
static int row4q[3]={2,2,0}; 
static int * quad[4]={row1q,row2q,row3q,row4q};  

//static int tet 
static int row1t[4]={3,2,1,3};
static int row2t[4]={3,0,2,3}; 
static int row3t[4]={3,1,0,3};
static int row4t[4]={3,2,1,0}; 
static int * tet[4]={row1t,row2t,row3t,row4t}; 

//static int pyramid 
static int row1py[4]={3,3,1,4};  
static int row2py[4]={3,0,2,4}; 
static int row3py[4]={3,1,3,4}; 
static int row4py[4]={3,2,0,4}; 
static int row5py[5]={4,0,3,2,1}; 
static int * pyramid[5]={row1py,row2py,row3py,row4py,row5py}; 

//static int prism 
static int row1pr[4]={3,2,1,3}; 
static int row2pr[4]={3,0,2,4};
static int row3pr[4]={3,1,0,5}; 
static int row4pr[4]={3,5,4,0}; 
static int row5pr[4]={3,3,5,1}; 
static int row6pr[4]={3,4,3,2}; 
static int * prism[6]={row1pr,row2pr,row3pr,row4pr,row5pr,row6pr}; 

//static int hex 
static int row1h[4]={3,3,1,4};
static int row2h[4]={3,0,2,5}; 
static int row3h[4]={3,1,3,6}; 
static int row4h[4]={3,2,0,7};
static int row5h[4]={3,7,5,0};
static int row6h[4]={3,4,6,1}; 
static int row7h[4]={3,5,7,2}; 
static int row8h[4]={3,6,4,3}; 
static int * hex[8]={row1h,row2h,row3h,row4h,row5h,row6h,row7h,row8h};
static int **  node_local[6]={tri,quad,tet,pyramid,prism,hex};

void PSP(int nnodes, int nelem[],const int * const c2n[],int nesp[],int esp[],int* npsp, int** psp)  
{

int indx; 
int indx1;
int indx2; 
int gelem; //global element number 
int inode;//local element number
int ielem;
int etype;
int mnode;//max node value
int lnode;//local node value
int nod; 
int node;
int nodes;
int counts=0;
int psp_node; 
int psp_indx;
int j=0;
int k=0;
int t=0; 
int count=0;
int pindx;
int pindx1;
int pindx2; 
//filling npsp 


for (inode=1; inode<=nnodes; inode++)
 {
    indx1 = nesp[inode + 0];
    indx2 = nesp[inode + 1];
     for (indx = indx1; indx < indx2; indx++)
       {
        gelem = esp[indx];
        GlobalToLocal(gelem,nelem,&ielem,&etype);//ielem & etype are known
        mnode=ElemTypeToMnode(etype);
        for ( nod=0; nod < mnode; nod++)
          {
           node=c2n[etype][mnode*ielem+nod];
           if (inode==node)
             {
               lnode=(nod);
              
        for (int i=0; i< node_local[etype-1][nod][0]; i++)
	{
            nodes=c2n[etype][mnode*ielem + node_local[etype-1][nod][i+1]];
            npsp[nodes+1]++;
	    //printf("%d this is nodes %d\n",counts,npsp[nodes+1]); 	
	} 
            }
         }
      }
 }
     

for (int i=nnodes+1; i>=1; i--) //changed this 16/Aug to see if i could fix npsp index 
{
 npsp[i]=npsp[i-1]; 

 
 //std::cout<<" this is npsp = "<<npsp[i]<<std::endl;

}
std::cout<<"\n\n***********************************************Break**************************************\n\n"<<std::endl; 
(*psp)=(int*)calloc(npsp[nnodes+1],sizeof(int)); //psp type was determined in function call 
int* temp_node=(int*)calloc(150,sizeof(int));
//filling psp
  for (inode=1; inode<=nnodes; inode++) 
     { 
	 
	      indx1 = nesp[inode + 0];
        indx2 = nesp[inode + 1];
      for (indx = indx1; indx < indx2; indx++)
        {
	
	    gelem = esp[indx];
	    GlobalToLocal(gelem,nelem,&ielem,&etype);//ielem & etype are known
	    mnode=ElemTypeToMnode(etype);
            //printf("  the node = %d, the global element number = %d, the element type = %d, the local element numnber = %d, the max node = %d\n",inode,gelem,etype,ielem,mnode);  
		
        for ( nod=0; nod < mnode; nod++) 	    
             {
	     node=c2n[etype][mnode*ielem+nod];  
            if (inode==node)
	       {   
                lnode=(nod);
	      
	        //printf(" %d  thie is the element type %d, this is the local node number %d, and this is the the global node number %d and this is ielem %d\n",inode,etype, lnode, inode, ielem);
	      
		for (int i=0; i< node_local[etype-1][nod][0]; i++) 
	        {
         	  psp_node=c2n[etype][mnode*ielem + node_local[etype-1][nod][i+1]];
	          temp_node[count]=psp_node; 
	          //printf("%d = the count and global node %d and the global element is %d is surrounded by %d\n",count,inode,gelem,temp_node[count]);   
	          count++; 
		}		
	      }
	    }
	 } 	
           
                int* temp=(int*)calloc((count+t),sizeof(int)); 
                for (t; t<count; t++)
		{ 
			temp[t]=temp_node[t];
		        //std::cout<<"this is temp[t] = "<<temp[t]<<std::endl;	
                }
      
                qsort(temp,count,sizeof(int),compare_ints);
                
                int counter =1;  
                for (j; j<count; j++)
		 {
			if(temp[j]!=temp[j+1])
			 { 	
			(*psp)[counts]=temp[j];  
			//printf("%d = count, %d = node and %d sorted psp\n",counts,inode,(*psp)[counts]);
			 counts++; 
			 counter++;
			 }	
		 } 

		npsp[inode]=counter-1;
	     //std::cout<<npsp[inode]<<std::endl;
	       	counter=1;
		
     }	
	       
             for (int i=1; i<=nnodes; i++)
               {
                npsp[i]+=npsp[i-1];
                std::cout<<"this is node = "<<i<<" this is npsp = "<<npsp[i]<<std::endl;

               }          
	           
     
}
	     

 		

