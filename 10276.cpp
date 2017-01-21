///*
#include<cstdio>
#include<iostream>
using namespace std;
int tower[100];

int sqr(int n)
{
	int j = n / 2;
	for (int k = j; k > 0;k--)
	{
		if (n == k*k)return 1;
	}
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> N;
		for (int k = 0; k < N; k++)
		{
			tower[k] = 0;
		}
		int i = 1;
		while (true)
		{
			int j;
			for (j = 0; j < N; j++)
			{
				if (tower[j] == 0 || sqr(tower[j]+i))
				{
					tower[j] = i;
					break;
				}
			}
			if (j == N)
			{
				break;
			}
			i++;
		}
		cout << (i-1) << endl;
	}
	return 0;
}
//*/
/*
#include<cstdio>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int a, b, ts;

	while (scanf("%d", &ts) == 1)
	{
		for (b = 0; b<ts; b++)
		{
			scanf("%d", &a);
			printf("%d\n", ((a*++a) >> 1) - 1);
		}
	}
}
*/