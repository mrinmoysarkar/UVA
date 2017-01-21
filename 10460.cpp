#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string output;
int used[100];
int N;
string data;
int n;
int trg;
void init()
{
	for (int i = 0; i < N; i++)
	{
		used[i] = 0;
	}
}

string put_c(int i, int indx, char ch, string output)
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
	if (n == trg)return;
	if (indx == N)
	{
		n++;
		if (n == trg)
		{
			for (int i = 0; i < N; i++)
				cout << output[i];
			cout << endl;
		}
		return;
	}
	string s = output;
	for (int i = 0; i <= indx; i++)
	{

		output = put_c(i, indx, data[indx], s);
		solve(indx + 1);
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	int tt;
	cin >> tt;
	while (tt--)
	{
		cin >> data;// cout << "D:" << data<<"    ";
		cin >> trg; //cout << "T: " << trg ;
		N = data.length(); //cout << " N: " << N << endl;
		trg--;
		for (int i = N; i > 0; i--)
		{
			used[i-1] = trg%i;
			trg = trg / i;
		}
		/*
		for (int i = 0; i < N; i++)
		{
			cout << used[i] << " ";
		}
		*/
		output = "";
		for (int i = 0; i <N; i++)
		{

			output = put_c(used[i], i, data[i], output);
		}
		//cout << endl;
		if (N != 0)
		{
			//output = "";
			cout << output << endl;
			//n = 0;
			//solve(0);
		}
		data = "";
	}
	return 0;
}