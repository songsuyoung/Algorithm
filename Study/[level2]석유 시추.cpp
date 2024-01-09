#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void bfs(vector<vector<int>> &land,vector<vector<bool>> &isVisited,vector<int> &amount,pair<int,int> st)
{
    //만나는 col을 다 저장예정
    queue<pair<int,int>> q;
    set<int> amountCol;
    q.push(st);
    int cnt=0;
    
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    while(!q.empty())
    {
        pair<int,int> pos=q.front();
        q.pop();
        if(isVisited[pos.first][pos.second]) continue;
        isVisited[pos.first][pos.second] = true;
        amountCol.insert(pos.second);
        cnt++;
        for(int i=0;i<4;i++)
        {
            int nextR=rows[i]+pos.first;
            int nextC=cols[i]+pos.second;
            
            if(nextR<0||nextC<0||nextR>=land.size()||nextC>=land[0].size()||isVisited[nextR][nextC]||land[nextR][nextC]==0) continue;
            
            q.push(make_pair(nextR,nextC));
        }
    }
    
    for(auto val:amountCol)
    {
        amount[val]+=cnt;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    vector<int> amount(land[0].size(),0);
    vector<vector<bool>> isVisited(land.size(),vector<bool>(land[0].size(),false));
    for(int i=0;i<land[0].size();i++) //열
    {
        for(int j=0;j<land.size();j++) //행
        {
            if(land[j][i]==1&&isVisited[j][i]==false)
            {
                bfs(land,isVisited,amount,make_pair(j,i));
            }
        }
    }
    
    for(int i=0;i<amount.size();i++)
    {
        answer=max(answer,amount[i]);
    }
    return answer;
}