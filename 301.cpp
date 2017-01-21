#include<cstdio>
#include<iostream>
using namespace std;

int max_n;
int no_of_s;
int no_of_o;
int order[50][3];
int used[50];
int plat[50];
int g = 0;
int mama;
void fnc(){
	for (int i = 0; i < no_of_o; i++)
	{
		used[i] = 0; plat[i] = 0;
	}
}
int check(int i,int j,int k)
{
	for (; i < j; i++)
	{
		if ((plat[i] + k) > max_n)return 0;
	}
	return 1;
}
void update(int i, int j, int k)
{
	for (; i < j; i++)
	{
		plat[i] = plat[i] + k;
	}
}
int costc()
{
	int cost = 0;
	//cout << "start: ";
	for (int i = 0; i < no_of_o; i++)
	{
		if (used[i])
		{
			int c = (order[i][1] - order[i][0]) * order[i][2];
			cost += c;
			//cout << "i: "<< i <<" "<< c << " ";
		}
	}
	//cout << endl;
	return cost;
}
void solve(int indx)
{
	//cout << pas << endl;
	if (g)return;
	if (indx == no_of_o)
	{
		int cst = costc();
		mama = mama < cst ? cst : mama;
		//cout << cst<<endl;
		//g = 1;
		return;
	}
	if (check(order[indx][0], order[indx][1], order[indx][2]))
	{
		used[indx] = 1;
		update(order[indx][0], order[indx][1], order[indx][2]);
		solve(indx + 1);
		used[indx] = 0;
		update(order[indx][0], order[indx][1], -order[indx][2]);
		solve(indx + 1);
	}
	else
	{
		solve(indx+1);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (true)
	{
		cin >> max_n >> no_of_s >> no_of_o;
		if (max_n == 0 && no_of_s == 0 && no_of_o == 0)return 0;
		for (int i = 0; i < no_of_o; i++)
		{
			cin >> order[i][0] >> order[i][1] >> order[i][2];
		}
		fnc();
		mama = -1;
		solve(0);
		cout << mama << endl;
	}
	return 0;
}