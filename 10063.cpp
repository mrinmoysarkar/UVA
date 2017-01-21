#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string output;
int used[100];
int N;
string data;

void init()
{
	for (int i = 0; i < N; i++)
	{
		used[i] = 0;
	}
}

string put_c(int i,int indx,char ch,string output)
{
	output += ' ';
	for (; indx > i; indx--)
	{
		output[indx] = output[indx - 1];
	}
	output[i] = ch;
	return output;
}

void solve(int indx)
{
	if (indx == N)
	{
		for (int i = 0; i < N;i++)
				cout << output[i];
		cout << endl;
		return;
	}
	//output[indx] = data[indx];
	string s = output;
	for (int i = 0; i <= indx; i++)
	{
		
		output=put_c(i, indx, data[indx],s);
		solve(indx + 1);
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	int nl = 0;
	while (!cin.eof())
	{
		
		getline(cin,data);
		N = data.length();
		if (N != 0)
		{
			if (nl)cout << endl;
			nl = 1;
			output = "";
			solve(0);
		}
	}
	return 0;
}