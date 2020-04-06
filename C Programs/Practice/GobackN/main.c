#include<stdio.h>
#include<string.h>

int main()
{
    int window_size,count=0,i,ack;
    printf("Enter the window size: ");
    scanf("%d",&window_size);
    while(1)
    {
        for(i=0;i<window_size;i++)
        {
            printf("\n Frame %d has been transmitted",count);
            count++;
            if(count==window_size)
                break;
        }
        printf("\n Enter the last ack received: ");
        scanf("%d",&ack);

        if(ack==window_size)
            break;
        else
            count=ack;
    }
}
