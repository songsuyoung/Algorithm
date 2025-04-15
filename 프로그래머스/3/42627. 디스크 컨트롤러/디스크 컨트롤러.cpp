#include <bits/stdc++.h>

using namespace std;

struct Compare
{
  bool operator()(vector<int>& job1, vector<int>& job2)
  {
      return job1[1] > job2[1];
  }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end()); //요청 순서대로 정렬
    
    priority_queue<vector<int>,vector<vector<int>>, Compare> pq;
    
    int time = 0; //1+9 => 10초 때 끝남. 10-1 => 9ms 진행
    int task = 0;
    vector<int> buf;
    
    while(task < jobs.size() || !pq.empty())
    {
        if(task < jobs.size() && time>=jobs[task][0])
        {
            pq.push(jobs[task++]);
            continue;
        }
        
        //time < jobs[task][0]
        
        if(!pq.empty())
        {
            //비어있지 않으면 계산을 수행한다.
            vector<int> cur = pq.top();
            time+=cur[1]; //진행시간 더해짐
            buf.push_back(time-cur[0]); //실제로 요청부터 종료까지의 시간 17-1 => 16ms
            pq.pop();
        }
        else
        {
            //비어있다면 그냥 삽입
            pq.push(jobs[task]);
            time = jobs[task][0];
            task++;
        }
    }
    
    for(int i=0; i<buf.size(); i++)
    {
        answer+=buf[i];
    }
    
    return answer/buf.size();
}