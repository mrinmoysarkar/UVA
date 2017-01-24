#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<cstdio>
using namespace std;

#define abs(a) a<0?-a:a

int grid[100][100];
int origin[30];
int n;
void init_ori()
{
	for (int i = 0; i < 30; i++)
	{
		origin[i] = 0;
	}
}
class queue{
public:
	int size = 1000;
	int A[1000];
	int font, rare;

	queue()
	{
		font = 0;
		rare = 0;
		for (int i = 0; i < 1000; i++)A[i] = 0;
	}
	int data_at(int indx)
	{
		return A[indx];
	}

	void print()
	{
		for (int i = 0; i < n; i++)cout << A[i] << " ";
		cout << endl;
	}
	int pop()
	{

		if (font == size)
		{
			font = 0;
		}
		int data = A[font];
		font += 1;
		return data;
	}
	int push(int data)
	{
		int i = 0;
		for (; i < rare; i++)
		{
			if (data == A[i])
			{
				break;
			}
		}
		if (i != rare) return 0;
		if (rare == size)
		{
			rare = 0;
		}

		A[rare] = data;
		rare++;
		return 1;
	}
	int isempty()
	{
		return font - rare;
	}
	int length(void)
	{
		return abs(rare - font);
	}
	void reset()
	{
		font = 0;
		rare = 0;
		for (int i = 0; i < 1000; i++)A[i] = 0;
	}

};

void init_grid()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void print_grid()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	freopen("Text.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	queue loop;
	
	//cout << loop.font << "   " << loop.rare << endl;
	int T = 1;
	while (true)
	{
		init_grid();
		int source = 1;
		int dest = 5;
		//cin >> n;
		n = 20;
		for (int i = 1; i < n; i++)
		{
			int m;
			if (scanf("%d", &m) != 1)return 0;
			else if (i == 1)
			{
				cout << "Test Set #" << T << endl;
				T++;
			}
			//cin >> m;
			for (int j = 0; j < m; j++)
			{
				int x;
				cin >> x;
				grid[i][x] = 1;
				grid[x][i] = 1;
			}
		}
		//print_grid();
		int query;
		cin >> query;
		for (int q = 0; q < query; q++)
		{
			cin >> source >> dest;
			//cout << source << " to " << dest << ": ";
			printf("%2d to %2d: ", source, dest);
			//cout << "S:" << source << " D:" << dest << endl;
			init_ori();
			loop.reset();
			loop.push(source);
			int xd = 1;
			int flag = 0;
			int k = 0;
			while (xd)
			{
				//cout << source << endl;
				flag = 0;

				for (int i = 1; i <= n; i++)
				{
					if (grid[source][i])
					{
						//cout << "ok";
						if (loop.push(i))
						{
							flag = 1;
							//cout << i << endl;
							origin[k] = source;
							k++;
						}

						if (i == dest)
						{
							xd = 0;
							break;
						}
					}
				}
				source = loop.pop();

			}
			//cout << origin.length() << endl;

			//loop.print();
			//loop.print();
			//for (int ii = 0; ii < k; ii++)
			//{
			//		cout << origin[ii] << " ";
			//}
			//cout << endl;
			int last_indx = loop.rare - 2;
			int no_of_k = 0;
			if (k > 0)
			{
				no_of_k++;
				int d = origin[k - 1];
				//cout << dest << " " << d << " ";
				//cout << last_indx << endl;

				for (int tx = last_indx; tx > 0; tx--)
				{
					if (loop.data_at(tx) == d)
					{
						no_of_k++;
						//cout << tx;
						d = origin[tx - 1];
						//			cout << d << " ";
					}
				}
			}
			cout << no_of_k << endl;
			
		}
		//*/
		cout << endl;
	}
	return 0;
}