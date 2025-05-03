#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int,int>> order;
    
    for(int i=0; i<priorities.size(); i++)
    {
        order.push_back({priorities[i],i});
    }
    
    int i = 1;
    while(!order.empty())
    {
        
        auto it = max_element(order.begin(), order.end(), [] (pair<int,int> const& lhs, pair<int,int> const& rhs) 
            {
                return lhs.first < rhs.first;
            });
        int end = it-order.begin();
    
        if(order[end].second == location)
        {
            answer = i;
            break;
        }
        
        for(int j=0; j<end; j++)   
        {
            //앞에껄 뺀다
            order.push_back(order[0]);
            order.erase(order.begin());
        }
        
        order.erase(order.begin()); //처리
        i++;
    }
        
    return answer;
}

/*
프로세스를 관리할 경우 특정 프로세스가 몇 번 째로 실행되는지 알아내는 문제

1. 실행 대기 큐 에서 대기중인 프로세스를 하나 꺼낸다.
2. 대기 중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면, 방금 꺼낸 프로세스를 다시 큐에 넣음
-> 우선순위 priority_queue
3. 없다면, 방금 꺼낸 프로세스 실행

예)
A B C D
2 1 3 2

C D A B 

- 우선순위가 클수록, 늦게 들어올 수록 먼저 처리? 
아니면, 
A 꺼내고 우선순위 확인 2
B 꺼내고 우선순위 확인 1
C 꺼내고 우선순위 확인 3
D 꺼내고 우선순위 확인 2

1Queue CBA       2Queue D

C 의 우선순위가 3 2 우선순위가 2니깐... C 실행


priority_queue

ABD

queue ABD

priority_queue

예)

A B C D E F
1 1 9 1 1 1

CFEDBA => C

max_element => idx 전달

그 인덱스 전까지 큐 뒤로 이동.

C D E F A B
9 1 1 1 1 1

C 제거

D E F A B

max_element => 0


*/