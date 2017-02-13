#include<iostream>
#include<cstdio>

using namespace std;
#define MAX 2000
int grid[MAX][MAX];
int no_of_node;
int node_val[MAX];


class data_structure{
public:
	int data_structure_type;
	int font, rare;
	int A[MAX];
	data_structure(int type)//type =0 queue; 1 stack; 2 priority queue 
	{
		font = rare = 0;
		data_structure_type = type;
	}
	int data_at(int indx)
	{
		return A[indx];
	}
	void reset()
	{
		font = rare = 0;
	}
	bool push(int data)
	{
		switch (data_structure_type)
		{
		case 0:
			A[font] = data;
			font++;
			break;
		case 1:
			A[font] = data;
			font++;
			break;
		case 2:
			if (!is_in_array(data))
			{
				A[font] = data;
				font++;
				return true;
			}
			return false;
			break;
		}
		return true;
	}
	int is_in_array(int data)
	{
		for (int i = 0; i < font; i++)
		{
			if (A[i] == data)
			{
				return i;
			}
		}
		return 0;
	}
	int pop()
	{
		switch (data_structure_type){
		case 0:
		case 2:

			return A[rare++];
		case 1:
			return A[--font];
		default:
			return 0;
		}
	}
	void print(){
		for (int i = 0; i < font; i++)
		{
			cout << A[i] << endl;
		}
		//cout << endl;
	}
};

void init_variable()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			grid[i][j] = 0;
		}
	}
}


int main()
{
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);
	int T;
	cin >> T;
	bool bs = false;
	while (T--)
	{
		if (bs)cout << endl;
		bs = true;
		init_variable();
		int N;
		cin >> N;
		int D;
		cin >> D;
		for (int i = 0; i < D; i++)
		{
			int x, y;
			cin >> x >> y;
			grid[x][y] = 1;
			grid[y][x] = 1;
		}
		que.reset();
		label.reset();
		int source = 0;
		que.push(source);
		que.pop();
		int l = 0;
		while (true)
		{
			for (int i = 0; i < N; i++)
			{
				if (grid[source][i] && source != i)
				{
					if (que.push(i))
					{
						label.push(l + 1);
					}
				}
			}
			source = que.pop();
			if (que.rare > que.font)
			{
				break;
			}
			l = label.pop();
		}
		//label.print();
		for (int i = 1; i < N; i++)
		{
			int in = que.is_in_array(i) - 1;
			cout << label.data_at(in) << endl;
		}
	}
	return 0;
}