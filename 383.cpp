#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 100
int grid[MAX][MAX];
int M ,N ,P;

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
		for (int j = 0; j < MAX; j++)
		{
			grid[i][j] = 0;
		}
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
	int A[1000];
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
	freopen("text.txt", "r", stdin);

	freopen("0.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);
	str_data code;
	int T;
	cin >> T;
	if (T)
		cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
	for (int t = 1; t <= T; t++)
	{
		code.reset();
		init_var();
		cout << "DATA SET  " << t << endl << endl;
		cin >> M >> N >> P;
		char c[3];
		for (int i = 0; i < M; i++)
		{
			cin >> c;
			code.insert(c);
		}
		//code.print();
		for (int i = 0; i < N; i++)
		{
			cin >> c;
			//cout << c << " ";
			int x = code.is_in_data(c);
			cin >> c;
			//cout << c << endl;
			int y = code.is_in_data(c);
			if (x != -1 && y != -1)
			{
				grid[x][y] = 1;
				grid[y][x] = 1;
			}
		}
		//print_grid();
		for (int i = 0; i < P; i++)
		{
			int multiply;
			cin >> multiply;
			cin >> c;
			int source = code.is_in_data(c);
			cin >> c;
			int dest = code.is_in_data(c);
			if (source != -1 && dest != -1)
			{
				que.reset();
				label.reset();
				//cout << "sou: " << node_val[xi] << " in " << xi << endl;
				que.push(source);
				que.pop();
				int no_of_push = 0;
				int l = 0;
				//cout << node_indx << endl;
				int w = 1;
				while (w)
				{
					for (int i = 0; i < code.last_ind; i++)
					{
						if (grid[source][i] && source != i)
						{
							//cout << "S: " << source << " " << i << endl;
							if (i == dest)
							{
								w = 0;
								break;
							}

							if (que.push(i))
							{
								no_of_push++;
								label.push(l + 1);
							}

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
				if (!w)
				{
					cout << "$"<<(l+1)*100*multiply << endl;
				}
				else
				{
					cout << "NO SHIPMENT POSSIBLE" << endl;
				}
			}

		}
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}