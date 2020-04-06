#include <stdio.h>
#include <stdlib.h>
int n=0,d=0;
int ack=0,sel,f=0;

void sender()
{
    if(f==0)
    {
        printf("\n sender\n");
        up:printf("\n sending frame %d\n",d);
    }
    else
    {
       if((f==1))
       {  if(ack==0)
        {
           printf("\n the ack %d is received ",n);
           n++;
           if(n%2==0)
            d=0;
           else
            d=1;
           goto up;
       }

       }
       else{
        printf("\n Sender\n time out ack %d is not received",n);
        goto up;
       }
    }
}

void channel1()
{
    printf("\n Forward channel\n");
    printf("\ enter transmission type \n 0. send error free frame\n1. semd frame with error\n 2. to drop the frame\n");
    scanf("%d",&sel);
}

void receiver()
{
    printf("\n Receiver\n");
    if(sel==0)
    {
        printf("frame %d recieved \n",d);
        f=1;
    }
    if(sel==1)
    {
        printf("\n frame %d is recieved but corrupted\n",d);
        f=0;
    }
    if(sel==2)
    {
        printf("\n frame %d is not received \n",d);
        f=0;
    }
}

void channel2()
{
    printf("\n Reverse Channel\n");
    if(f=1)
    {
        printf("\n enter the transmission type\n 0. to send the ack \n 1. drop the ack\n ");
        scanf("%d",&ack);
        printf("\n sending the ack...\n");
    }
    else{
        printf("\n nothing to send\n");
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
