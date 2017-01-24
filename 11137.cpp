#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

#define II 22
#define JJ 10001
#define i64 unsigned long long

int Target;
int A[21];// = { 50, 25, 10, 5, 1 };
int N = 21;
i64 dp[II][JJ];

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

i64 max_profit(int i, int cost)
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
	i64 profit1 = 0, profit2 = 0;
	if ((cost - A[i]) >= 0)
	{
		profit1 = max_profit(i, (cost - A[i]));
	}
	else
	{
		profit1 = 0;
	}
	profit2 = max_profit(i + 1, cost);
	i64 m = profit1 + profit2;
	dp[i][cost] = m;
	return dp[i][cost];
}

int main()
{
	freopen("Text.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init_dp();
	for (int i = 0; i < 21; i++)
	{
		A[i] = (i + 1)*(i + 1)*(i + 1);
		//cout << A[i] << " ";
	}
	while (cin >> Target)
	{

		cout << max_profit(0, Target) << endl;
	}
	return 0;
}