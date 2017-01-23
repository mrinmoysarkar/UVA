#include<iostream>
#include<cstdio>
using namespace std;

int board[8][8];
int output[8][8];
int cont = 0;
int row, col;
void init_board()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
			output[i][j] = 0;
		}
}

void update_board(int i, int j, int val,int choice)
{
	//if (board[i][j] != 0) return;
	if (i == 8 || j == 8 || i == -1 || j == -1) return;
	
	board[i][j] += val;
	switch (choice)
	{
	case 0:	
		update_board(i + 1, j + 1,val, choice);
		break;
	case 1:
		update_board(i + 1, j,val, choice);
		break;
	case 2:
		update_board(i, j + 1, val, choice);
		break;
	case 3:
		update_board(i - 1, j - 1, val, choice);
		break;
	case 4:
		update_board(i - 1, j, val, choice);
		break;
	case 5:
		update_board(i, j - 1, val, choice);
		break;
	case 6:
		update_board(i - 1, j + 1, val, choice);
		break;
	case 7:
		update_board(i + 1, j - 1, val, choice);
		break;
	}
}
void update(int i, int j, int val)
{
	for (int c = 0; c < 8; c++)
	{
		update_board(i, j, val, c);
	}
}
void print_board()
{
	//cout << " " << cont << "      ";
	printf("%2d     ", cont);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//cout << board[i][j] << " ";
			//printf("%3d  ", board[i][j]);
			//printf("%d  ", output[i][j]);
			if (output[j][i])
			{
				printf("%2d", (j + 1));
			}
		}
	}
	cout << endl;
}
void solve(int indx)
{
	//if (indx == row) return;
	if (indx == 8)
	{
		if (output[row][col])
		{
			cont++;
			print_board();
		}
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		//if (i != col && indx != row)
		{
			if (!board[i][indx])
			{
				output[i][indx] = 1;
				update(i, indx, i + 1);
				solve(indx + 1);
				update(i, indx, -(i + 1));
				output[i][indx] = 0;
			}
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl;
		cout << endl;
		init_board();
		//row = 0;
		//col = 1;
		cin >> row >> col;
		row--;
		col--;
		//update(row, col, col+1);
		//output[row][col] = 1;
		//print_board();
		//update(2, 3, -2);
		//print_board();
		cont = 0;
		solve(0);
		//cout << cont << endl;
		if (i != (T - 1))cout << endl;
	}
	return 0;
}