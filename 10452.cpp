#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string data[100];
int out[100];
string target = "AVOHEI";
int m, n;
int done = 0;
void solve(int indx, int k, int w)
{
	if (done)return;
	if (data[w][indx] == '@')
	{
		done = 1;
		for (int i = 6; i >= 0; i--)
		{
			switch (out[i])
			{
			case 1:
				cout << "right";
				break;
			case -1:
				cout << "left";
				break;
			case 0:
				cout << "forth";
				break;
			}
			if (i != 0)cout << " ";
		}
		cout << endl;
		return;
	}
	if ((indx - 1) >= 0 && (data[w][indx - 1] == target[k] || data[w][indx - 1] == '@'))
	{
		out[k] = 1;
		solve((indx - 1), (k + 1), w);
	}
	if ((indx + 1) < m && (data[w][indx + 1] == target[k] || data[w][indx + 1] == '@'))
	{
		out[k] = -1;
		solve((indx + 1), (k + 1), w);
	}
	if (data[w + 1][indx] == target[k] || data[w+1][indx] == '@')
	{
		out[k] = 0;
		solve(indx, (k+1), w + 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		int ind;
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
			if (i == 0)for (int j = 0; j < m; j++)if (data[i][j] == '#'){ ind = j; break; }
		}
		done = 0;
		solve(ind, 0, 0);
	}
	return 0;
}