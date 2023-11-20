#include <iostream>
#include <queue>
using namespace std;

int main()
{

    int A,B,N,M;
    cin>>A>>B>>N>>M;

    bool isVisited[100001]={};

    queue<pair<int,int>> q;
    q.push(make_pair(N,0));
    
    while(!q.empty())
    {
        int pos=q.front().first;
        int cnt=q.front().second;

        q.pop();
        if(isVisited[pos]||pos<0||pos>100000) continue;

        if(pos==M)
        {
            cout<<cnt<<'\n';
            break;
        }
        //cout<<pos<<'\n';
        isVisited[pos]=true;
        //+1
        int step = pos+1;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }

        step= pos-1;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }
        step=pos+A;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }
        //+B
        step=pos-A;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }
        step=pos+B;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }
        //+B
        step=pos-B;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }
        
        step=pos*A;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }

        step=pos*B;
        if (step>=0&&step<=100000)
        {
            q.push(make_pair(step,cnt+1));
        }
    }

    return 0;
}