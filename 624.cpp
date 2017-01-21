#include<cstdio>
#include<iostream>
using namespace std;
#define MAX 100
int data[MAX];
int out[MAX];
int fout[MAX];
int target, N;
int gmin = 0;
int in = 0;
int pin = 0;
int sum;
int flag = 0;
void copy(int j)
{
	for (int i = 0; i < j; i++)
	{
		fout[i] = out[i];
	}
}
int solve(int indx, int sum1)
{
	if (flag)return 0;
	if (indx == N)
	{
		//cout << sum1 << endl;
		int d = target - sum1;
		if (d >= 0)
		{
			if (gmin >= d)
			{
				if (d == 0 && gmin == 0 && pin < in)
				{
					copy(in);
					pin = in;
				}
				else
				{
					//if (d == 0)flag = 1;
					gmin = d;
					sum = sum1;
					copy(in);
					pin = in;
				}
			}
		}
		return 0;
	}
	solve(indx + 1, sum1);
	out[in] = data[indx];
	in++;
	solve(indx + 1, sum1 + data[indx]);
	in--;
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d %d", &target, &N) == 2)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> data[i];
		}
		gmin = 1<<8;
		pin = -1;
		in = 0;
		flag = 0;
		solve(0, 0);
		for (int i = 0; i < pin; i++)
		{
			cout << fout[i] << " ";
		}
		//cout << pin << endl;
		cout << "sum:" << sum << endl;
	}
	return 0;
}
