
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

char A[12];
int N = 12;
int dp[1 << 15 + 2];

void init_dp()
{
	for (int i = 0; i < (1 << 15 + 2); i++)
	{
		dp[i] = -1;
	}
}

int set(int N, int pos){ return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~(1 << pos); }
bool check(int N, int pos){ return (bool)(N & (1 << pos)); }

int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a < b ? b : a;
}

int countBits(int bitmask){
	int count = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (bitmask & 1 << i)count++;
	}
	if (count == N)return count;
	for (int i = 0; i < N - 1; i++)
		if ((bitmask & 1 << i) != 0 && (bitmask & 1 << (i + 1)) != 0)
			return -1;
	return count;
}

int move(int mask)
{
	int mask2 = countBits(mask);
	//cout << mask2 << endl << endl;
	if (mask2 != -1) return dp[mask] = mask2;
	
	if (dp[mask] != -1)return dp[mask];
	int mov = 0;
	int ans = 1 << 12;
	
	for (int i = 0; i < N; i++)
	{
		if ((i+2 < N) && check(mask, i) && check(mask, i + 1) && !check(mask, i + 2))
		{
			mask2 = reset(mask, i);
			mask2 = reset(mask2, i + 1);
			mask2 = set(mask2, i + 2);
			ans = min(move(mask2),ans);

		}
		if ((i > 1) && check(mask, i) && check(mask, i - 1) && !check(mask, i - 2))
		{
			mask2 = reset(mask, i);
			mask2 = reset(mask2, i - 1);
			mask2 = set(mask2, i - 2);
			ans = min(move(mask2), ans);
		}
	}
	return dp[mask] = ans;
}

int main()
{
	freopen("Text.txt", "r", stdin);
	int test;
	cin >> test;
	
	//init_dp();
	init_dp();
	for (int t = 0; t < test; t++)
	{
		int mask = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
			if (A[i] == 'o')
			{
				mask |= 1 << i;
			}
		}
		cout << move(mask) << endl;
	}
	return 0;
}