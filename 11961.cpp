#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N,K;
string output;
string data="ACGT";
vector<string> out;
int NN;
int no;
string s;

int dif()
{
	int d = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i] != output[i])
		{
			d++;
		}
	}
	return d;
}

void solve(int indx)
{
	if(indx == N)
	{
		if (dif() <= K)
		{
			//cout << output << endl;
			out.push_back(output);
			no++;
		}
		return;
	}
	for(int i=0;i<4;i++)
	{
		output[indx] = data[i];
		solve(indx+1);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		cin >> s;
		output = s;
		no = 0;
		//NN = N > 4 ? N : 4;
		out.clear();
		solve(0);
		cout << no << endl;
		for (int i = 0; i < no; i++)
		{
			cout << out[i] << endl;
		}
	}
	return 0;
}

