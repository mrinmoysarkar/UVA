#include<iostream>
#include<cstdio>

using namespace std;
#define MAX 31
int grid[MAX][MAX];
int no_of_node;
int node_val[MAX];
int xi, yi;
int node_indx;

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

void init_variable()
{
	for (int i = 0; i < MAX; i++)
	{
		node_val[i] = -1;
		for (int j = 0; j < MAX; j++)
		{
			grid[i][j] = 0;
		}
	}
}
void print_node_val()
{
	for (int i = 0; i < node_indx; i++)
	{
		cout << node_val[i] << " ";
	}
	cout << endl;
}
void print()
{
    for (int i = 1; i <= node_indx; i++)
	{
		for (int j = 1; j <= node_indx; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
void is_in_node(int x, int y)
{
	xi = 0; yi = 0;
	if (x == y)
	{
		for (int i = 0; i < node_indx; i++)
		{
			if (node_val[i] == x)
			{
				x = -1;
				xi = i + 1;
				return;
			}
		}
		if (x != -1)
		{
			node_val[node_indx] = x; node_indx++;
			xi = node_indx;
		}
	}
	for (int i = 0; i < node_indx; i++)
	{
		if (node_val[i] == x)
		{
			x = -1;
			xi = i + 1;
		}
		if (node_val[i] == y)
		{
			y = -1;
			yi = i + 1;
		}
		if (x == -1 && y == -1)return;
	}
	if (x != -1)
	{
		node_val[node_indx] = x; node_indx++;
		xi = node_indx;
	}
	if (y != -1)
	{
		node_val[node_indx] = y; node_indx++;
		yi = node_indx;
	}
	//cout << node_indx << "ind" << endl;
}
void find_x(int x)
{
	xi = -1;
	for (int i = 0; i < node_indx; i++)
	{
		if (node_val[i] == x)
		{
			x = 0;
			xi = i + 1;
			return;
		}
	}
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);
	int ca_se = 0;
	while (true)
	{
		cin >> no_of_node;
		if (no_of_node == 0) return 0;
		//cout << no_of_node << endl;
		node_indx = 0;
		init_variable();
		for (int i = 0; i < no_of_node; i++)
		{
			int x, y;
			cin >> x >> y;
			//cout << x << " " << y << endl;
			is_in_node(x, y);

			//cout << xi << " " << yi << endl;
			//print_node_val();
			grid[xi][yi] = 1;
			grid[yi][xi] = 1;
		}
		//cout << "dek" << endl;
		while (true)
		{
			
			int init_node, time;
			cin >> init_node >> time;
			if (!init_node && !time) break;
			ca_se++;
			//cout << "###########" << endl;
			find_x(init_node);
			if (xi == -1)
			{
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ca_se, node_indx , init_node, time);
				continue;
			}
			que.reset();
			label.reset();
			int source = xi;
			//cout << "sou: " << node_val[xi] << " in " << xi << endl;
			que.push(source);
			que.pop();
			int no_of_push = 0;
			int l = 0;
			//cout << node_indx << endl;
			while (true)
			{
				if ((l + 1) > time)break;
				for (int i = 1; i <= node_indx; i++)
				{
					if (grid[source][i] && source != i)
					{
						//cout << "S: " << source << " " << i << endl;
						if (que.push(i))
						{
							no_of_push++;
							label.push(l + 1);
						}

					}
				}
				if (no_of_push == (node_indx-1))
				{
					break;
				}
				source = que.pop();
				if (que.rare > que.font)
				{
					break;
				}
				l = label.pop();
				//cout << l << endl;
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ca_se, (node_indx - no_of_push-1), init_node, time);

			//que.print();
			//label.print();
			//print_node_val();
			//cout << no_of_push << endl;
			//cout << node_indx << endl;
		}
	}
	//print();
	return 0;
}