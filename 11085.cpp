#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int board[8][8];
int out[8][8];
int var = 0;
int ref_b[8][8];
int m;
void init()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++){
			board[i][j] = 0; out[i][j] = 0; ref_b[i][j] = 0;
		}
}
void update_board(int i,int j,int val,int option)
{
	switch (option)
	{
	case 0:
		if ((i + 1) < 8 && (j + 1) < 8)
		{
			board[i + 1][j + 1] += val;
			update_board(i + 1, j + 1, val, option);
		}
		break;
	case 1:
		if ((i - 1) >= 0 && (j - 1) >= 0)
		{
			board[i - 1][j - 1] += val;
			update_board(i - 1, j - 1, val, option);
		}
		break;
	case 2:
		if ((i - 1) >= 0 && (j + 1) < 8)
		{
			board[i - 1][j + 1] += val;
			update_board(i - 1, j + 1, val, option);
		}
		break;
	case 3:
		if ((i + 1) < 8 && (j - 1) >= 0)
		{
			board[i + 1][j - 1] += val;
			update_board(i + 1, j - 1, val, option);
		}
		break;
	case 4:
		if ((i + 1) < 8 )
		{
			board[i + 1][j] += val;
			update_board(i + 1, j, val, option);
		}
		break;
	case 5:
		if ((i - 1) >= 0)
		{
			board[i - 1][j] += val;
			update_board(i - 1, j, val, option);
		}
		break;
	case 6:
		if ((j + 1) < 8)
		{
			board[i][j + 1] += val;
			update_board(i, j + 1, val, option);
		}
		break;
	case 7:
		if ((j - 1) >= 0)
		{
			board[i][j - 1] += val;
			update_board(i, j - 1, val, option);
		}
		break;
	}
}

void update(int i, int j, int val)
{
	board[i][j] += val;
	for (int o = 0; o < 8; o++)
	{
		update_board(i, j, val, o);
	}
}
void print(int op)
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			switch (op)
			{
			case 0:
				cout << out[i][j] << " ";
				break;
			case 1:
				cout << ref_b[i][j] << " ";
				break;
			}
		}
		cout << endl;
	}
}
int calc_m()
{
	int rf, dm;
	int sm = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (ref_b[j][i])
			{
				rf = j;
			}
			if (out[j][i])
			{
				dm = j;
			}
		}
		sm += rf == dm?0:1;
	}
	return sm;
}
void solve(int col)
{
	if (col == 8)
	{
		int mm = calc_m();
		if (mm < m)m = mm;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (!board[i][col])
		{
			update(i, col, 1);
			out[i][col] = 1;
			solve(col + 1);
			out[i][col] = 0;
			update(i, col, -1);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cas = 1;
	while (1)
	{
		var = 0;
		init();
		for (int i = 0; i < 8; i++)
		{
			int r;
			if (scanf("%d", &r) == 1)
			{
				ref_b[r-1][i] = 1;
			}
			else{
				var = 1;
				break;
			}
		}
		if (!var)
		{
			//print(1);
			//cout << endl;
			m = 1 << 8;
			solve(0);
			cout <<"Case "<<cas<<": " <<m << endl;
			cas++;
		}
		else{
			break;
		}
	}
	return 0;
}