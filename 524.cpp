#include<cstdio>
#include<iostream>
using namespace std;
int N;
int used[100];
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };
int dat[100];
int out[100];
void isprime()
{
	for (int i = 0; i < 100; i++)dat[i] = used[i] = 0;
	for (int i = 0; i < 13; i++)dat[prime[i]] = 1;
}
void solve(int indx,int data)
{
	if (indx == N)
	{
		if (dat[out[0] + out[N - 1]]){
			for (int i = 0; i < N; i++)
			{
				cout << out[i];
				if(i!=(N-1))cout << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!used[i] && dat[i+data])
		{
			used[i] = 1;
			out[indx] = i;
			solve(indx + 1, i);
			used[i] = 0;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	isprime();
	int t = 1;
	int N1;
	while (scanf("%d", &N) == 1)
	{
		if (t != 1)cout << endl;
		cout << "Case " << t << ":" << endl;
		t++;
		out[0] = 1;
		used[1] = 1;
		solve(1, 1);
	}
	return 0;
}