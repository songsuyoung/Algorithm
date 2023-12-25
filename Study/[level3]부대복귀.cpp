#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n,vector<vector<int>> &roads,int destination, vector<int> &distance)
{
    
    queue<pair<int,int>> q;
    vector<bool> isVisited(n+1,false);
    q.push(make_pair(destination,0));
    
    while(!q.empty())
    {
        pair<int,int> cur=q.front();
        q.pop();
        
        if(isVisited[cur.first]) continue;
        
        isVisited[cur.first]=true;
        distance[cur.first]=cur.second;
        
        for(int i=0;i<roads[cur.first].size();i++)
        {
            q.push(make_pair(roads[cur.first][i],cur.second+1));          
        }
    }
    
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> v(n+1);
    vector<int> distance(n+1,-1);
    //정제 과정이 필요함.. 
    //처음에 다익스트라 알고리즘을 생각했으나, 거리가 모두 1 이기때문에 bfs사용 가능
    for(int i=0;i<roads.size();i++)
    {
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    
    bfs(n,v,destination,distance);
    
    for(int i=0;i<sources.size();i++)
    {
        answer.push_back(distance[sources[i]]);
    }
    
    return answer;
}