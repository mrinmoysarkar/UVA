#include<cstdio>
#include<iostream>
#include<string>
#include <ctype.h>
using namespace std;
string topic[100];
int to, p, s;
string constrain[100];
int grid[100][100];
string output[100];
int out[6];
int out_fs[5000][6];
int current_int;
int done = 0;
int used[100];
int fs;
void print_0(int n)
{
	cout << topic[current_int] << " ";
	for (int i = 0; i < n; i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}
void print()
{
	for (int j = 0; j < to; j++)
	{
		cout << topic[j] << endl;;
	}
	cout << endl;
}
void p_grid()
{
	for (int i = 0; i < to; i++)
	{
		for (int j = 0; j < to; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
void sort_s()
{
	for (int i = 0; i < to; i++)
	{
		for (int j = 0; j < (to-1-i); j++)
		{
			if (topic[j + 1].length() > topic[j].length())
			{
				string tem = topic[j + 1];
				topic[j + 1] = topic[j];
				topic[j] = tem;
			}
			else if (topic[j + 1] < topic[j] && topic[j + 1].length() == topic[j].length())
			{
				string tem = topic[j + 1];
				topic[j + 1] = topic[j];
				topic[j] = tem;
			}
		}
		//print();
	}
}
void init()
{
	for (int i = 0; i < to; i++)
	{
		used[i] = 0;
	}
}
void build_grid()
{
	for (int i = 0; i < to; i++)
	{
		for (int j = 0; j < to; j++)
		{
			if (i != j)
			{
				grid[i][j] = 1;
			}
			else
			{
				grid[i][j] = 0;
			}
		}
	}
}
int find_s()
{
	for (int i = 0; i < fs; i++)
	{
		int sum = 0;
		for (int j = 0; j < s; j++)
		{
			for (int k = 0; k < s; k++)
			{
				if (out_fs[i][k] == out[j])
				{
					sum++;
					break;
				}
			}
		}
		if (sum == s)return 0;
	}
	for (int k = 0; k < s; k++)
	{
		out_fs[fs][k] = out[k];
	}
	return 1;
}

void place_node()
{
	int pp = p;
	for (int i = 0; i < pp; i = i + 2)
	{
		int x = -1, y = -1;
		for (int j = 0; j < to; j++)
		{
			if (constrain[i] == topic[j])
			{
				x = j;
			}
			if (constrain[i + 1] == topic[j])
			{
				y = j;
			}
			if (x != -1 && y != -1)
			{
				grid[x][y] = 0;
				grid[y][x] = 0;
				break;
			}
		}
	}
}

int is_in(int ii,int indx)
{
	for (int i = 0; i < indx; i++)
	{
		if (used[i])
		{
			if (!grid[i][ii])return 0;
		}
	}
	return 1;
}
void dfs(int indx,int no,int oi)
{
	if (done)return;
	if (s == no)
	{
		///*
		//out[0] = current_int;
		
		//if (find_s())
		{
			//fs++;
			cout << topic[current_int];
			if (s != 1)
			{
				cout << " ";
				for (int i = 0; i < (s-1); i++)
				{
					cout << output[i];
					if (i != (s - 2)){ cout << " "; }
				}
			}
			cout << endl;
		}
		//*/
		//done = 1;
		return;
	}
	for (int i = indx+1; i < to; i++)
	{
		if (grid[indx][i] && !used[i] && is_in(i,to))
		{
			output[oi] = topic[i];
			//out[oi+1] = i;
			used[i] = 1;
			//print_0(oi+1);
			dfs(i,no+1,oi+1);
			used[i] = 0;
		}
	}
}



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> to >> p >> s;
		for (int j = 0; j < to; j++)
		{
			cin >> topic[j];
			int l = topic[j].length();
			for (int k = 0; k < l; k++)
			{
				topic[j][k] = toupper(topic[j][k]);
			}
		}
		sort_s();
		p = 2 * p;
		for (int j = 0; j < p; j++)
		{
			cin >> constrain[j];
			int l = constrain[j].length();
			for (int k = 0; k < l; k++)
			{
				constrain[j][k] = toupper(constrain[j][k]);
			}
		}
		build_grid();
		place_node();
		cout << "Set " << i << ":" << endl;
	//	fs = 0;
		for (int j = 0; j < to; j++)
		{
			init();
			used[j] = 1;
			current_int = j;
			dfs(j, 1,0);
		}
		//if (i != t)
			cout << endl;
	}
	return 0;
}