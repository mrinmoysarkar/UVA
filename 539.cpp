#include<stdio.h>
#include<iostream>

using namespace std;
#define MAX 100
int n, e;
int out[100];
int fout[100];
int grid[MAX][MAX];
int edge[MAX][MAX];
int check(int nn, int val);
int M = 0;
void copy(int nn)
{
	for (int i = 0; i < nn; i++)
	{
		fout[i] = out[i];
	}
}
void print(int nn)
{
	for (int i = 0; i <= nn; i++)
	{
		cout << out[i] <<" ";
	}
	cout << endl;
}
void solve(int indx,int ad)
{
	if (indx == n)
	{
		if (ad > M)
		{
			M = ad;
			//copy(M);
			//print(M);
		}
		//print(ad-1);
		return;
	}
	int fg = 1;
	for (int i = 0; i < n; i++)
	{
		if (grid[indx][i] && !edge[indx][i])//check(ad+1, i))
		{
			//out[ad+1] = i;
			fg = 0;
			edge[indx][i] = 1;
			edge[i][indx] = 1;
			solve(i, ad + 1);
			edge[indx][i] = 0;
			edge[i][indx] = 0;
		}
	}
	if (ad > M)
	{
		M = ad;
		copy(M);
		//print(M);
	}
	//if(fg)print(ad);
	return;
}
void init_var(){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++){
			grid[i][j] = 0;
			edge[i][j] = 0;
		}
	}
}
void print_grid(){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++){
			cout << grid[i][j] <<" ";
		}
		cout << endl;
	}
}
void init_edge()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++){
			edge[i][j] = 0;
		}
	}
}
int check(int nn, int val)
{
	for (int i = 0; i < nn; i++)
	{
		if (out[i] == val)return 0;
	}
	return 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	while (scanf("%d %d",&n,&e) == 2)
	{
		if (n == 0 && e == 0)break;
		init_var();
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			grid[x][y] = 1;
			grid[y][x] = 1;
		}
		//print_grid();
		//cout << endl;
		M = -1;
		for (int i = 0; i < n;i++)
		{
			out[0] = i;
			init_edge();
			solve(i, 0);
			
			//print(M);
		}
		cout << M << endl;
	}
	return 0;
}