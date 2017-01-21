#include<cstdio>
#include<iostream>

using namespace std;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (x >= y && x <= z || x <= y && x >= z)
		{
			cout << "Case " << i << ": " << x << endl;
		}
		else if (y >= x && y <= z || y <= x && y >= z)
		{
			cout << "Case " << i << ": " << y << endl;
		}
		else if (z >= y && z <= x || z <= y && z >= x)
		{
			cout << "Case " << i << ": " << z << endl;
		}
	}
	return 0;
}