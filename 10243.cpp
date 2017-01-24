#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<vector>


using namespace std;

#define MAXN 100002
int dp[MAXN][5];
int par[MAXN];
vector<int> edges[MAXN];

int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a < b ? b : a;
}

int f(int u, int isGuard)
{
	if (edges[u].size() == 0)
		return 0;
	if (dp[u][isGuard] != -1)
		return dp[u][isGuard];
	int sum = 0;
	for (int i = 0; i < (int)edges[u].size(); i++) {
		int v = edges[u][i];
		if (v != par[u]) {
			par[v] = u;
			if (isGuard == 0)
				sum += f(v, 1);
			else
				sum += min(f(v, 1), f(v, 0));
		}
	}
	return dp[u][isGuard] = sum + isGuard;
}


void init_dp()
{
	for (int i = 0; i < MAXN; i++)
	{
		dp[i][0] = -1;
		dp[i][1] = -1;
		dp[i][2] = -1;
		dp[i][3] = -1;
		dp[i][4] = -1;
	}
}

int set(int N, int pos){ return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~(1 << pos); }
bool check(int N, int pos){ return (bool)(N & (1 << pos)); }





int main()
{
	freopen("Text.txt", "r", stdin);
	int t;
	while (scanf("%d", &t) == 1)
	{
		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			for (int j = 0; j < x; j++)
			{
				int d;
				cin >> d;
				edges[i].push_back(d);
			}
		}
		int ans = 0;
		ans = min(f(1, 1), f(1, 0));
		printf("%d\n",ans);
	}
	
	return 0;
}