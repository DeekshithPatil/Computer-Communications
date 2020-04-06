#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{   char d[100]="",s[200]="",temp[]="",m[100]="";
    int i,l,j=0;
    printf("Enter input \n");
    scanf("%s",d);
    printf("\n%s\n",d);
    l=strlen(d);
    printf("stringlength is %d",l);
    for(i=0;i<l;i++)
    {
        if(d[i]=='f')
        {
            s[j]='f';
            j++;
            s[j]='f';
            j++;
            //temp[0]=d[i];
            //strcat(s,temp);
            //printf("%s",s);
        }
        else if(d[i]=='e')
        {
            s[j]='e';
            j++;
            s[j]='e';
            j++;

            //temp[0]=d[i];
            //strcat(s,temp);
            //printf("%s",s);
        }
        else
        {
            s[j]=d[i];
            j++;
            //temp[0]=d[i];
            //strcat(s,temp);
            //printf("%s",s);
        }


    }
    printf("output of stuffing is %s: ",s);
    l=strlen(s);
    printf("\nLength of output string is: %d",l);
    j=0;
    for(i=0;i<l;i++)
    {

        if((s[i]=='f'))
        {   if(s[i+1]=='f')
            {
                m[j]='f';
                j++;
            }

        }
        else if(s[i]=='e')
        {
            if(s[i+1]=='e')
            {
                m[j]='e';
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;

        }
         printf("\nOutput of destuffed array is: %s",m);


    }
    printf("\nOutput of destuffed array is: %s",m);


    return 0;

}
