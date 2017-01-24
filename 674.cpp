#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

#define II 5
#define JJ 7490

int Target;
int A[] = {50,25,10,5,1};
int N = 5;
int dp[II][JJ];

void init_dp()
{
	for (int i = 0; i < II; i++)
	{
		for (int j = 0; j < JJ; j++)
		{
			dp[i][j] = -1;
		}
	}
}

int max_profit(int i, int cost)
{
	if (i == N)
	{
		if (cost == 0)
		{
			return 1;
		}
		return 0;
	}
	if (dp[i][cost] != -1)return dp[i][cost];
	int profit1 = 0, profit2 = 0;
	if ((cost - A[i]) >= 0)
	{
		profit1 = max_profit(i , (cost - A[i]));
	}
	else
	{
		profit1 = 0;
	}
	profit2 = max_profit(i + 1, cost);
	int m = profit1 + profit2;
	dp[i][cost] = m;
	return dp[i][cost];
}

int main()
{
	freopen("Text.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init_dp();

	while (cin >> Target)
	{
		
		cout << max_profit(0, Target) << endl;
	}
	return 0;
}