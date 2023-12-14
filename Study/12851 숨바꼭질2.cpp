#include <iostream>
#include <queue>
#include <vector>
using namespace std;

pair<int,int> bfs(int N,int K)
{
    vector<bool> isVisited(100001,false);

    queue<pair<long long,long long>> q;

    q.push(make_pair(N,0));
    pair<int,int> res=make_pair(0,0);
    while(!q.empty())
    {
        long long pos=q.front().first; //2
        long long cnt=q.front().second;
        

        isVisited[pos]=true;
        q.pop();

        if(res.first!=0&&pos==K&&res.first==cnt) res.second++;
        if(res.first==0&&pos==K)
        {
            res.second++;
            res.first=cnt;
        }
        if(pos<0||pos>100000) continue;

        if(pos+1<=100000&&!isVisited[pos+1])
            q.push(make_pair(pos+1,cnt+1)); //1 -> 2 -> 31 
        if(pos-1>=0&&!isVisited[pos-1])
            q.push(make_pair(pos-1,cnt+1)); //1
        if(pos*2<=100000&&!isVisited[pos*2])
            q.push(make_pair(pos*2,cnt+1)); //1   
    }
    
    return res;
}
int main()
{
    int N,K;
    cin>>N>>K;

    pair<int,int> res=bfs(N,K);

    cout<<res.first<<'\n'<<res.second<<'\n';
}