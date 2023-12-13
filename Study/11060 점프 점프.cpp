#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<int> jumpCnt,int start)
{
    vector<bool> isVisited(jumpCnt.size(),false);

    queue<pair<int,int>> q;
    q.push(make_pair(start,0));

    while(!q.empty())
    {
        pair<int,int> cur=q.front();

        q.pop();
        if(cur.first>=(jumpCnt.size()-1))
            return cur.second;
        if(isVisited[cur.first]) continue;
        isVisited[cur.first]=true;
        for(int i=1;i<=jumpCnt[cur.first];i++)
        {
            q.push(make_pair(cur.first+i,cur.second+1));
        }
    }

    return -1;
}
int main()
{
    vector<int> v;

    int N;
    cin>>N;

    for(int i=0;i<N;i++)
    {
        int jumpCnt;
        cin>>jumpCnt;

        v.push_back(jumpCnt);
    }

    cout<<bfs(v,0);
}