#include <stdio.h>
#include <stdlib.h>

#define duration 60
#define bucketsize 30
#define packetrate 20

#define sst 16

//#define cwnd
#define detail

int sender();
int router();
int time=0,total_sent=0,sent=0,dropped=0,total_dropped=0,to_send=0;
int main()
{
    while(time<=duration)
    {
        #if defined (detail) && ! defined (cwnd)
        printf("\n At itme =%d \n",time);
        #endif // defined

        sender();
        router();
        time++;
    }
    #ifndef cwnd
    printf("\n Total packets sent= %d \n",total_sent);
    #endif // cwnd
}
int sender()
{
    static int cwnd=1;
    #if defined (detail) && ! defined (cwnd)
    printf("\n Sender\n");
    printf("\n NO. of packets sent= %d \t dropped= %d \n",sent,dropped);
    #endif // defined
    if(sent>0)
    {
        total_sent +=sent;
        sent=0;
        if(cwnd<sst)
            cwnd=cwnd*2;
        else
            cwnd=cwnd+1;
        if(dropped>0)
        {
            total_dropped+=dropped;
            dropped=0;
            cwnd=1;
        }
    }
    to_send=cwnd;
    #ifdef cwnd
    printf("\n time=%d,cwnd=%d ")
    #endif // cwnd
    #if defined (detail) && ! defined (cwnd)
    printf("\n cwnd = %d \n",cwnd);
    #endif // defined
}

int router()
{
    static int buffer=0;
    dropped=0;
    #if defined (detail) && ! defined (cwnd)
    printf("\n At router\n");
    printf("\n Remaining in buffer= %d\t new from sender+%d \n",buffer,to_send);
    #endif // defined
    buffer=buffer+to_send;
    if(buffer<=packetrate)
    {
        sent=buffer;
        buffer=0;
    }
    else
    {
        sent=packetrate;
        buffer=buffer-packetrate;
        if(buffer>bucketsize)
        {
            dropped=buffer-bucketsize;
            buffer=bucketsize;
        }
    }
    #if defined (detail) && ! defined (cwnd)
    printf("sent= %d dropped=%d \n",sent,dropped);
    #endif // defined
}
