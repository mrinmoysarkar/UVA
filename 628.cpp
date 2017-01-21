#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
#define MAX1 101
#define MAX2 1001
string dic[MAX1];
int r, c;
string rule;
int N;
string output[MAX2];
string num[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
int used[MAX2];
int p = 1;
int cp;
void init()
{
	for (int i = 0; i < N; i++)used[i] = 0;
}
void solve(int indx)
{
	if (indx == N)
	{
		cp++;
		for (int i = 0; i < N; i++)
		{
			cout << output[i];
		}
		cout << endl;
		return;
	}

		if (rule[indx] == '0' && !used[indx])
		{
			for (int j = 0; j < 10; j++)
			{
				used[indx] = 1;
				output[indx] = num[j];
				solve(indx + 1);
				used[indx] = 0;
			}
		}
		else if (rule[indx] == '#' && !used[indx])
		{
			for (int j = 0; j < c; j++)
			{
				used[indx] = 1;
				output[indx] = dic[j];
				solve(indx + 1);
				used[indx] = 0;
			}
		}
	
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	while (scanf("%d", &c) == 1)
	{
		for (int i = 0; i < c; i++)
		{
			cin >> dic[i];
		}
		int n;
		cin >> n;
		cout << "--" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> rule;
			N = rule.length();
			init();
			solve(0);
		}
	}
	return 0;
}
