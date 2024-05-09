#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    int answer = 0;
    
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }
    
    while(pq.size()>=2 && pq.top()<K)
    {
        long long first=pq.top();
        pq.pop();
        long long second=pq.top();
        pq.pop();
        
        if(first ==0 && second ==0)
        {
            answer=-1;
            break;
        }
        long long res= first + (second * 2);
        pq.push(res);
        answer++;
    }
    
    if(pq.size()<2&&pq.top()<K)
    {
        answer=-1;
    }
    return answer;
}