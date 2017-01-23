#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string data;
string output;
int N;
int evn=5,od=21;
string odd="bcdfghjklmnpqrstvwxyz";
string even="aeiou";
int used1[21];
int used2[5];
double data_SBC;
double avg_SBC;
int total_word;
double prob[]={12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0, 4.97, 3.15, 6.71, 8.68, 2.51, .88, 6.87, 7.98, 4.63, 3.93, .9, .02, .22, .9, .52};
void init()
{
    for(int i=0;i<21;i++)
    {
        if(i<5)used2[i]=0;
        used1[i]=0;
        if(data[0] == odd[i])
        {
            used1[i]++;
        }
    }
}

double SBC()
{
    double sbc = 0;
    for(int i=0;i<N;i++)
    {
        sbc += (i+1)*prob[output[i]-'a'];
    }
    return sbc;
}

void dfs(int indx)
{
    if(indx == N)
    {
        if(output != data)
        {
            //cout << output << endl;
            total_word++;
            avg_SBC += SBC();
        }
        return;
    }
    if((indx+1) & 1)
    {
        for(int i=0;i<od;i++)
        {
            if(used1[i]<2)
            {
                used1[i]++;
                output[indx] = odd[i];
                dfs(indx+1);
                used1[i]--;
            }
        }
    }
    else
    {
        for(int i=0;i<evn;i++)
        {
            if(used2[i]<2)
            {
                used2[i]++;
                output[indx] = even[i];
                dfs(indx+1);
                used2[i]--;
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> data;
        output = data;
        N = data.length();
        init();
        total_word = 0;
        data_SBC = SBC();
        avg_SBC = data_SBC;
        total_word++;
        dfs(1);
        if(data_SBC < (avg_SBC/total_word))
        {
            cout << "below" << endl;
        }
        else
        {
            cout << "above or equal" << endl;
        }
    }
    return 0;
}

