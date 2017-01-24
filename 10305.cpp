#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

int variable[101];
int used[101];
int result[101];
int constrain[101][101];
int N;
int done = 0;
int n, m;
void init()
{
	for (int i = 1; i < 101; i++) 
	{
		variable[i] = 0; used[i] = 0; result[i] = 0;
		for (int j = 1; j < 101; j++)
		{
			constrain[i][j] = 0;
		}
	}
}

void readVariable()
{
	
	//cin >> n >> m;
	N = n;
	for (int i = 1; i <= n; i++)
	{
		variable[i] = 1;
	}
	int i, j;
	for (int k = 1; k <= m; k++)
	{
		cin >> i >> j;
		constrain[i][j] = 1;
	}
	//cin >> i >> j;
}
void solve(int indx)
{
	if (done)return;
	if (indx == (N+1))
	{
		for (int i = 1; i < indx; i++)
		{
			cout << result[i];
			if (i != indx - 1) cout << " ";
		}
		cout << endl;
		done = 1;
		return;
	}
	for (int i = 1; i < 101; i++)
	{
		if (variable[i] && used[i] == 0)
		{
			for (int j = 1; j < 101; j++)
			{
				if (constrain[i][j] && used[j]) return;
			}
			used[i] = 1;
			result[indx] = i;
			solve(indx+1);
			used[i] = 0;
		}
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)break;
		done = 0;
		init();
		readVariable();
		solve(1);
	}
	return 0;
}