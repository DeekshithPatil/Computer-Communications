#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char input[100],key[30],temp[100],key1[30],quot[100],rem[30];
    int keylen,msglen,i,j;
    printf("Enter the data: ");
    gets(input);
    msglen=strlen(input);
    printf("\nEnter the key: ");
    gets(key);
    keylen=strlen(key);
    strcpy(key1,key);
    for(i=0;i<keylen-1;i++)
        input[msglen+i]='0';
    for(i=0;i<keylen;i++)
        temp[i]=input[i];
    for(i=0;i<msglen;i++)
    {
        quot[i]=temp[0];
        if(temp[0]=='0')
            for(j=0;j<keylen;j++)
                key[j]='0';
        else
            for(j=0;j<keylen;j++)
                key[j]=key1[j];
        for(j=keylen-1;j>0;j--)
        {
            if(temp[j]==key[j])
                rem[j-1]='0';
            else
                rem[j-1]='1';
        }
        rem[keylen-1]=input[i+keylen];
        strcpy(temp,rem);

    }
    printf("\nOutput: ");
    for(j=0;j<keylen-1;j++)
        printf("%c",rem[j]);
}
