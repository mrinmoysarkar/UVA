#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
int A[100];
int sind[101][50001];
int sum;
int N;
int coin(int i, int sum1)
{

	if (i == N)
	{
		int sum2 = sum - sum1;
		sum2 -= sum1;
		sind[i][sum1] = sum2 < 0 ? -sum2 : sum2;
		return sind[i][sum1];
	}
	if (sind[i][sum1] != -1)return sind[i][sum1];

	int left = coin(i + 1, sum1);
	int right = coin(i + 1, sum1+A[i]);
	sind[i][sum1] = left < right ? left : right;
	return sind[i][sum1]; 

}
int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int t;
cin >> t;
for (int T = 0; T < t;T++)
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 50001; j++)
			sind[i][j] = -1;

	sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	cout << coin(0, 0) << endl;
}
return 0;
}

