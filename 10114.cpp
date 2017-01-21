#include<cstdio>
#include<iostream>
using namespace std;

double depri[200];

double owe, worth;
void init()
{
	for (int i = 0; i < 200; i++)
	{
		depri[i] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (true)
	{
		int m;
		cin >> m;
		if (m < 0)break;
		init();
		double interest;
		int n;
		cin >> interest >> owe >> n;
		worth = owe;
		for (int i = 0; i < n; i++)
		{
			int mon;
			double rate;
			cin >> mon >> rate;
			depri[mon] = rate;
		}
		double rate=0;
		for (int i = 0; i < m; i++)
		{
			if (depri[i] != 0)rate = depri[i];
			owe -= interest; cout << "O: "<<owe << endl;
			worth *= (1 - rate); cout << "w: " << worth << endl;
			if (owe < worth)
			{
				cout << (i + 1);
				if (i == 0)cout << " month" << endl;
				else cout << " months" << endl;
				break;
			}

		}
	}
	return 0;
}
