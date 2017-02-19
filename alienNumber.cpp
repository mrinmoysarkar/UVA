#include<stdio.h>

#define MAX_IND 100000

int str_len(char *s)
{
    int i=0;
    while(s[i])
    {
        i++;
    }
    return i;
}

int get_index(char c, char *s)
{
    int i=0;
    while(s[i] != c)
    {
        i++;
    }
    return i;
}

int power(int x, int n)
{
    int val = 1;
    while(n--)
    {
        val *= x;
    }
    return val;
}

int main()
{
    freopen("input.txt","r",stdin);
    int testCase;
    scanf("%d",&testCase);
    
    for(int t = 1;t<=testCase;t++)
    {
        char number[MAX_IND],numbersystem1[MAX_IND],numbersystem2[MAX_IND],output[MAX_IND];
        scanf("%s %s %s", number, numbersystem1, numbersystem2);
        
        int L1 = str_len(number);
        int L2 = str_len(numbersystem1);
        int L3 = str_len(numbersystem2);
        //printf("%d %d %d\n",L1,L2,L3);
        int num = 0;
        for(int i=0;i<L1;i++)
        {
            int indx = get_index(number[i],numbersystem1);
            num += indx * power(L2, L1-i-1);
        }
        //printf("%d\n", num); 
        int i = 0;
        while(num)
        {
            output[i++] = numbersystem2[num%L3];
            num /= L3;
        }      
        printf("Case%d: ",t);
        for(int j=i-1;j>=0;j--)printf("%c",output[j]);
        printf("\n");
    }
    return 0;
}
