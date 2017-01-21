#include<cstdio>
#include<iostream>
using namespace std;

int grid[1000][1000];
int used[1000];
int N;
int out[1000];
int done = 0;
void init()
{
	for (int i = 0; i <= N; i++)
	{
		used[i] = 0;
		for (int j = 0; j <= N; j++)grid[i][j] = 0;
	}
}
void p()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)cout << grid[i][j] <<" ";
		cout << endl;
	}
}
void solve(int indx,int ad)
{
	if (done)return;
	if (ad == N)
	{
		if (grid[out[ad - 1]][1])
		{
			for (int i = 0; i < ad; i++)
			{
				cout << out[i] << " ";
			}
			cout << 1 << endl;
			done = 1;
		}
		return;
	}
	for(int i = 1; i <= N; i++)
	{
		if (!used[i] && grid[indx][i])
		{
			used[indx] = 1;
			out[ad] = i;
			solve(i,ad+1);
			used[indx] = 0;
		}
	}

}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d", &N) == 1)
	{
		init();
		getchar();
		char str[10];
		while (gets(str) && str[0] != '%')
		{
			int a, b;
			sscanf(str, "%d%d", &a, &b);
			//cout << a << b;
			grid[a][b] = grid[b][a] = 1;
		}
		//p();
		done = 0;
		out[0] = 1;
		solve(1, 1);
		if (!done)cout << "N" << endl;
	}
	return 0;
}