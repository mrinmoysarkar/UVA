#include<cstdio>
#include<iostream>
using namespace std;
int target;
int N;
int data[15];
int flah;
int out[15];
int pre[10000][15];
int gt = 0;
int check(int k)
{
	for (int i = 0; i < gt; i++)
	{
		int j = 0;
		for (; j < k; j++)
		{
			if (out[j] != pre[i][j])break;
		}
		if (k == j) return 0;
	}
	return 1;
}
void solve(int indx, int sum,int i)
{
	if (sum > target) return;
	if (indx == N )
	{
		if (sum == target && check(i))
		{
			//cout << "got" << endl;
			for (int j = 0; j < i; j++)
			{
				cout << out[j];
				pre[gt][j] = out[j];
				if (j != (i - 1)) cout << "+";
			}
			gt++;
			cout << endl;
			flah = 0;
		}
		return;
	}
	out[i] = data[indx];
	solve(indx + 1, sum + data[indx],i+1);
	solve(indx + 1, sum,i);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (true)
	{
		cin >> target >> N;
		if (target == 0 && N == 0)break;
		for (int i = 0; i < N; i++)cin >> data[i];
		cout << "Sums of " << target <<":"<< endl;
		flah = 1;
		gt = 0;
		solve(0, 0,0);
		if (flah)cout << "NONE" << endl;
	}
	return 0;
}