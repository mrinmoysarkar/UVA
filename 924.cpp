#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;
#define MAX 2501

int grid[MAX][MAX];
int N;

class city{
public:
	char data[MAX][2];
	int last_indx;
	city()
	{
		last_indx = 0;
	}
	void reset()
	{
		last_indx = 0;
	}
	int insert(char *c)
	{
		for (int i = 0; i < last_indx; i++)
		{
			if (c[0] == data[i][0] && c[1] == data[i][1])
			{
				return i;
			}
		}
		data[last_indx][0] = c[0];
		data[last_indx][1] = c[1];
		return last_indx++;
	}

	void get(int indx, char *c)
	{
		c[0] = data[indx][0];
		c[1] = data[indx][1];
	}
};

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
		for (int i = 0; i < MAX; i++)A[i] = 0;
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
				//partition(A, rare, font);
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
	int get_indx(int data)
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
			cout << A[i] << " ";
		}
		cout << endl;
	}

	void partition(int arr[], int low, int high){

		int mid;

		if (low<high){
			mid = (low + high) / 2;
			partition(arr, low, mid);
			partition(arr, mid + 1, high);
			mergeSort(arr, low, mid, high);
		}
	}

	void mergeSort(int arr[], int low, int mid, int high){

		int i, m, k, l, temp[MAX];

		l = low;
		i = low;
		m = mid + 1;

		while ((l <= mid) && (m <= high)){

			if (arr[l] <= arr[m]){
				temp[i] = arr[l];
				l++;
			}
			else{
				temp[i] = arr[m];
				m++;
			}
			i++;
		}

		if (l>mid){
			for (k = m; k <= high; k++){
				temp[i] = arr[k];
				i++;
			}
		}
		else{
			for (k = l; k <= mid; k++){
				temp[i] = arr[k];
				i++;
			}
		}

		for (k = low; k <= high; k++){
			arr[k] = temp[k];
		}
	}

	void get_r(int *x, int *y)
	{
		int max_count = -1;
		int label = A[0];
		int count = 1;
		int max_label = 0;
		//cout << font << "fop" << endl;
		for (int i = 1; i < font; i++)
		{
			//cout << label << "l" << endl;
			if (A[i] == label)
			{
				count++;
			}
			else
			{
				
				if (count > max_count)
				{
					max_count = count;
					max_label = label;
				}
				label = A[i];
				count = 1;
			}
		}
		if (count > max_count)
		{
			max_count = count;
			max_label = label;
		}
		//cout << max_label << "  " << max_count << endl;
		*x = max_count;
		*y = max_label;
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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);
	
	while (scanf("%d", &N) == 1)
	{
		init_var();
		for (int i = 0; i < N; i++)
		{
			int m;
			cin >> m;
			for (int j = 0; j < m; j++)
			{
				int y;
				cin >> y;
				grid[i][y] = 1;
			}
		}
		//print_grid();
		int test;
		cin >> test;
		//cout << test << endl;
		for (int t = 0; t < test; t++)
		{
			int source;
			cin >> source;
			//cout << "S" << source << endl;
			que.reset();
			label.reset();
			que.push(source);
			que.pop();
			int l = 0;
			int max_push = -1;
			int no_of_push = 0;
			int max_l;
			while (true)
			{
				no_of_push = 0;
				for (int i = 0; i < N; i++)
				{
					if (grid[source][i] && source != i)
					{
						if (que.push(i))
						{
							label.push(l + 1);
							no_of_push++;
						}

					}
				}
				//cout << no_of_push << "g"<<endl;
				if (max_push < no_of_push)
				{
					max_push = no_of_push;
					max_l = l + 1;
				}
				source = que.pop();
				if (que.rare > que.font)
				{
					break;
				}
				l = label.pop();
			}
			//label.print();
			if (l == 0)
			{
				cout <<l<< endl;
			}
			else
			{
				label.get_r(&max_push, &max_l);
				cout << max_push << " " << max_l << endl;
			}
		}
	}
	return 0;
}