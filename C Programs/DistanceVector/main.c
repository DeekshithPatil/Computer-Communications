#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dist[20];
    int from[20];
}rt[10];

int main()
{   int n,i,j,k,count,distance_matrix[20][20];

    printf("enter the number of nodes: ");
    scanf("%d",&n);
    printf("\n Enter the cost or distance matrisx:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&distance_matrix[i][j]);
            distance_matrix[i][i]=0;
            rt[i].dist[j]=distance_matrix[i][j];
            rt[i].from[j]=j;
        }
    }
    do
    {
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(rt[i].dist[j]>distance_matrix[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }

            }
        }



    }while(count!=0);
    for(i=0;i<n;i++)
    {
        printf("Routing table for %d \n Dest\tNextHop\tDist\n",i+1);
        for(j=0;j<n;j++)
            printf("%d\t%d\t%d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
    }


}


