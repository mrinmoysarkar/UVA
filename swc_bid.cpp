#include<stdio.h>

#define MAX_INDX 100
int used[MAX_INDX];
int A[MAX_INDX][4];
int ui;
int N,C;
int max;
int isin(int x)
{
    for(int i=0;i<N;i++)
    {
        if(used[i] == x) return 1;
    }
    return 0;
}

int func(int r, int profit)
{
    if(r == C)
    {
        return max = profit > max ? profit : max;
    }
    int d1=0,d2=0,d3=0,d4=0;
    
    if(!isin(A[r][0]) && !isin(A[r][1]))
    {
        used[ui++] = A[r][0];
        used[ui++] = A[r][1];
        int rate = A[r][3];
        int p = A[r][0] * rate + A[r][1] * rate - 100;
        d1 = func(r+1,profit+p);
        used[--ui] = 0;
        used[--ui] = 0;
    }
    
    if(!isin(A[r][1]) && !isin(A[r][2]))
    {
        used[ui++] = A[r][1];
        used[ui++] = A[r][2];
        int rate = A[r][3];
        int p = A[r][1] * rate + A[r][2] * rate - 100;
        d2 = func(r+1,profit+p);
        used[--ui] = 0;
        used[--ui] = 0;
    }
    if(!isin(A[r][0]) && !isin(A[r][2]))
    {
        used[ui++] = A[r][0];
        used[ui++] = A[r][2];
        int rate = A[r][3];
        int p = A[r][0] * rate + A[r][2] * rate - 100;
        d3 = func(r+1,profit+p);
        used[--ui] = 0;
        used[--ui] = 0;
    }
    
    if(!isin(A[r][0]) && !isin(A[r][1]) && !isin(A[r][2]))
    {
        used[ui++] = A[r][0];
        used[ui++] = A[r][1];
        used[ui++] = A[r][2];
        int rate = A[r][3];
        int p = A[r][0] * rate + A[r][1] * rate + A[r][2] * rate - 150;
        d4 = func(r+1,profit+p);
        used[--ui] = 0;
        used[--ui] = 0;
        used[--ui] = 0;
    }
    int d5 = func(r+1,profit);
    
    
    max = max > d1?max:d1;
    max = max > d2?max:d2;
    max = max > d3?max:d3;
    max = max > d4?max:d4;
    max = max > d5?max:d5;

    return max;
    
}
int main()
{
    freopen("input.txt","r",stdin);
    
    scanf("%d %d",&N, &C);
    for(int i=0;i<C;i++)for(int j=0;j<4;j++)scanf("%d",&A[i][j]);
    max = 0;
    ui = 0;
    int profit = func(0,0);
    printf("profit: %d\n",profit);
    return 0;
}
