#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//char data[11];
//char output[65537];
int M,N;
int MULTI=1;
int done = 0;
string out;
string ref_out;
int check(int indx)
{
    if(!done)return 0;
    if(indx == M)
    {
        if(ref_out.find(out) == -1)done=0;
        return 0;
    }
    for(int i=0;i<N;i++)
    {
        out[indx] = i+'0';
        check(indx+1);
    }
    return 0;
}

void dfs(int len,string s, string output)
{
    //cout <<"opt: "<< output << endl;
    if(done)return;
    if(len == MULTI)
    {
        //data[indx] = '\0';
        ref_out = output;
        ref_out += ref_out.substr(0,M-1);
        //cout << output << endl;
        //if accept dfs(0)
        done = 1;
        check(0);
        if(done)cout << output << endl; 
        return;
    }
    //string temp = output.substr(0,len) + output.substr(0,M-1); 
    s=s.substr(1)+'0';
    //cout << temp << endl; 
    
    for(int i=0;i<N;i++)
    {
        char c = i+'0';
        s[M-1] = c;
        if(output.find(s) == -1)
        {
            output[len] = c;
            dfs(len+1,s,output);
        }
    }
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d %d",&M,&N) == 2)
	{
        string s="";
        string output="";
        MULTI=1;
        for(int i=0;i<M;i++)
        {
            s+='0';
            MULTI *= N;
        }
        for(int i=0;i<MULTI;i++)
        {
            if(i<M)
            {
                output += '0';
            }
            else
            {
                output += 'a';
            }
        }
        //cout << MULTI << endl;
        done = 0;
        out = s;
		dfs(M,s,output);
	}
	return 0;
}

