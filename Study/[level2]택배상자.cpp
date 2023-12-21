/*
1,000,000 => O(1)로 끝내야함
영재는 택배상자를 트럭에 싣는 일
택배상자는 크기가 모두 같으며 1번 n번 상자까지 번호가 증가하는 순서대로 컨베이너 벨트에 일렬로 놓여 영재에게 전달.

컨베이너 벨트 순서(1~n번) <-다름-> 택배기사 아저씨가 알려준 순서 
컨베이너 벨트 순서가 아니면 잠시 보관 (Queue/Stack?(가장 마지막에 보관 ㅇㅇ) -> 보조 컨테이너 벨트를 추가로 설치 => 앞뒤 이동 가능 
=> 기사님이 원하는 순서 안되면 stop

예) 5개 1~2~3~4~5 O(N)
택배 기사 4 3 1 2 5 O(N)
4 3 =>2개만 
[1 2] stack
*/
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> s;

    for(int i=1,idx=0;i<=order.size();i++)
    {
        if(order[idx]==i)
        {
            idx++;
            answer++;
        }
        else
        {
            s.push(i);
        }
        
        while(!s.empty()&&order[idx]==s.top())
        {
            idx++;
            s.pop();
            answer++;
        }
    }
    return answer;
}