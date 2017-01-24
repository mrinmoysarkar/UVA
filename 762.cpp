#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;
#define MAX 700

int grid[MAX][MAX];

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
	int A[1000];
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
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	data_structure que(2);
	data_structure label(0);
	int N;
	city cit;
	bool nline = false;
	while (scanf("%d", &N) != EOF)
	{
		if (nline) cout << endl;
		nline = true;
		//cout << N << endl;
		cit.reset();
		init_var();
		char c[3];
		for (int i = 0; i < N; i++)
		{
			cin >> c;
			int x = cit.insert(c);
			cin >> c;
			int y = cit.insert(c);
			grid[x][y] = 1;
			grid[y][x] = 1;
		}

		cin >> c;
		int source = cit.insert(c);
		cin >> c;
		int dest = cit.insert(c);
		//cout << source << " " << dest << endl;
		int s = source;

		que.reset();
		label.reset();
		que.push(source);
		que.pop();
		int w = 1;
		while (w)
		{
			for (int i = 0; i < MAX; i++)
			{
				if (grid[source][i] && source != i)
				{
					if (que.push(i))
					{

						label.push(source);
					}
					if (i == dest)
					{
						w = 0;
						break;
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
			}
		}

		if (w)
		{
			cout << "No route" << endl;
		}
		else
		{
			//cout << "*********" << endl;
			//que.print();
			//label.print();
			int indx = que.font - 2;
			int data = label.data_at(indx);
			int output[MAX];
			output[0] = data;
			int k = 1;
			//cout << "data " << data << " in " << indx << endl;
			while (data != s)
			{
				indx = que.get_indx(data) - 1;
				data = label.data_at(indx);
				output[k] = data;
				k++;
				//cout << "data " << data << " in " << indx << endl;
			}
			char chc[3],cho[3];
			chc[2] = '\0';
			cho[2] = '\0';
			cit.get(output[k-1], cho);
			for (int in = k - 2; in >= 0; in--)
			{
				cit.get(output[in], chc);
				cout << cho << " ";
				cout << chc << endl;
				cho[0] = chc[0];
				cho[1] = chc[1];
			}
			cit.get(dest, chc);
			cout << cho << " ";
			cout << chc << endl;
		}
		
	}

	return 0;
}