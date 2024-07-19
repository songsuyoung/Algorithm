#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct Compare
{
  bool operator()(pair<int,int> &a,pair<int,int> &b)
  {
      return a.second>b.second;
  }
};
bool compare(vector<int> &a,vector<int> &b)
{ 
    return a[0]<b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(),jobs.end(),compare);
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    
    for(int i=0;i<jobs.size();i++)
    {
        if(jobs[0][0] != jobs[i][0])
        {
            break;
        }
        pq.push(make_pair(jobs[i][0],jobs[i][1]));
    }
    
    int idx=pq.size();
    int sec=jobs[0][0];
    while(!pq.empty())
    {
        sec+=pq.top().second; //+3
        answer += (sec - pq.top().first);
        cout<<sec<<' '<<pq.top().first<<' '<<answer<<'\n';
        pq.pop();
        
        if(idx>=jobs.size()) continue;
        if(pq.empty() && sec<jobs[idx][0]) //비어있지 않을 때에는 안에 있는 걸 전부 사용하고, 비어있다면 새로운 잡을 가지고 온다.
        {
            sec = jobs[idx][0];  //업데이트
        }
        
        while(idx<jobs.size() && sec>=jobs[idx][0]) //+6, +9
        {
            pq.push(make_pair(jobs[idx][0],jobs[idx][1]));
            idx++;
        }
    
    }
    
    return answer/jobs.size();
}