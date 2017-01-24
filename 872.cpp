#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

#define SIZE1 26
#define SIZE2 1201

char line[SIZE2];
int possible;
//string line;
int variable[SIZE1], used[SIZE1], path[SIZE1][SIZE1];
int N;
char output[SIZE1];
char output2[SIZE1];
int isFirst;

void initCase()
{
	int i, j;
	for (i = 0; i<SIZE1; i++)
		variable[i] = 0;
	for (i = 0; i<SIZE1; i++) for (j = 0; j<SIZE1; j++)
		path[i][j] = 0;
	for (i = 0; i<SIZE1; i++)
		used[i] = 0;
}

void readCase()
{
	int i, j, index1, index2;
	for (i = 0; line[i]; i++) if (line[i] >= 'A' && line[i] <= 'Z') {
		index1 = line[i] - 'A';
		variable[index1] = 1;
	}
	gets(line);
	//cout << line;
	for (i = 0; line[i]; i++) if (line[i] == '<')line[i] = ' ';
	//cout << line;
	for (i = 0; line[i]; i++) {
		while (line[i] == ' ')
			i++;
		index1 = line[i] - 'A';
		i++;
		while (line[i] == ' ')
			i++;
		index2 = line[i] - 'A';
		path[index1][index2] = 1;
	}
}

void printPath()
{
	int i, j;
	for (i = 0; i<SIZE1; i++) if (variable[i]) {
		for (j = 0; j<SIZE1; j++) if (variable[j])
			printf("%d ", path[i][j]);
		printf("\n");
	}
	printf("\n");
}

void countVariable()
{
	int i;
	N = 0;
	for (i = 0; i<SIZE1; i++) if (variable[i])
		N++;
}

void solve(int index)
{
	int i, j;
	if (index == N) {
		output[index] = '\0';
		int k = 0;
		for (int j = 0; j < index; j++)
		{
			output2[k] = output[j];
			output2[++k] = ' ';
			k++;
		}
		output2[--k] = '\0';
		printf("%s\n", output2);
		possible = 1;
		return ;
	}
	for (i = 0; i<SIZE1; i++) if (variable[i] && used[i] == 0) {
		for (j = 0; j<SIZE1; j++) if (path[i][j] && used[j])
			return ;
		used[i] = 1;
		output[index] = i + 'A';
		solve(index + 1);
		used[i] = 0;
	}
}

void solveCase()
{
	int i;
	if (isFirst)
		isFirst = 0;
	else
		printf("\n");
	countVariable();
	solve(0);
}

int main()
{
	freopen("Text.txt", "r", stdin);
	isFirst = 1;
	int M;
	cin >> M;
	gets(line);
	for (int i = 0; i < M;i++)
	{ 	
		gets(line);
		gets(line);
		//while(gets(line))
		//printf("%s\n", line);
		//cout << line << endl;
		initCase();
		readCase();
		possible = 0;
		solveCase();
		if (!possible) printf("NO\n");
	}
	return 0;
}
