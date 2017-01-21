#include<cstdio>
#include<iostream>
using namespace std;
int s, d;
int m;
int cal;
int out[12];
void solve(int indx,int sum1)
{
	if (indx == 12)
	{
		int def = 0;
		int sm = 0;
		for (int i = 0; i < 8; i++)
		{
			sm = 0;
			for (int j = i; j < (i + 5); j++)
			{
				sm += out[j];
			}
			if (sm < 0)def++;
		}
		if (def == 8)
		{
			if (m < sum1)
			{
				m = sum1;
			}
		}
		
		return;
	}
	out[indx] = s;
	solve(indx + 1, sum1 + s);
	out[indx] = -d;
	solve(indx + 1, sum1 - d);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d %d", &s, &d) == 2)
	{
		m = -1;
		solve(0, 0);
		if (m > 0)
		{
			cout << m << endl;
		}
		else
		{
			cout << "Deficit" << endl;
		}
	}
	return 0;
}