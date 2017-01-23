#include<iostream>
#include<cstdio>

using namespace std;
#define MAX 10000

class num{
public:
	int start_time, end_time, dest;
};

num table[MAX];
void init_var()
{
	for (int i = 0; i < MAX; i++)
	{
		table[i].dest = 0;
		table[i].end_time = 0;
		table[i].start_time = 0;
	}
}
int main()
{
	freopen("Text.txt", "r", stdin);
	
	int N;
	cin >> N;
	for (int ii = 0; ii<N; ii++)
	{
		init_var();
		while (true)
		{
			int number;
			cin >> number;
			if (number == 0)break;
			int st, et, dest;
			cin >> st >> et >> dest;
			table[number].start_time = st;
			table[number].end_time = st + et;
			table[number].dest = dest;
			//cout << st << "  " << et << "  " << dest << endl;
		}
		cout << table[1111] << "  " << et << "  " << dest << endl;
		while (true)
		{
			int time, source;
			cin >> time;
			if (time == 9000) break;
			cin >> source;
			int s = source;
			//cout << time << " " << source << endl;
			while (true)
			{
				if (time >= table[source].start_time && time <= table[source].end_time)
				{
					source = table[source].dest;
					cout << source << endl;
					if (s == source)
					{
						cout << "AT " << time << " CALL TO " << s << " RINGS 9999" << endl;
						break;
					}
				}
				else
				{
					cout << "AT " << time << " CALL TO " << s << " RINGS " << source << endl;
					break;
				}

			}
		}

	}

	return 0;
}
