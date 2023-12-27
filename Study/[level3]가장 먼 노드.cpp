#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

struct Compare
{
  bool operator()(pair<int,int> &a,pair<int,int> &b)
  {
      return a.second>b.second;
  }
};

int bfs(int n,vector<vector<int>> &nodes)
{
    vector<bool> isVisited(n+1,false);
    vector<int> distance(n+1,0);
    queue<pair<int,int>> q;
    
    q.push(make_pair(1,0));
    int maxDist=0;
    while(!q.empty())
    {
        pair<int,int> cur=q.front();
        
        q.pop();
        
        if(isVisited[cur.first]) continue;
        isVisited[cur.first]=true;
        distance[cur.first]=cur.second;
        maxDist=max(maxDist,distance[cur.first]);
        for(int i=0;i<nodes[cur.first].size();i++)
        {
            q.push(make_pair(nodes[cur.first][i],cur.second+1));   
        }
    }
    int answer=0;
    for(int i=1;i<distance.size();i++)
    {
        if(maxDist==distance[i])
            answer++;
    }
    return answer;
}


int solution(int n, vector<vector<int>> edge) {
   
    
    vector<vector<int>> nodes(n+1);
    
    for(int i=0;i<edge.size();i++)
    {
        nodes[edge[i][0]].push_back(edge[i][1]);
        nodes[edge[i][1]].push_back(edge[i][0]);
    }
    
    //다익스트라 알고리즘
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    
    vector<bool> isVisited(n+1,false);
    vector<int> distance(n+1,INT_MAX);
    distance[1]=0;
    pq.push(make_pair(1,0));
    
    int answer = 0;
    
    while(!pq.empty())
    {
        pair<int,int> pos=pq.top();
        pq.pop();
        
        if(isVisited[pos.first]) continue;

        isVisited[pos.first]=true;
        
        for(int i=0;i<nodes[pos.first].size();i++)
        {
            int next=nodes[pos.first][i];
            int nextDist=distance[pos.first]+1;
            
            if(distance[next]>nextDist)
            {
                distance[next]=nextDist;
                pq.push(make_pair(next,nextDist));
            }
        }
    }
    int maxDist=0;
    for(int i=1;i<distance.size();i++)
    {
        maxDist=max(maxDist,distance[i]);
    }
    for(int i=1;i<distance.size();i++)
    {
        if(maxDist==distance[i]) answer++;
    }
    return answer;
}