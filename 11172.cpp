#include<iostream>
using namespace std;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t; 
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		if (x > y)cout << ">" << endl;
		if (x < y)cout << "<" << endl;
		if (x == y)cout << "=" << endl;
	}
	return 0;
}