#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int max = *max_element(citations.begin(), citations.end());
    
    for(int h=0; h<=max; h++)
    {
        int cnt=0;
        for(int p=0; p<citations.size(); p++)
        {
            if(h<=citations[p])
            {
                cnt++;
            }
        }
        
        if(cnt<h) continue; //이상이어야하기 때문에 실패
        
        int other = citations.size() - cnt;
        
        if(other>h) continue;
        
        answer = h;
    }
    return answer;
}

/*
H-Index 과학자의 생산성과 영향력을 나타내는 지표

(n/h)>=h && (f-n)/h, h의 최댓값이 h- index

예)
[3,0,6,1,5] (인용 횟수)
n = 5
h = (1,4), (2,3), (3,3,5-3), (4,2), (5,2), (6,1)
h번 이상 인용된 논문이 h편 h==h 같음 즉 (3,3)

(h(반복문), 몇 개 이상?, 전체 - 몇개를 뺌)

1. 0번부터 h를 반복문 돌린다. (citations에서 가장 큰 max값 만큼) => 10'000회
2. 위 반복문 내에서 citations 반복문을 돌린다(이중 포문) => 1'000회
3. 반복문을 돌면서 h>=citations[i] 의 수를 센다. 
    - h번 이상이 아니면 4번을 수행하지 않는다.
4. citations.size() - 3번에서 구한 수를 확인한다.
    - h번 이하일 경우 answer에 h값을 넣는다.

*/