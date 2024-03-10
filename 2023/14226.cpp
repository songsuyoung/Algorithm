#include <iostream>
#include <queue>
using namespace std;

int bfs(int end)
{
    int copyCnt=0;
    int curCnt=1;
    
    queue<pair<pair<int,int>,int>> q; //copy,cur,cmdCnt
    q.push(make_pair(make_pair(0,1),0));
    vector<vector<bool>> isVisited(5000,vector<bool>(5000,false));
    //vector<vector<int>> dp(1005,vector<int>(1005,0));

    while(!q.empty())
    {
        pair<int,int> cnt=q.front().first;
        int time = q.front().second;
        q.pop();
        //조건 검사
        if(cnt.second == end) return time;
        //방문 검사
        if(isVisited[cnt.first][cnt.second]) continue;
        //
        isVisited[cnt.first][cnt.second]=true;
        //복사
        q.push(make_pair(make_pair(cnt.second,cnt.second),time+1));
        //붙여넣기
        q.push(make_pair(make_pair(cnt.first,cnt.first+cnt.second),time+1));
        //삭제
        if(cnt.second-1>=0)
            q.push(make_pair(make_pair(cnt.first,cnt.second-1),time+1));
    }
    
    return -1;
}

int main()
{

    int N;
    cin>>N;

    cout<<bfs(N)<<'\n';
    
}