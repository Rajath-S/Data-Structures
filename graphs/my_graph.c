//dfs using adjacency matrix
#include<stdio.h>
#include<stdlib.h>
#define MAXVERTEX 100
typedef int Adjmatrix[MAXVERTEX][MAXVERTEX];
typedef struct graph
{
  int num_vertices;
  Adjmatrix A;
  int visit[MAXVERTEX];
}Graph;
 Graph* creategraph();
void print_g(Graph*);
void dfs(Graph*,int);
int main()
{
  //int i,v,k;

  //printf("Enter the number of vertices..");
  //scanf("%d",&n);

  Graph* G=creategraph();
  print_g(G);
  while(1)
  {
  printf("Enter the source vertex..\n");
  int v;
  scanf("%d",&v);
  if(v==0)
    break;
  printf("The vertices reachable from %d using DFS are..\n",v);
  dfs(G,v);
  
}

  /*
  printf("Enter the source vertex..\n");
  scanf("%d",&v);
  printf("The vertices reachable from %d using DFS are..\n",v);
  dfs(v);
*/
 }
void dfs(Graph* G,int source)
{
  G->visit[source]=1;
  printf("%d",source);
  for(int w=1;w<=G->num_vertices;w++)
  {
    if(G->A[source][w]==1 && G->visit[w]==0)
      dfs(G,w);
  }
}
 void print_g(Graph* G)
 {
   printf("num_vertices=%d\n",G->num_vertices);
   printf("visit array is \n");
   for(int i=0;i<=G->num_vertices;i++)
   {
     printf(" %d ",G->visit[i]);
   }
   printf("\n");
   printf("Adjacency matrix is \n");
   for(int i=0;i<=G->num_vertices;i++)
   {
     for(int j=0;j<=G->num_vertices;j++)
     {
       printf(" %d ",G->A[i][j]);
     }
     printf("\n");
 }
}

 Graph* creategraph()
 {
   Graph* G=(Graph*) malloc(sizeof(Graph));
   printf("Enter the number of vertices..");
   scanf("%d",&G->num_vertices);
   int source,dest;
  printf("Enter the source and destination vertices..\n");
   while(1)
   {
     scanf("%d %d",&source,&dest);
     if(source==0&&dest==0)
       break;
     G->A[source][dest]=1;
   }
   printf("ending graph creation\n");
   return G;

   }

   //printf(sizeof(Graph));
