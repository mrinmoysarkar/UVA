
// UVa 10000 - Longest Paths
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int main() {
	int n;
	int t = 0;
	while ((cin >> n) && n) {
		t++;
		int s;
		cin >> s;
		bool lnk[101][101];
		memset(lnk, false, sizeof(lnk));
		int parents[101];
		memset(parents, 0, sizeof(parents));
		int p, o;
		while (cin >> p >> o && p && o) {
			lnk[p][o] = true;
			parents[o]++;
		}
		int lvl[101];
		memset(lvl, 255, sizeof(lvl));
		queue<int> q;
		q.push(s);
		lvl[s] = 0;
		int sol = s;
		while (!q.empty()) {
			int m = q.front();
			q.pop();
			for (int i = 1; i <= n; i++)
				if (lnk[m][i]) {
					parents[i]--;
					if (lvl[i] < lvl[m] + 1) {
						lvl[i] = lvl[m] + 1;
						q.push(i);
						if (lvl[sol] < lvl[i] || lvl[sol] == lvl[i] && i < sol)
							sol = i;
					}
				}
		}
		printf("Case %d: The longest path from ", t);
		printf("%d has length %d, finishing at %d.\n\n", s, lvl[sol], sol);
	}
	return 0;
}






/*
#include<iostream>
#include<queue>
#include<map>
#include<cstdio>
using namespace std;

int n, s;
int longest;
int destiny;
int visited[101];

vector< vector<int> > L(101);

void bfs(){
	queue< pair<int, int> > Q;
	Q.push(make_pair(s, 0));

	pair<int, int> aux;

	while (!Q.empty()){
		aux = Q.front();
		Q.pop();

		if (aux.second>visited[aux.first]){
			visited[aux.first] = aux.second;

			if (aux.second>longest){
				longest = aux.second;
				destiny = aux.first;
			}
			else if (aux.second == longest && aux.first<destiny) destiny = aux.first;

			for (int i = 0; i<L[aux.first].size(); i++)
				Q.push(make_pair(L[aux.first][i], aux.second + 1));
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int caso = 1, p, q;

	while (1){
		scanf("%d", &n);
		if (n == 0) break;

		scanf("%d", &s);

		for (int i = 1; i <= n; i++) L[i].clear();

		while (1){
			scanf("%d %d", &p, &q);
			if (p == 0 && q == 0) break;

			L[p].push_back(q);
		}

		destiny = s;
		longest = 0;
		memset(visited, -1, sizeof(visited));

		bfs();

		cout << "Case " << caso << ": The longest path from " << s << " has length " << longest << ", finishing at " << destiny << "." << endl << endl;
		caso++;
	}

	return 0;
}
*/
/*
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int N;
int grid[1000][1000];
int ma, ed;
vector<int> edge[1000];

void init()
{
	for (int i = 1; i <= N; i++)
	{
		edge[i].clear();
	}
		//for (int j = 0; j <= N; j++)grid[i][j] = 0;
}

void solve(int in,int ad)
{
	int flag=0;
	//int sz = edge[in].size();
	for (int i : edge[in])
	{
		solve(i,ad+1);
		flag = 1;
	}
	if (!flag)
	{
		if (ma < ad)
		{
			ma = ad;
			ed = in;
		}
		else if (ma == ad && ed > in)
		{
			ed = in;
		}
		//cout << in << endl;
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cas = 0;
	while (1)
	{
		cin >> N;
		if (N == 0)return 0;
		//if (cas != 0)cout << endl;
		cas++;
		init();
		int sp;
		cin >> sp;
		while (1)
		{
			int x, y;
			cin >> x >> y;
			if (x == 0 && y == 0)break;
			//grid[x][y] = 1;
			edge[x].push_back(y);
		}
		//cout << "**" << endl;
		ma = -1;
		solve(sp, 0);
		cout << "Case "<<cas<<": The longest path from "<<sp<<" has length "<<ma<<", finishing at "<<ed<<"." << endl<<endl;
	}
	return 0;
}*/