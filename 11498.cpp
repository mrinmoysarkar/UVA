#include<cstdio>
#include<iostream>

using namespace std;




int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N;
	while (scanf("%d", &N) == 1 && N != 0)
	{
		int x0, y0;
		cin >> x0 >> y0;
		int x, y;
		for (int i = 0; i < N; i++)
		{
			cin >> x >> y;
			int dx, dy;
			dx = x - x0;
			dy = y - y0;
			if (dx == 0 || dy == 0)
			{
				cout << "divisa" << endl;
			}
			else if (dx > 0 && dy > 0)
			{
				cout << "NE" << endl;
			}
			else if (dx > 0 && dy < 0)
			{
				cout << "SE" << endl;
			}
			else if (dx < 0 && dy > 0)
			{
				cout << "NO" << endl;
			}
			else if (dx < 0 && dy < 0)
			{
				cout << "SO" << endl;
			}
		}
	}
	return 0;
}