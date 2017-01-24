#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;
#define MAX 200
int grid[MAX][MAX];
string data[MAX];

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


int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	data_structure que(2);
	data_structure label(0);
	int N;
	cin >> N;
	int toppp = 0;
	for (int ds = 0; ds < N; ds++)
	{
		if (toppp) cout << endl;
		toppp = 1;
		init_var();
		int indx = 0;
		while (true)
		{
			string s;
			cin >> s;
			if (s == "*")break;
			else{
				data[indx] = s;
				indx++;
			}
		}
		for (int i = 0; i < indx; i++)
		{
			for (int j = 0; j < indx; j++)
			{
				if (i != j)
				{
					string s1 = data[i];
					string s2 = data[j];
					if (s1.length() == s2.length())
					{
						int l = s1.length();
						int o_mil = 0;
						for (int k = 0; k < l; k++)
						{
							if (s1[k] != s2[k])
							{
								o_mil++;
								if (o_mil > 1)
								{
									break;
								}
							}
						}
						if (o_mil == 1)
						{
							grid[i][j] = 1;
							grid[j][i] = 1;
						}
					}
				}
			}
		}

		string s1, s2, s3;
		getline(cin, s3);
		while (getline(cin, s3) && !s3.empty())
		{
			//cin >> s3;
			//getline(cin, s3);
			//gets(s3);
			//cout << "hello"<<s3 << endl;
			//if (s3.empty())break;
			//cout << s3 << endl;
			istringstream iss(s3);
			iss >> s1>>s2;
			//cout << s1 << " " << s2 << endl;
			///*
			int source = -1, dest = -1;
			for (int i = 0; i < indx; i++)
			{
				if (s1 == data[i])
				{
					source = i;
				}
				if (s2 == data[i])
				{
					dest = i;
				}
				if (source != -1 && dest != -1)break;
			}
			if (source != -1 && dest != -1 && source == dest){
				cout << s1 << " " << s2 << " " << 0 << endl;
			}
			else if (source != -1 && dest != -1)
			{
				que.reset();
				label.reset();
				que.push(source);
				que.pop();
				int l = 0;
				int w = 1;
				while (w)
				{
					for (int i = 0; i < indx; i++)
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
					cout << s1 << " " << s2 << " " << (l + 1) << endl;
				}
				else
				{
					//cout << "NO SHIPMENT POSSIBLE" << endl;
				}
			}
			//*/
		}
	}


	return 0;
}