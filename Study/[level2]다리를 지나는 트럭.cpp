#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    queue<int> q;
    deque<int> dq;
    
    for(int i=0;i<truck_weights.size();++i)
    {
        dq.push_back(truck_weights[i]);
    }
    for(int i=0;i<bridge_length-1;++i)
    {
        q.push(0); 
    }
    int total=0;
    while(!dq.empty())
    {
        if(total+dq.front()<=weight)
        {
            q.push(dq.front());
            total+=dq.front();
            dq.pop_front();
        }
        else
        {
            while(q.size()<bridge_length)
            {
                q.push(0);
            }
            
            if(total+dq.front()>=weight)
            {
                answer++;
                total-=q.front();
                q.pop();
            }

        }
    }
    
    while(!q.empty())
    {
        answer++;
        q.pop();
    }
    return answer;
}