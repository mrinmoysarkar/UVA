#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
char grid[26][26];
int table[26][26];
int output[100];
int oi = 0;
int N;
string all_out[10000];
int gt=0;
char out[100];
int NN;
void init_t()
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			table[i][j] = 0;
		}
	}
}
void print_t()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout <<grid[i][j]<<" ";
		}
		cout << endl;
	}
}
int check(string v)
{
	for (int i = 0; i < gt; i++)
	{
		if (all_out[i] == v)return 0;
	}
	return 1;
}
void solve(int r, int c,int indx)
{
	if (r < 0 || c < 0 || r == N || c==N)
	{
		//cout << "got: "<<r<<"  "<<c << endl;
		if (indx > 2 && indx < NN)
		{
			out[indx] = '\0';
			string s(out);
			if (check(s))
			{
				//cout << s << endl;
				all_out[gt] = s;
				gt++;
			}
		}
		return;
	}
	int called = 1; 
	//row col
	if ((c - 1) >= 0 && grid[r][c] < grid[r][c - 1])
	{
		out[indx] = grid[r][c - 1];
		solve(r, c - 1,indx+1);
		called = 0;
	}
	else if ((c-1)==-1)
	{
		solve(r, c - 1,indx);
		called = 0;
	}

	if ((c + 1) < N && grid[r][c] < grid[r][c + 1])
	{
		out[indx] = grid[r][c + 1];
		solve(r, c + 1,indx+1);
		called = 0;
	}
	else if ((c + 1) == N)
	{
		solve(r, c + 1,indx);
		called = 0;
	}

	if ((r - 1) >= 0 && grid[r][c] < grid[r-1][c])
	{
		out[indx] = grid[r-1][c];
		solve(r-1, c,indx+1);
		called = 0;
	}
	else if ((r - 1) == -1)
	{
		solve(r-1, c,indx);
		called = 0;
	}

	if ((r + 1) < N && grid[r][c] < grid[r+1][c])
	{
		out[indx] = grid[r+1][c];
		solve(r+1, c,indx+1);
		called = 0;
	}
	else if ((r + 1) == N)
	{
		solve(r+1, c,indx);
		called = 0;
	}
	//corner
	if ((c - 1) >= 0 && (r-1) >= 0 && grid[r][c] < grid[r-1][c - 1])
	{
		out[indx] = grid[r-1][c - 1];
		solve(r-1, c - 1,indx+1);
		called = 0;
	}
	else if ((c - 1) == -1 && (r-1) == -1)
	{
		solve(r-1, c - 1,indx);
		called = 0;
	}

	if ((c + 1) < N && (r + 1) < N && grid[r][c] < grid[r + 1][c + 1])
	{
		out[indx] = grid[r + 1][c + 1];
		solve(r + 1, c + 1,indx+1);
		called = 0;
	}
	else if ((c + 1) == N && (r + 1) == N)
	{
		solve(r + 1, c + 1,indx);
		called = 0;
	}

	if ((c - 1) >= 0 && (r + 1) < N && grid[r][c] < grid[r + 1][c - 1])
	{
		out[indx] = grid[r+1][c - 1];
		solve(r + 1, c - 1,indx+1);
		called = 0;
	}
	else if ((c - 1) == -1 && (r + 1) == N)
	{
		solve(r + 1, c - 1,indx);
		called = 0;
	}

	if ((c + 1) < N && (r - 1) >= 0 && grid[r][c] < grid[r - 1][c + 1])
	{
		out[indx] = grid[r - 1][c + 1];
		solve(r - 1, c + 1,indx+1);
		called = 0;
	}
	else if ((c + 1) == N && (r - 1) == -1)
	{
		solve(r - 1, c + 1,indx);
		called = 0;
	}
	if (called)
	{
		if (indx > 2 && indx < NN)
		{
			out[indx] = '\0';
			string s(out);
			if (check(s))
			{
				//cout << s << endl;
				all_out[gt] = s;
				gt++;
			}
		}
	}
}
void ssort()
{
	for (int i = 0; i < gt; i++)
	{/*
		for (int ii = 0; ii < gt; ii++)
		{
			cout << all_out[ii] << "  ";
		}
		cout << endl;*/
		for (int j = 0; j < (gt-1); j++)
		{
			if ((all_out[j].length() > all_out[j + 1].length()))
			{
				string tm = all_out[j];
				all_out[j] = all_out[j + 1];
				all_out[j + 1] = tm;
			}
			if ((all_out[j].length() == all_out[j + 1].length()))
			{
				if ((all_out[j] > all_out[j + 1]))
				{
					string tm = all_out[j];
					all_out[j] = all_out[j + 1];
					all_out[j + 1] = tm;
				}
			}
		}
	}
	for (int i = 0; i < gt; i++)
	{
		cout << all_out[i] << endl;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int y = 0;
	while (T--)
	{
		if (y)
			cout << endl;
		y = 1;
		cin >> N;
		NN = N*N + 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> grid[i][j];
			}
		}
		//print_t();
		//cout << "##############" << endl;
		gt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out[0] = grid[i][j];
				solve(i, j, 1);
			}
		}
		//cout << "************" << endl;
		ssort();
		//cout << endl;
	}
	return 0;
}