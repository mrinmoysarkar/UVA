#include<cstdio>
#include<iostream>
using namespace std;
int N, M;
class node{
public:
	int x, y;
};
node nod[100];

node output[100];
int start_x;
int start_y;
int end_x;
int end_y;
int used[100];
int done = 0;
int node_ind;
void init()
{
	for (int i = 0; i < 100; i++)
	{
		used[i] = 0;
	}
}

void dfs(int indx,int level)
{
	if (done)return;
	if (level == N)
	{
		/*
		cout << N << endl;
		for (int i = 0; i < N; i++)
		{
			cout << "(" << output[i].x << "," << output[i].y << "),";
		}*/
		if (indx == end_x)
		{
			cout << "YES" << endl;
			done = 1;
		}
		//cout << endl;
		return;
	}
	for (int i = 0; i < node_ind;i++)
	{
		node data = nod[i];
		if(data.x == indx && !used[i])
		{
			used[i] = 1;
			if (i < (node_ind-1) && i>0)
			{
				if (data.x != data.y && nod[i+1].x == data.y && nod[i+1].y == data.x)
				{
					used[i + 1] = 1;
				}
				else if (data.x != data.y && nod[i - 1].x == data.y && nod[i - 1].y == data.x)
				{
					used[i - 1] = 1;
				}
			}
			else if (i==0)
			{
				if (data.x != data.y && nod[i + 1].x == data.y && nod[i + 1].y == data.x)
				{
					used[i + 1] = 1;
				}
			}
			else if (i == (node_ind-1))
			{
				if (data.x != data.y && nod[i - 1].x == data.y && nod[i - 1].y == data.x)
				{
					used[i - 1] = 1;
				}
			}
			output[level] = data;
			dfs(data.y, level + 1);
			used[i] = 0;
			if (i < (node_ind - 1) && i>0)
			{
				if (data.x != data.y && nod[i + 1].x == data.y && nod[i + 1].y == data.x)
				{
					used[i + 1] = 0;
				}
				else if (data.x != data.y && nod[i - 1].x == data.y && nod[i - 1].y == data.x)
				{
					used[i - 1] = 0;
				}
			}
			else if (i == 0)
			{
				if (data.x != data.y && nod[i + 1].x == data.y && nod[i + 1].y == data.x)
				{
					used[i + 1] = 0;
				}
			}
			else if (i == (node_ind - 1))
			{
				if (data.x != data.y && nod[i - 1].x == data.y && nod[i - 1].y == data.x)
				{
					used[i - 1] = 0;
				}
			}

		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	while (scanf("%d", &N) == 1 && N != 0)
	{
		//cout << N << endl;
		init();
		cin >> M;
		cin >> start_x >> start_y >> end_x >> end_y;
		int in = 0;
		for (int i = 0; i < M; i++)
		{
			int x, y;
			cin >> x >> y;
			if (x != y)
			{
				nod[in].x = x;
				nod[in].y = y;
				in++;
				nod[in].x = y;
				nod[in].y = x;
				in++;
			}
			else
			{
				nod[in].x = x;
				nod[in].y = y;
				in++;
			}
		}
		node_ind = in;
		done = 0;
		dfs(start_y, 0);
		if (!done)cout << "NO" << endl;
	}
	return 0;
}