#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string data;
char output[1000];
int N;
string key[1000];
char value[1000];
int N_I;
int total_code;


void print_val_key()
{
	for (int i = 0; i < N; i++)
	{
		cout << "val: " << value[i] << " key: " << key[i] << endl;
	}

}

void sort_data()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < (N - 1); j++)
		{
			if (value[j] > value[j + 1])
			{
				char c = value[j];
				value[j] = value[j + 1];
				value[j + 1] = c;
				string s = key[j];
				key[j] = key[j + 1];
				key[j + 1] = s; 
			}
		}
	}
}
void dfs(int indx, int oi, bool zz)
{
	if (total_code == 100)return;
	if (indx == N_I)
	{
		if (zz)
		{
			output[oi] = '\0';
			cout << output << endl;
			total_code++;
		}
		return;
	}
	if (data[indx] == '0')
	{
		dfs(indx + 1, oi,false);
	}
	else
	{
		for (int i = 0; i<N; i++)
		{
			string s = key[i];
			int l = s.length();
			int j;
			for (j = 0; j<l; j++)
			{
				if (s[j] != data[j + indx])
				{
					break;
				}
			}
			if (j == l)
			{
				output[oi] = value[i];
				dfs(indx + l, oi + 1,true);
			}

		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T = 1;
	while (1)
	{
		cin >> N;
		if (!N)break;
		for (int i = 0; i<N; i++)
		{
			cin >> value[i];
			cin >> key[i];
		}
		//print_val_key();
		sort_data();
		//cout << endl;
		//print_val_key();
		cin >> data;
		N_I = data.length();
		cout << "Case #" << T << endl;
		total_code = 0;
		if (data[0] == '0')
		{
			dfs(0, 0, false);
		}
		else
		{
			dfs(0, 0, true);
		}
		T++;
		cout << endl;
	}
	return 0;
}

