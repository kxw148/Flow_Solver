#include "generic.h"

//edge from  low node to high node map 
int row1edgetet[3]={2,0,1};
int row2edgetet[3]={2,0,2};
int row3edgetet[3]={2,0,3}; 
int row4edgetet[3]={2,1,2}; 
int row5edgetet[3]={2,1,3}; 
int row6edgetet[3]={2,2,3}; 
int* edgetet[6]={row1edgetet,row2edgetet,row3edgetet,row4edgetet,row5edgetet,row5edgetet}; 

int row1edgepyr[3]={2,0,1}; 
int row2edgepyr[3]={2,0,3}; 
int row3edgepyr[3]={2,0,4}; 
int row4edgepyr[3]={2,1,2}; 
int row5edgepyr[3]={2,1,4}; 
int row6edgepyr[3]={2,2,3}; 
int row7edgepyr[3]={2,2,4}; 
int row8edgepyr[3]={2,3,4}; 
int* edgepyr[8]={row1edgepyr,row2edgepyr,row3edgepyr,row4edgepyr,row5edgepyr,row6edgepyr,row7edgepyr,row8edgepyr}; 

int row1edgepr[3]={2,0,1};
int row2edgepr[3]={2,0,2};
int row3edgepr[3]={2,0,3};
int row4edgepr[3]={2,1,2}; 
int row5edgepr[3]={2,1,4}; 
int row6edgepr[3]={2,2,4}; 
int row7edgepr[3]={2,3,4};
int row8edgepr[3]={2,3,5}; 
int row9edgepr[3]={2,4,5}; 
int* edgepr[9]={row1edgepr,row2edgepr,row3edgepr,row4edgepr,row5edgepr,row6edgepr,row7edgepr,row8edgepr,row9edgepr};

int row1edgehex[3]={2,0,1}; 
int row2edgehex[3]={ 2,0,3}; 
int row3edgehex[3]={2,0,4}; 
int row4edgehex[3]={2,1,2}; 
int row5edgehex[3]={ 2,1,5}; 
int row6edgehex[3]={2,2,3}; 
int row7edgehex[3]={2,2,6}; 
int row8edgehex[3]={2,3,7}; 
int row9edgehex[3]={2,4,5}; 
int row10edgehex[3]={2,4,7}; 
int row11edgehex[3]={2,5,6}; 
int row12edgehex[3]={2,6,7}; 
int* edgehex[12]={row1edgehex,row2edgehex,row3edgehex,row4edgehex,row5edgehex,row6edgehex,row7edgehex,row8edgehex,row9edgehex,row10edgehex,row11edgehex,row12edgehex}; 
int** edge[4]={edgetet,edgepyr,edgepr,edgehex}; 

//edge to face first number is right face second number is left face 
int edge1tet[2]={0,1};
int edge2tet[2]={2,0};
int edge3tet[2]={2,1};
int edge4tet[2]={0,3};
int edge5tet[2]={1,3};
int edge6tet[2]={3,2}; 
int* edgetofacetet[6]={edge1tet,edge2tet,edge3tet,edge4tet,edge5tet,edge6tet};

int edge1pyr[2]={0,1};
int edge2pyr[2]={2,0};
int edge3pyr[2]={2,1};
int edge4pyr[2]={0,3};
int edge5pyr[2]={1,3};
int edge6pyr[2]={0,4};
int edge7pyr[2]={3,4};
int edge8pyr[2]={4,2}; 
int* edgetofacepyr[8]={edge1pyr,edge2pyr,edge3pyr,edge4pyr,edge5pyr,edge6pyr,edge7pyr,edge8pyr}; 

int edge1pr[2]={0,1}; 
int edge2pr[2]={1,0}; 
int edge3pr[2]={2,1}; 
int edge4pr[2]={0,3}; 
int edge5pr[2]={1,3};
int edge6pr[2]={3,2};
int edge7pr[2]={4,1}; 
int edge8pr[2]={2,4}; 
int edge9pr[2]={4,3};
int* edgetofacepr[9]={edge1pr,edge2pr,edge3pr,edge4pr,edge5pr,edge6pr,edge7pr,edge8pr,edge9pr}; 

int edge1hex[2]={0,1}; 
int edge2hex[2]={2,0}; 
int edge3hex[2]={2,1}; 
int edge4hex[2]={0,3}; 
int edge5hex[2]={1,3}; 
int edge6hex[2]={0,4}; 
int edge7hex[2]={3,4}; 
int edge8hex[2]={4,2}; 
int edge9hex[2]={5,1}; 
int edge10hex[2]={2,5}; 
int edge11hex[2]={5,3}; 
int edge12hex[2]={5,4};
int* edgetofacehex[12]={edge1hex,edge2hex,edge3hex,edge4hex,edge5hex,edge6hex,edge7hex,edge8hex,edge9hex,edge10hex,edge11hex,edge12hex};
int** edgetoface[4]={edgetofacetet,edgetofacepyr,edgetofacepr,edgetofacehex}; 




void Dual(int esp[],int nesp[], int nnodes, int nelem[]) 
{ 
int etype; 








} 
