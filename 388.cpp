#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 27
int data[27];
double value[27];
int grid[MAX][MAX];
double multiplier[26];
double output[MAX];
double gmax = -1.0;

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

void init_multiplier()
{
	multiplier[0] = 1;
	for (int i = 1; i < 26; i++)
	{
		multiplier[i] = multiplier[i - 1] * 0.95;
	}
}

void init_variable()
{
	for (int i = 0; i < MAX; i++)
	{
		output[i] = 0;
		data[i] = 0;
		value[i] = 0;
		for (int j = 0; j < MAX; j++)
		{
			grid[i][j] = 0;
		}
	}
}

void print()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

void print_output()
{
	for (int i = 0; i < MAX; i++)
	{
		if (output[i] == gmax)
		{
			char c = 'A' + i;
			cout << "Import from " << c << endl;
			break;
			//printf("%.2f ", output[i]);
		}
	}
	//cout << endl;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);
	init_multiplier();
	int N;
	while (scanf("%d", &N) == 1)
	{
		gmax = -1.0;
		//cout << "test" << endl;
		init_variable();
		for (int i = 0; i < N; i++)
		{
			char c;
			cin >> c;
			int x = c - 'A';
			data[x] = 1;
			double v;
			cin >> v;
			value[x] = v;
			char ch[30];
			cin >> ch;
			int j = 0;
			while (ch[j])
			{
				c = ch[j];
				int y;
				if (c == '*') y = 26;
				else y = c - 'A';
				grid[x][y] = 1;
				grid[y][x] = 1;
				j++;
			}//*/
		}
		//print();
		//cout << endl << endl;
		
		
		for (int ii = 0; ii < MAX - 1; ii++)
		{
			if (data[ii])
			{
				if (gmax > value[ii]) continue;
				int source = ii;
				int dest = 26;
				que.reset();
				label.reset();
				que.push(source);
				que.pop();
				int no_of_push = 0;
				int l = 0;
				int w = 1;
				while (w)
				{	
					for (int i = 0; i <MAX; i++)
					{
						if (grid[source][i] && source != i)
						{
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
				//cout << l << endl;
				if (!w)
				{
					output[ii] = value[ii] * multiplier[l];
					//output[ii] = ((int)(output[ii] * 100 + .5) / 100.0);
					if (output[ii] > gmax) gmax = output[ii];
				}

			}
		}
		print_output();
	}
}
