#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 27
int data[27];
double value[27];
int grid[MAX][MAX];

void init_variable()
{
	for (int i = 0; i < MAX; i++)
	{
		data[i] = 0;
		value[i] = 0;
		for (int j = 0; j < MAX; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void print()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	freopen("i.txt", "r", stdin);
	int N;
	while (scanf("%d", &N) == 1)
	{
		init_variable();
		for (int i = 0; i < N; i++)
		{
			char c;
			cin >> c;
			int x = c - 'A';
			data[x] = 1;
			double v;
			cin >> v;
			value[x] = v;
			char ch[30];
			cin >> ch;
			int j = 0;
			while (ch[j])
			{
				c = ch[j];
				int y;
				if (c == '*') y = 26;
				else y = c - 'A';
				grid[x][y] = 1;
				grid[y][x] = 1;
				j++;
			}//*/
		}
		//print();
		cout << endl << endl;
	}
}
