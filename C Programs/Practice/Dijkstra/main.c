#include <stdio.h>
#include <stdlib.h>

#define infinity 9999
#define max 10

int dij(int g[max][max],int n,int startnode);

int main()
{
   int g[max][max],i,j,n,u;
   printf("Enter Number of nodes: ");
   scanf("%d",&n);
   printf("Enter the distance matrix: \n");
   for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           scanf("%d",&g[i][j]);
       }
   }
   printf("\nEnter the node: ");
   scanf("%d",&u);
   dij(g,n,u);
}
int dij(int g[max][max],int n,int startnode)
{
    int cost[max][max],dist[max],visited[max],i,j,count,mindistance,nextnode;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(g[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=g[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        dist[i]=cost[startnode][i];
        visited[i]=0;
    }
    visited[startnode]=1;
    dist[startnode]=0;
    count=1;
    while(count<n-1)
    {
        mindistance=infinity;
        for(i=0;i<n;i++)
        {
            if((dist[i]<mindistance)&&! visited[i])
            {
                mindistance=dist[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
        {
            if((mindistance+cost[nextnode][i]<dist[i])&&!visited[i])
            {
                dist[i]=mindistance+cost[nextnode][i];
            }
        }
        count++;
    }
    for(i=0;i<n;i++)
    {
        if(i!=startnode)
        {
            printf("\nDistance of %d=%d",i,dist[i]);
        }
    }
}
