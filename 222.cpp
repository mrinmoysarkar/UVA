#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX1 1000
double target;
double tank_capacity;
double h_tc;
double d_per_galon;
double fixed_cost;
int no_of_station;
double s_d[MAX1];
double s_d_c[MAX1];
double total_distance;
int used[MAX1];
double min_cost;
void init_used()
{
	for (int i = 0; i < no_of_station; i++)
	{
		used[i] = 0;
	}
}
double round_up(double value)
{
	double val = ((int)(value * 100 + .5) / 100.0);
	return val;
}
void solve(double required_d, double cost, int indx,double s)
{
	
	if (indx == no_of_station)
	{
		//cout << cost << endl;
		if (int(cost*100.0) > 0 )
		{
			min_cost = min_cost > cost ? cost : min_cost;
			//cout << (cost) << endl;
		}
		return;
	}
	double ca = (s_d[indx] - s) / d_per_galon;
	double co = round_up((200.0+ca*s_d_c[indx])/100.0);
	//cout << co << endl;
	double md = round_up((tank_capacity - ca)*d_per_galon);
	if (md<required_d && md < s_d[indx+1] - s_d[indx])
	{
		solve(required_d - s_d[indx] + s, round_up(cost + co), indx + 1, s_d[indx]);
	}
	else if (ca > h_tc && md < required_d)
	{
		solve(required_d - s_d[indx] + s, round_up(cost + co), indx + 1, s_d[indx]);
		solve(required_d, cost, indx + 1, s);
	}
	else
	{
		solve(required_d, cost, indx + 1, s);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1;
	while (scanf("%lf", &target) == 1 && target > 0)
	{
		cin >> tank_capacity >> d_per_galon >> fixed_cost >> no_of_station;
		total_distance = round_up(tank_capacity*d_per_galon);
		//cout << total_distance << endl;
		h_tc = round_up(tank_capacity / 2);
		for (int i = 0; i < no_of_station; i++)
		{
			cin >> s_d[i] >> s_d_c[i];
		}
		s_d[no_of_station] = target;
		if (total_distance >= target)
		{
			min_cost = 0;
		}
		else
		{
			min_cost = 100000.00;
			solve(target, 0, 0, 0);
		}
		cout << "Data Set #" << t << endl;
		printf("minimum cost = $%.2f\n", round_up(min_cost+fixed_cost));
		t++;
	}
	return 0;
}