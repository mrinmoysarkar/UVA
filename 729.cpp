#include<stdio.h>
#include<iostream>

using namespace std;
int N, H;
int out[100];
void solve(int indx)
{
	if (indx == N)
	{
		int x = 0;
		for (int i = 0; i < N; i++)
		{
			x += out[i] == 1 ? 1 : 0;
		}
		if (x == H)
		{
			for (int i = 0; i < N; i++)
			{
				cout << out[i];
			}
			cout << endl;
		}
		return;
	}
	out[indx] = 0;
	solve(indx + 1);
	out[indx] = 1;
	solve(indx + 1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> N >> H;
		solve(0);
		if (tt != (t - 1))cout << endl;
	}
	return 0;
}