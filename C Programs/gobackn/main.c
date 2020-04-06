#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,windowsize,sent=0,ack;
    printf("Enter the window size: ");
    scanf("%d",&windowsize);
    while(1)
    {
        for(i=0;i<windowsize;i++)
        {
            printf("Frame %d has been sent\n",sent);
            sent++;
            if (sent==windowsize)
            {
                break;
            }
        }
        printf("please enter the last acknowledgment that was received: ");
        scanf("%d",&ack);
        if(ack==windowsize)
            break;
        else
            sent=ack;
    }
}
