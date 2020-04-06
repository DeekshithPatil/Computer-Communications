#include<stdio.h>
#include<string.h>

int main()
{   char d[100]="";
    char s[100]="";
    char de[100]="";
    int i,j,l;

    printf("Enter the string: \n");
    gets(d);
    printf("\nEntered array is: %s",d);
    l=strlen(d);
    printf("\n Length of entered array is %d",l);
    j=0;
    for(i=0;i<l;i++)
    {
        if(d[i]=='f')
        {
            s[j]='f';
            j++;
            s[j]='f';
            j++;
        }
        else if(d[i]=='e')
        {
            s[j]='e';
            j++;
            s[j]='e';
            j++;
        }
        else
        {
            s[j]=d[i];
            j++;
        }
    }
    printf("\nOutput: %s",s);
    l=strlen(s);
    j=0;
    for(i=0;i<l;i++)
    {
        if(s[i]=='f')
        {
            if(s[i+1]=='f')
            {
                de[j]='f';
                j++;
            }
        }
        else if(s[i]=='e')
        {
            if(s[i+1]=='e')
            {
                de[j]='e';
                j++;
            }
        }
        else
        {
            de[j]=s[i];
            j++;
        }
    }
    printf("\nOUTPUT: %s",de);
}
