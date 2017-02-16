
#include<iostream>
#include<stdio.h>

using namespace std;

int cumalative_sum[30000];



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int test;
	int r;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> r;
		r = r - 1;
		cumalative_sum[0] = 0;
		int all_neg = 1;
		int r1 = 1, r2 = 1;
		int r0 = 1;
		int max = -(1<<20);
		for (int i = 0; i < r; i++)
		{
			cin >> cumalative_sum[i];
			if (cumalative_sum[i] > 0)all_neg = 0;
			if (i != 0)
			{
				cumalative_sum[i] += cumalative_sum[i - 1];
			}

			if (cumalative_sum[i] > max || (cumalative_sum[i] == max && (i + 2 - r0 > r2 - r1)))
			{
				max = cumalative_sum[i];
				r1 = r0;
				r2 = i + 2;
			}
			if (cumalative_sum[i] < 0)
			{
				cumalative_sum[i] = 0;
				r0 = i + 2;
				r1 = max <= 0 ? r0 : r1;
			}
		}
		if (all_neg == 1)
		{
			cout << "Route "<< t << " has no nice parts" << endl;
		}
		else
		{
			cout << "The nicest part of route " << t << " is between stops " << r1 << " and " << r2 << endl;
		}
	}
	return 0;
}

