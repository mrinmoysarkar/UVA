
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
#define MAX 1002
int grid[MAX][MAX];
vector<int> sgrid[MAX];
int row, col;

void init_grid()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			grid[i][j] = 0;
		}
	}
}
void print_grid()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

}
void init_s_grid()
{
	for (int i = 0; i < row; i++)
	{
		cout <<i<<endl;
		for (int j = 0; j < col; j++)
		{
			if (!grid[i][j])
			{
				int node_no = col*i + j;
				//cout << "N: " << node_no << " : ";
				if ((i + 1) < row)
				{
					if (!grid[i + 1][j])
					{
						int d_node = col*(i + 1) + j;
						sgrid[node_no].push_back(d_node);
						//cout << d_node << " ";
					}
				}
				if ((i - 1) >= 0)
				{
					if (!grid[i - 1][j])
					{
						int d_node = col*(i - 1) + j;
						sgrid[node_no].push_back(d_node);
						//cout << d_node << " ";
					}
				}
				if ((j + 1) < col)
				{
					if (!grid[i][j + 1])
					{
						int d_node = col*i + j + 1;
						sgrid[node_no].push_back(d_node);
						//cout << d_node << " ";
					}
				}
				if ((j - 1) >= 0)
				{
					if (!grid[i][j - 1])
					{
						int d_node = col*i + j - 1;
						sgrid[node_no].push_back(d_node);
						//cout << d_node << " ";
					}
				}
				//cout << endl;
			}
		}
	}
}
void init_var()
{
	for (int i = 0; i < MAX; i++)
	{
		sgrid[i].clear();
	}
}
class data_structure{
public:
	int data_structure_type;
	int font, rare;
	vector<int> A;
	data_structure(int type)//type =0 queue; 1 stack; 2 priority queue 
	{
		font = rare = 0;
		data_structure_type = type;
	}
	void reset()
	{
		font = rare = 0;
		A.clear();
	}
	bool push(int data)
	{
		switch (data_structure_type)
		{
		case 0:
			//A[font] = data;
			A.push_back(data);
			font++;
			break;
		case 1:
			//A[font] = data;
			A.push_back(data);
			font++;
			break;
		case 2:
			if (!is_in_array(data))
			{
				//A[font] = data;
				A.push_back(data);
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
	freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);
	///*
	while (1)
	{	
		cin >> row >> col;
		if (row == 0 )
		{
			break;
		}
		init_grid();
		//init_var();
		int R_CB;
		cin >> R_CB;
		for (int i = 0; i < R_CB; i++)
		{
			int r, b;
			cin >> r >> b;
			for (int j = 0; j < b; j++)
			{
				int c;
				cin >> c;
				grid[r][c] = 1;
			}
		}
		//cout << row << " " << col << endl;
		//print_grid();
		init_s_grid();
		int s1, s2;
		cin >> s1 >> s2;
		int source = s1*col + s2;
		cin >> s1 >> s2;
		int dest = s1*col + s2;
		cout << source << " " << dest << endl;
		/*
		que.reset();
		label.reset();
		que.push(source);
		que.pop();
		int l = 0;
		int w = 1;
		while (w)
		{
			for (int dat : sgrid[source])
			{
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
				sgrid[source].clear();
				source = que.pop();
				if (que.rare > que.font)
				{
					break;
				}
				l = label.pop();
			}
		}
		if (!w)
		{
			cout << (l + 1) << endl;
		}*/
	}	
	return 0;
}
