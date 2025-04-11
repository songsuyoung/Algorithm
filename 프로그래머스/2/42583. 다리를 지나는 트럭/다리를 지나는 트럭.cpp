#include <bits/stdc++.h>
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

/*
bridge => 일차선 다리를 정해진 순으로 건너려고 함 (queue)
모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야함 

다리에는 트럭이 최대 bridge_length대 올라 갈 수 있으며, 다리는 weight 이하까지 무게 견딤.

예) 트럭 2대 => 2초 길이, 10kg

7 4 5 6

0 대기
1 0번 인덱스 건너는 중
2 0번 인덱스 건너는 중
3 0번 인덱스 끝, 1번 인덱스 건너는 중
4 1번 인덱스 건너는 중, 2번 인덱스 건너는 중
5 1번 인덱스 끝, 2번 인덱스 건너는 중
6 2번 인덱스 끝, 3번 인덱스 건너는 중

=> queue에 대한 while문이 내부에 있고, 건널 수 있는 모든 초를 세는 방법

*/