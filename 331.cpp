#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//int grid[100][100];
int N;
int gdata[10];
int totalswap;
/*
void dfs(int indx)
{
if(indx == N)
{
return;
}

for(int i=0;i<N;i++)
{
if(grid[indx][i])
{
dfs(i);
}
}
}
*/
void solve(int *dt)
{
	int i;
	for (i = 0; i<(N - 1); i++)
	{
		if (dt[i] > dt[i + 1])break;
	}
	if (i == (N - 1))
	{
		totalswap++;
		return;
	}
	int data[10];
	for (i = 0; i<N; i++)
	{
		data[i] = dt[i];
	}
	for (i = 0; i<(N - 1); i++)
	{
		if (data[i] > data[i + 1])
		{
			int tem = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tem;
			solve(data);
			tem = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tem;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cout<<"This is the main cpp code"<<endl;
	int t = 1;
	while (1)
	{
		cin >> N;
		if (N == 0)break;
		for (int i = 0; i<N; i++)
		{
			cin >> gdata[i];
		}
		//        cout <<"N: "<< N << endl;
		totalswap = 0;
		int i;
		for (i = 0; i<(N - 1); i++)
		{
			if (gdata[i] > gdata[i + 1])break;
		}
		if (i == (N - 1))
		{
			cout << "There are " << totalswap << " swap maps for input data set " << t << "." << endl;
		}
		else
		{
			solve(gdata);
			cout << "There are " << totalswap << " swap maps for input data set " << t << "." << endl;
		}
		t++;
	}
	return 0;
}