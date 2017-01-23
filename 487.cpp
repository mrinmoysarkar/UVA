#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char grid[21][21];
char grid_priority[21][21];

string data[20];
string data_s[20];
vector<string> output[1000];
char out[400];
int N;
class cordinate
{
    public:
        int x,y;
};


cordinate c_indxes[400];


void sort_data()
{
    for(int ii=0;ii<(N*N);ii++)
    {
        int x=-1,y=-1;
        char sml = 120;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                //              cout << data_s[i][j] << " ";
                if(data_s[i][j] < sml)
                {
                    sml = data_s[i][j];
                    x=i;
                    y=j;
                }
            }
            //            cout << endl;
        }
        if(x != -1 && y != -1)
        {
            c_indxes[ii].x = x;
            c_indxes[ii].y = y;
            data_s[x][y] = 122;
        }
        //    cout << "x: "<< x << " y: " << y << endl;
    }
}

void print_co()
{
    for(int i=0;i<(N*N);i++)
    {
        cout << "x: "<< c_indxes[i].x << " y: " << c_indxes[i].y << endl;
    }
}

void print_output()
{
    for(int i=3;i<=N*N;i++)
    {
        int s = output[i].size();
        sort(output[i].begin(),output[i].end());
        for(int j=0;j<s;j++)//string str:output[i])
        {
            cout << output[i][j] << endl;
        }
        output[i].clear();
    }
}

void dfs(int x,int y,int len)
{
    if(len > 2)
    {
        out[len] = '\0';
        if(find(output[len].begin(),output[len].end(),out) == output[len].end())
        {
            output[len].push_back(out);
          //  cout << out << endl;
        }
        //cout << out << endl;
//        return;
    }

    bool flag[8]={true,true,true,true,true,true,true,true};
    for(int i=0;i<8;i++)
    {
        int ii,jj,flg = -1;
        char c = 'z'+1;
        if(flag[0] && (x-1)>=0 && c > data[x-1][y] && data[x-1][y] > data[x][y])
        {
            ii = x-1;
            jj = y;
            flg = 0;
            c = data[x-1][y];
        }
        if(flag[1] && (x+1)<N && c > data[x+1][y] && data[x+1][y] > data[x][y])
        {
            ii = x+1;
            jj = y;
            flg = 1;
            c = data[x+1][y];
        }
        if(flag[2] && (y-1)>=0 && c > data[x][y-1] && data[x][y-1] > data[x][y])
        {
            ii = x;
            jj = y-1;
            flg = 2;
            c = data[x][y-1];
        }
        if(flag[3] && (y+1)<N && c > data[x][y+1] &&  data[x][y+1] > data[x][y])
        {
            ii = x;
            jj = y+1;
            flg = 3;
            c = data[x][y+1];
        }
        if(flag[4] && (x-1)>=0 && (y-1)>=0 && c > data[x-1][y-1] && data[x-1][y-1] > data[x][y])
        {
            ii = x-1;
            jj = y-1;
            flg = 4;
            c = data[x-1][y-1];
        }
        if(flag[5] && (x+1)<N && (y-1)>=0 && c > data[x+1][y-1] && data[x+1][y-1] > data[x][y])
        {
            ii = x+1;
            jj = y-1;
            flg = 5;
            c = data[x+1][y-1];
        }
        if(flag[6] && (x-1)>=0 && (y+1)<N &&  c > data[x-1][y+1] && data[x-1][y+1] > data[x][y])
        {
            ii = x-1;
            jj = y+1;
            flg = 6;
            c = data[x-1][y+1];
        }
        if(flag[7] && (x+1)<N && (y+1)<N &&  c > data[x+1][y+1] && data[x+1][y+1] > data[x][y])
        {
            ii = x+1;
            jj = y+1;
            flg = 7;
            c = data[x+1][y+1];
        }
        if(flg != -1)
        {
            flag[flg] = false;
            out[len] = data[ii][jj];
            dfs(ii,jj,len+1);
        }
    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cout<<"This is the main cpp code"<<endl;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> data[i];
            data_s[i] = data[i];
        }
//        cout << N << endl;
        //sort_data();
        //print_co();
        int i = 0;
        /*
        for(i=0;i<N*N;i++)
        {
            out[0] = data[c_indxes[i].x][c_indxes[i].y];
            dfs(c_indxes[i].x,c_indxes[i].y,1);
        }*/
        for(i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                out[0] = data[i][j];
                dfs(i,j,1);
            }
        }
        print_output();
        if(T)
        {
            cout << endl;
        }
    }

    return 0;
}

