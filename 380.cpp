#include<iostream>
#include<cstdio>

using namespace std;
#define MAX 10000

class num{
public:
int start_time,end_time,dest;
};

int main()
{
    freopen("input.txt","r",stdin);
    num table[MAX];
    int N;
    cin >> N;
    for(int ii=0;ii<N;ii++)
    {
        while(true)
        {
            int number;
            cin >> number;
            if(number == 0)break;
            int st,et,dest;
            cin >> st >> et >> dest;
            table[number].start_time = st;
            table[number].end_time = st+et;
            table[number].dest = dest;
        }
        while(true)
        {
            int time,source;
            cin >> time;
            if(time == 9000) break;
            cin >> source;
            int s = source;
            while(true)
            {
                if(time >= table[source].start_time && time >= table[source].end_time)
                {
                    source = table[source].dest;
                    if(s == source)
                    {
                        cout <<"AT "<< time << " CALL TO " << s << " RINGS 9999" << endl;
                    }
                }
                else
                {
                    cout <<"AT "<< time << " CALL TO " << s << " RINGS " << source << endl;
                    break;
                }

            }
        }

    }

    return 0;
}
