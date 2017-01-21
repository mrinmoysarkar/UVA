#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string data[100];
string output[100];
int N;

void solve2(int indx,int NN,int go)
{
	if (indx == NN)
	{
		for (int i = 0; i < NN; i++)
		{
			cout << output[i];
			if (i != (NN - 1))cout << ", ";
		}
		cout << endl;
		return;
	}
	for (int i = go; i < N; i++)
	{
			output[indx] = data[i];
			solve2(indx + 1, NN,i+1);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	string line;
	int all;
	int st, sto;
	getline(cin, line);
	sscanf(line.c_str(), "%d", &t);
	getline(cin, line);
	int T = 0;
	while (t--)
	{
		if (T)cout << endl;
		T = 1;
		all = 0;
		st = 0; sto = 0;
		getline(cin, line);
		if (line.length() == 1 && line[0] == '*')
		{
			all = 1;
		}
		else
		{
			if (sscanf(line.c_str(), "%d %d", &st, &sto) == 1){
				sto = st;
			}
		}
		N = 0;
		while (true)
		{
			getline(cin, line);
			if (line.length() == 0)break;
			data[N] = line;
			N++;
			if (cin.eof())break;
		}
		if (all){ st = 1; sto = N; }
		for (int i = st; i <= sto; i++)
		{
			cout << "Size " << i << endl;
		    solve2(0, i,0);
			cout << endl;
		}
	}
	return 0;
}