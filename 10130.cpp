#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int Time;
int costs[1001];
int profit[1001];
int N;
int dp[1001][101];


void init_dp()
{
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			dp[i][j] = -1;
		}
	}
}


int max_profit(int i, int cost)
{
	if (i == N)
	{
		return 0;
	}
	if (dp[i][cost] != -1)return dp[i][cost];
	int profit1 = 0, profit2 = 0;
	if ((cost + costs[i]) <= Time)
	{
		profit1 = profit[i] + max_profit(i + 1, (cost + costs[i]));
	}
	else
	{
		profit1 = 0;
	}
	profit2 = max_profit(i + 1, cost);
	int m = profit1 > profit2 ? profit1 : profit2;
	dp[i][cost] = m;
	return dp[i][cost];
}



int main()
{
	freopen("Text.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--){
		
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> profit[i];
			cin >> costs[i];
		}
		int fm;
		cin >> fm;
		int mx_p = 0;
		for (int i = 0; i < fm; i++)
		{
			init_dp();
			cin >> Time;
			mx_p += max_profit(0, 0);
		}
		cout << mx_p << endl;
	}
	return 0;
}