#include<cstdio>
#include<iostream>
using namespace std;
int row[10001];
int col[10001];
int target;
int p, q;
int source[10001];
int operation[10001];
int check(int N,int x,int y)
{
	for (int i = 0; i < N; i++)
	{
		if (row[i] == x && col[i] == y)return 0;
	}
	return 1;
}
void solve(int r, int c,int indx)
{
	row[0] = r;
	col[0] = c;
	int n = 1;
	while (1)
	{
		indx++;
		if (c == target)
		{ /*
			cout << "done" << endl; 
			for (int i = 0; i < indx; i++)
			{
				cout << operation[i] << " ";
			}
			cout << endl;
			for (int i = 0; i < indx; i++)
			{
				cout << source[i] << " ";
			}
			cout << endl;*/
			int in = indx-1;
			int ii = 0;

			while (in)
			{
				row[ii] = operation[in];
				ii++;
				in = source[in]-1;
			}
			for (int i = ii - 1; i >= 0; i--)
			{
				//cout << row[i] << " ";
				if (row[i] == 0){ cout << "fill A"<< endl;}
				else if (row[i] == 1){ cout << "empty A" << endl;}
				else if (row[i] == 2){ cout << "fill B" << endl; }
				else if (row[i] == 3){ cout << "empty B" << endl; }
				else if (row[i] == 4){ cout << "pour B A" << endl; }
				else if (row[i] == 5){ cout << "pour A B" << endl; }
			}
			cout << "success" << endl;
			break;
		}
		if (r < p)
		{
			if (check(n,p,c))
			{
				row[n] = p;
				col[n] = c;
				source[n] = indx;
				operation[n] = 0;
				n++;
			}
		}
		if (r > 0)
		{
			if (check(n,0,c))
			{
				row[n] = 0;
				col[n] = c;
				source[n] = indx;
				operation[n] = 1;
				n++;
			}
		}
		if (c < q)
		{
			if (check(n, r, q))
			{
				row[n] = r;
				col[n] = q;
				source[n] = indx;
				operation[n] = 2;
				n++;
			}

		}
		if (c > 0)
		{
			if (check(n, r, 0))
			{
				row[n] = r;
				col[n] = 0;
				source[n] = indx;
				operation[n] = 3;
				n++;
			}
		}
		if (r < p)
		{
			int x, y;
			if ((r + c)>p){ x = p; y = r + c - p; }
			else{
				x = r + c; y = 0;
			}
			if (check(n, x, y))
			{
				row[n] = x;
				col[n] = y;
				source[n] = indx;
				operation[n] = 4;
				n++;
			}

		}
		if (c < q)
		{
			int x, y;
			if ((r + c)>q){ y = q; x = r + c - q; }
			else{
				y = r + c; x = 0;
			}
			if (check(n, x, y))
			{
				row[n] = x;
				col[n] = y;
				source[n] = indx;
				operation[n] = 5;
				n++;
			}
		}
		r = row[indx]; c = col[indx];
		//cout << "R: " << r << " C: " << c << endl;
	}
}



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d %d %d", &p, &q, &target) == 3)
	{
		//cout << target << endl;
		solve(0, 0, 0);
	}
	return 0;
}