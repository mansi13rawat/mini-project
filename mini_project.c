#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

char* givesum(char a[], char b[])
{
    int size1=strlen(a)-1;
    int size2=strlen(b)-1;
    int i=0;
    for (i = 0; i < (size1 + 1) / 2; i++)
    {
        char temp = a[i];
        a[i] = a[size1 - i];
        a[size1 - i] = temp;

    }


    int num=0;
    int extra=0;
    static char final[20000];
    int size=0;


    for(i=0;i<=size1;i++)
    {
        if(i<=size2)
        {
            num=(a[i]-'0')+(b[i]-'0');
        }
        else
        {
            num=a[i]-'0';
        }

        final[i]=((num+extra)%10)+'0';
        size++;
        extra=(extra+num)/10;

    }
    while(extra!=0)
    {
        final[i]=(extra%10)+'0';
        size++;
        extra=extra/10;
        i++;
    }

    for(int i=0;i<size/2;i++)
    {
        char temp=final[i];
        final[i]=final[size-1-i];
        final[size-1-i]=temp;
    }


    return(final);
}

void noat(int n)
{
    static int size = 2;
    static char data[20002][20000] = {"0", "1"};

    if (n < size)
    {
        printf("at index %d of series is: %s\n",n, strrev(data[n]));
    }
    else
    {
        for (int i = size - 1; i < n; i++)
        {
            strcpy(data[size], givesum(data[i], data[i - 1]));
            size++;
        }

        printf("at index %d of the series is: %s\n",n,data[n]);
    }
}

int main()
{
    /*
            0  1  1  2  3  5  8  13  21  34  55  89
      index 0  1  2  3  4  5  6  7   8   9   10  11
    */
    int n;
    printf("enter index: ");
    scanf("%d",&n);

    noat(n);
    return (0);
}