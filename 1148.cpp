#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

#define MAX 100001
vector<int> grid[MAX];
int M, N, P;

class str_data{
public:
	char data[100][2];
	int last_ind;
	str_data()
	{
		last_ind = 0;
	}
	void reset(){ last_ind = 0; }
	int insert(char *d)
	{
		int i = is_in_data(d);
		if (i == -1)
		{
			data[last_ind][0] = d[0];
			data[last_ind][1] = d[1];
			last_ind++;
		}
		return i;
	}
	int is_in_data(char *d)
	{
		for (int i = 0; i < last_ind; i++)
		{
			if (data[i][0] == d[0] && data[i][1] == d[1])
			{
				return i;
			}
		}
		return -1;
	}
	void print()
	{
		for (int i = 0; i < last_ind; i++)
		{
			cout << data[i][0] << data[i][1] << " ";
		}
		cout << endl;
	}
};

void init_var()
{
	for (int i = 0; i < MAX; i++)
	{
		grid[i].clear();
	}
}

void print_grid()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

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
	bool is_in_array(int data)
	{
		for (int i = 0; i < font; i++)
		{
			if (A[i] == data)
			{
				return true;
			}
		}
		return false;
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
			cout << A[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	//freopen("i.txt", "r", stdin);

	//freopen("o.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		if (t != 1)cout << endl;
		init_var();
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int node;
			int node_no;
			cin >> node >> node_no;
			for (int j = 0; j < node_no; j++)
			{
				int b;
				cin >> b;
				grid[node].push_back(b);
			}
		}
		///*
		int source, dest;
		cin >> source >> dest;
		int s = source;
		que.reset();
		label.reset();
		que.push(source);
		que.pop();
		int l = 0;
		int w = 1;
		while (w)
		{
			for (int dat : grid[source])
			{
				//int dat = grid[source].at(i);
				if (dat == dest)
				{
					w = 0;
					break;
				}
				if (que.push(dat))
				{
					label.push(l + 1);
				}

			}

			if (w)
			{
				source = que.pop();
				if (que.rare > que.font)
				{
					break;
				}
				l = label.pop();
			}
		}
		printf("%d %d %d\n", s, dest, l);
		//*/
	}	
return 0;
}