
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int Time;
int costs[100];
int profit[100];
int d[100];
int indxes[100];

int N;
int dp[31][1001];
int dir[31][1001];

void init_dp()
{
	for (int i = 0; i < 31; i++)
	{

		for (int j = 0; j < 1001; j++)
		{
			dp[i][j] = -1;
			dir[i][j] = -1;
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

	if (profit1 > profit2)
	{
		dir[i][cost] = 1;
		return dp[i][cost] = profit1;
	}
	else
	{
		dir[i][cost] = 2;
		return dp[i][cost] = profit2;
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);
	bool blank = false;
	/*

	int w;
	bool blank = false;
	while (scanf("%d %d", &Time, &w) == 2)
	{
		init_dp();
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d", &costs[i], &profit[i]);
			costs[i] *= 3 * w;
		}
		if (blank) puts("");
		blank = true;
		printf("%d\n", max_profit(0, 0));
		int ii = 0;
		int ww = 0;
		int k = 0;

		while (dir[ii][ww] != -1)
		{
			if (dir[ii][ww] == 1)
			{
				//cout << d[i] << " " << profit[i] << endl;
				indxes[k] = ii; k++;
				ww += costs[ii];
				ii++;


			}
			else if (dir[ii][ww] == 2)
			{
				ii++;
			}
		}


		printf("%d\n", k);
		for (int j = 0; j < k; j++)
		{
			printf("%d %d\n", costs[indxes[j]] / (3 * w), profit[indxes[j]]);
		}

	}


	//puts("");


	*/


	
	//char c;
	int w;
	while (scanf("%d %d", &Time, &w) == 2){
	//cin >> Time;
	
	//cin >> w;
	cin >> N;
	init_dp();/*
	for (int i = 0; i < 31; i++)
	{

	for (int j = 0; j < 1001; j++)
	{
	dp[i][j] = -1;
	dir[i][j] = -1;
	}
	}*/
	for (int i = 0; i < N; i++)
	{
	cin >> costs[i];
	d[i] = costs[i];
	costs[i] *= w * 3;
	cin >> profit[i];
	}
	int max_profitq = max_profit(0, 0);
	if (blank) puts("");
	blank = true;
	cout << max_profitq << '\n';
	int i = 0;
	int ww = 0;
	int k = 0;

	while (dir[i][ww] != -1)
	{
	if (dir[i][ww] == 1)
	{
	//cout << d[i] << " " << profit[i] << endl;
	indxes[k] = i; k++;
	ww += costs[i];
	i++;


	}
	else if (dir[i][ww] == 2)
	{
	i++;
	}
	}

	cout << k << '\n';
	for (int j = 0; j < k; j++)
	{
	cout << d[indxes[j]] << " " << profit[indxes[j]] << '\n';
	}
	//cout << '\n';
	} //while (!cin.eof());
	return 0;
}