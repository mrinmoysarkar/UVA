#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define min(x,y) x<y?x:y

int used[8];
int variable[8];
int output[8];
int final_output[8];
int X_CO[8];
int Y_CO[8];
double dis[8][8];
double sum = 0;
double gmin = 1 < 10;
int N;
int k = 0;
int test = 0;

double get_dis(int i, int j)
{
	int x = X_CO[i] - X_CO[j];
	int y = Y_CO[i] - Y_CO[j];
	x = x*x;
	y = y*y;

	return sqrt(x + y);
}

void copy_output()
{
	for (int i = 0; i < N; i++)
	{
		final_output[i] = output[i];
	}
}

void print_output()
{
	cout << "**********************************************************" << endl;
	cout << "Network #" << test << endl;
	if (final_output[0] < final_output[N - 1])
	{
		for (int i = 0; i < N - 1; i++)
		{
			int ind1 = final_output[i];
			int ind2 = final_output[i + 1];

			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", X_CO[ind1], Y_CO[ind1], X_CO[ind2], Y_CO[ind2], 16 + dis[ind1][ind2]);
		}
	}
	else
	{
		for (int i = N-1; i > 0; i--)
		{
			int ind1 = final_output[i];
			int ind2 = final_output[i - 1];

			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", X_CO[ind1], Y_CO[ind1], X_CO[ind2], Y_CO[ind2], 16 + dis[ind1][ind2]);
		}
	}
	cout << "Number of feet of cable required is ";
	printf("%.2f.\n", gmin);
	//cout << "**********************************************************" << endl;
}
void init_variable()
{
	for (int i = 0; i < N; i++)
	{
		used[i] = 0;
		variable[i] = i;
		for (int j = 0; j < N; j++)
		{
			dis[i][j] = 0;
		}
	}
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}

void print_f()
{
	for (int i = 0; i < N; i++)
	{
		cout << final_output[i] << " ";
	}
	cout << endl;
}

double solve(int indx)
{
	if (indx == N)
	{
		//print();
		double sum2 = (sum + (N - 1) * 16);
		double gmin1 = min(gmin, sum2);
		if (gmin1 != gmin)
		{
			gmin = gmin1;
			copy_output();
		}
		//cout << gmin << endl;
		//cout <<  sum2 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			int in1, in2;
			double sum1=0;
			output[k] = variable[i];
			if (k != 0) 
			{
				in1 = output[k - 1];

				in2 = output[k];
				
				if (dis[in1][in2] != 0)
				{
					sum1 = dis[in1][in2];
				}
				else
				{
					sum1 = get_dis(in1, in2);
					dis[in1][in2] = sum1;
					dis[in2][in1] = sum1;
				}
			}
			sum += sum1;
			k = k + 1;
			solve(indx + 1);
			used[i] = 0;
			k = k - 1;
			sum -= sum1;
		}

	}
	return 0;
}


int main()
{
	freopen("Text.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (true)
	{
		cin >> N;
		test++;
		if (N == 0)break;
		for (int i = 0; i < N; i++)
		{
			int x, y;
			cin >> x >> y;
			X_CO[i] = x;
			Y_CO[i] = y;
		}
		init_variable();
		k = 0;
		sum = 0;
		gmin = 1000;
		solve(0);
		print_output();
		//print_f();
		//format_final_output();
	}

	return 0;
}