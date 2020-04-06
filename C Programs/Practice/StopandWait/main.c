#include <stdio.h>
#include <stdlib.h>

int n=0,d=0;
int ack=0,sel=0,f=0;

void sender()
{
     printf("\n Sender \n");
    if(f==0)
    {

        up:printf("frame %d has been transmitted\n",d);
    }
    else
    {
        if(f==1&&ack==0)
        {
            printf("Acknowledgemnet for frame %d has been received\n",n);
            n++;
            if(n%2==0)
                d=0;
            else
                d=1;
            goto up;
        }
        else
        {
            printf("Acknowledgement for frame %d has not been received\n",n);
            goto up;
        }
    }
}

void channel1()
{
    printf("\n Forward channel\n");
    printf("Channel Properties:\n 0. Send frame \n1. Send frame with error \n2.Drop frame \n");
    scanf("%d",&sel);
}

void receiver()
{
    printf("\nReceiver\n");
    if(sel==0)
    {
        printf("frame %d has been received\n",d);
        f=1;
    }
    else if(sel==1)
    {
        printf("frame %d has been corrupted\n",d);
        f=0;
    }
    else if(sel==2)
    {
        printf("frame %d has not been received\n",d);
        f=0;
    }
}

void channel2()
{
    printf("\n Reverse channel\n");
    if(f==1)
    {
        printf("Enter channel Property:\n 0.Send ack \n1.Drop ack\n");
        scanf("%d",&ack);
        printf("\n Ack is sent\n");
    }
    else
    {
        printf("\n Nothing to send\n");
        f=0;
        ack=0;
    }
}

int main()
{
    while(1)
    {
        sender();
        channel1();
        receiver();
        channel2();
    }
}
