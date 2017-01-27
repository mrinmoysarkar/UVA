//#include <iostream.h>
#include <stdio.h>


int arr[10000000];


int cyclelength(int n)
{
    int cl = 1;
    while(1)
    {
        if( n == 1)break;
        n = n%2 == 0?n/2:3*n + 1;
        cl++;
    }
    return cl;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


int i,j;
int sum = 0;

while(scanf("%d %d",&i,&j) != EOF)
{
    int mx = i>j?i:j;
    int mi = i<j?i:j;
    sum = 0;
	for(int l = mi;l<=mx;l++)
	{
	    int cc = cyclelength(l);
	    sum = sum > cc ? sum : cc;
	}
	printf("%d %d %d\n",i,j,sum);
}

printf("\n");

return 0;
}
