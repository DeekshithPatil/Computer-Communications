#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dist[20];
    int from[20];
}rt[20];

int main()
{
    int n,i,j,k,cost[20][20],count;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            cost[i][i]=0;
            rt[i].dist[j]=cost[i][j];
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
                    if(rt[i].dist[j]>cost[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j]=cost[i][k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0);

    for(i=0;i<n;i++)
    {
        printf("\n Routing Table of Router %d is:\n Dest\tNext Hop\tDistance\n",i+1);
        for(j=0;j<n;j++)
        {
            printf("%d\t%d\t\t%d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }

    }
}
