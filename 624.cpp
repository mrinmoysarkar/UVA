#include<stdio.h>
#include<iostream>
using namespace std;
int data[1000];
int A[1000];
int N;
int target;
int mi;
int output[1000];
int foutput[1000];
int outi;
int found = 0;
int fin;
int s = 0;
int total_sum;
int solve(int indx)
{
	//if (found)return 0;
	if (indx == N)
	{
		outi = 0;
		int sum1=0;
		for (int i = 0; i < N; i++)
		{
			if (A[i])
			{
				output[outi] = data[i];
				sum1 += data[i];
				outi++;
			}
		}
		int d = target - sum1;
		if (d == 0)
		{
			if (outi > fin || found)
			{
				//cout << "got it" << endl;
				for (int i = 0; i < outi; i++)foutput[i] = output[i];
				fin = outi;
				found = 0;
				s = sum1;
				mi = d;
			}
		}
		else if (d > 0)
		{
			if (d < mi)
			{
				mi = d;
				for (int i = 0; i < outi; i++)foutput[i] = output[i];
				fin = outi;
				s = sum1;
			}
			else if (d == mi && fin < outi)
			{
				mi = d;
				for (int i = 0; i < outi; i++)foutput[i] = output[i];
				fin = outi;
				s = sum1;
			}
		}
		return 0;
	}
	A[indx] = 0;
	solve(indx + 1);
	A[indx] = 1;
	solve(indx + 1);
	return 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (scanf("%d",&target) == 1)
	{
		//cin >> target;
		cin >> N;
		mi = 1<<8;
		fin = mi;
		found = 1;
		total_sum = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> data[i];
			total_sum += data[i];
		}
		solve(0);
		//int s = 0;
		for (int i = 0; i < fin; i++)
		{
			cout << foutput[i] << " ";
			//s += foutput[i];
		}
		cout << "sum:" << s << endl;
	}
	return 0;
}