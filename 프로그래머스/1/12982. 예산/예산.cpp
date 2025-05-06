#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    for(int i=0; i<d.size(); i++)
    {
        if(budget - d[i]>=0)
        {
            budget-=d[i];
            answer++;
        }
    }
    return answer;
}

/*
전체 예산이 정해져 있기 때문에, 모든 부서의 물품을 구매해줄 순 없음 그래도 최대로 구매해줄 예정

예를 들어,

1,000원 신청한 부서는 1,000원을 지원해야 하며, 적은 지원 ㄴㄴ
배열 d와 예산 budget 이 매개변수로 주어질 때 최대 몇 개 부서에 물품 지원?

=> 정렬 후, 완탐을 통해서 몇 개 선택할 수 있는지를 확인하는 문제인것 같다.
=> 데이터를 재정리 할 필요 없는 이유 : 어떤 부서인지 알 필요 없고, 최대 몇 팀 지원해줄 수 있는지임.
=> 최대를 알기 위해서는 전부 선택해보는 수밖에 없음
=> 정확히 배열 d만큼 제공해주어야함. 정렬 후 작은 budget을 선택했을 때 최대이지 않을까? => 그리디
그리디 유형과 유사해서 그리디로 해볼 예정
*/