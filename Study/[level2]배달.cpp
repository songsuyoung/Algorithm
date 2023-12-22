#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Compare
{
  bool operator()(pair<int,int> &a,pair<int,int> &b)
  {
      return a.second>b.second;
  }
};
//1번마을에서 시작, K개 초과 -> Stop, K개 이내이면 수를 체크
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<bool> isVisited(N+1,false);
    vector<int> distance(N+1,INT_MAX);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> q;

    q.push(make_pair(1,0));
    distance[1]=0;
    while(!q.empty())
    {
        pair<int,int> cur=q.top();
        q.pop();
        
        if(cur.second>K) break;
        if(isVisited[cur.first]) continue;
        answer++;
        isVisited[cur.first]=true;
        for(int i=0;i<road.size();i++)
        {
            if(road[i][0]==cur.first)
            {
                int next=road[i][1];
                int nextDis=cur.second+road[i][2];
                
                if(nextDis<distance[next])
                {
                    distance[next]=nextDis;
                    q.push(make_pair(next,nextDis));
                }
            }
            if(road[i][1]==cur.first)
            {
                int next=road[i][0];
                int nextDis=cur.second+road[i][2];
                
                if(nextDis<distance[next])
                {
                    distance[next]=nextDis;
                    q.push(make_pair(next,nextDis));
                }
            }
            
        }
    }
    return answer;
}