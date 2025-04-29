#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for(int i=0; i<scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.size() > 1 && pq.top() < K)
    {
        int first = 0, second = 0;
        if(!pq.empty())
        {
            first = pq.top();
            pq.pop();
        }
        
        if(!pq.empty())
        {
            second = pq.top();
            pq.pop();
        }
        
        long long tmp = (first + (second * 2));
        
        pq.push(tmp);
        answer++;
    }
    
    if(K>pq.top())
    {
        answer = -1;
    }
    
    return answer;
}