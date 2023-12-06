#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int bfs(int N,int K,vector<int> &order)
{
    vector<bool> isVisited(100001,false);
    queue<pair<int,int>> q;

    q.push(make_pair(N,0));
    int cnt=0;
    while(!q.empty())
    {
        int num=q.front().first;
        cnt=q.front().second;
        q.pop();
        if(isVisited[num]) continue;

        if(num==K)
        { 
            break;
        }
        isVisited[num]=true;
        int moveLeft=num-1;
        if(moveLeft>=0&&moveLeft<=100000&&isVisited[moveLeft]==false)
        {
            if(order[moveLeft]==0)
                order[moveLeft]=num;
            q.push(make_pair(moveLeft,cnt+1));
        }
        int moveRight=num+1;
        if(moveRight>=0&&moveRight<=100000&&isVisited[moveRight]==false)
        {

            if(order[moveRight]==0)
                order[moveRight]=num;
            q.push(make_pair(moveRight,cnt+1));
        }
        int move2Jump=num*2;
        if(move2Jump>=0&&move2Jump<=100000&&isVisited[move2Jump]==false)
        {
            if(order[move2Jump]==0)
                order[move2Jump]=num;
            q.push(make_pair(move2Jump,cnt+1));
        }
    }

    return cnt;
}
int main()
{

    vector<int> order(100001,0);
    int N,K;
    cin>>N>>K;

    int cnt=bfs(N,K,order);
    vector<int> buffer;
    cout<<cnt<<'\n';

    int end=K;
    while(N!=end)
    {
        buffer.push_back(end);
        end=order[end];
    }
    buffer.push_back(end);

    for(int i=buffer.size()-1;i>0;i--)
    {
        cout<<buffer[i]<<' ';
    }
    cout<<buffer.front()<<'\n';
}