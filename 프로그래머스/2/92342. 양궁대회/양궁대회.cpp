#include <bits/stdc++.h>
using namespace std;

vector<int> answer;
int maxDist = 0;
void recursive(int n, vector<int>& info, vector<int> &update, int idx)
{
    if(n==0 || (info.size()<=idx && n>0))
    {
        update[10] += n;
        
        int cnt = 0;
        int apeach = 0, ryan = 0;
        //점수 계산을 수행
        for(int i=0; i<11; i++)
        {
            if(info[i] == 0 && update[i] == 0) continue; //점수에 영향을 안준다.
            if(info[i]<update[i])
            {
                //update[i] ryan , info[i] apeach
                ryan+=(10-i);
            }
            else
            {
                apeach+=(10-i);
            }
        }
        
        //어피치랑 점수 비교
        if(ryan > apeach)
        {
            int dist = abs(ryan - apeach);
            
            if(dist == maxDist)
            {
                for(int i=10; i>0; i--)
                {
                    if(update[i] > answer[i])
                    {
                        answer = update;       
                    }
                    else if(update[i]<answer[i])
                    {
                        break; //업데이트 안함. 선택에 따라 달라지기 때문에 이와같은 로직이 필요
                    }
                }
            }
            else if(dist > maxDist)
            {
                answer = update;  
                maxDist = dist;
            }
            
        }
        
        if(answer.empty())
        {
            answer.push_back(-1);
        }
        //마무리 취소
        update[10] -= n;
        return;
    }

    
    //선택한다.
    int cnt = info[idx] + 1;
    cnt = n-cnt < 0? n : cnt;
    
    update[idx] = cnt;
    recursive(n-cnt, info, update, idx+1);
    update[idx] = 0;
    
    recursive(n, info, update, idx+1);
}

vector<int> solution(int n, vector<int> info) {
    
    vector<int> update(info.size(),0);

    //모든 경우의 수..
    recursive(n, info, update, 0);

    return answer;
}

/*
어피치가 화살 n발을 다 쏜 후 라이언이 화살 n발을 쏜다.
점수 계산
k(1~10)점을 어피치가 a발 맞혔고, 라이언이 b발 맞혔을 경우 더 많은 화살을 k점에 맞힌 선수가 k점을 가져감.
예) 3점 어피치 4발, 라이언이 2발 => 어피치 +3점
최종 점수 계산, 같을 경우에는 어피치 승

이 문제 결론: 어피치를 가장 큰 점수 차이로 이기기 위해서 n발의 화살을 어떤 과녁 점수에 맞혀야 하는가?

예)
어피치
10 2
9 1
8 1
7 1
7+8

라이언은 5발 쏠 수 있는데... 그 5발을 완탐 진행 => 어피치+1 왜냐하면, 어차피 어피치보다 1발 더 맞추면 점수는 라이언꺼.

예)
10 2+1(어피치+1점 더 놓게) => 10 3
9 2 
8 0
...

10+9

그리고
10 0
9 2
8 2
7 1

9+8 = 17 라이언
어피치 10+7 = 17 

9 2
8 2
6 1

라이언 9+8+6 => 23
어피치 10+7 => 17


n번을 10부터 골라야 함.
기준 점 -> 10인지..

즉,
for(int fix = 10; fix>= 1; fix--)
{
    while(n>=0)
    {
        for(int i = fix; i>= 1; i--)
        {
            //어피치 개수 가져옴
            int cnt = info[i-1] + 1;
            
            n-=cnt;
            
            if(n==0)
            {
                break;
            }
            
            if(n<0)
            {
                //해당 info를 사용할 수 없음. 복구
            }
        }
    }
}

=> 완탐.
//선택한다.
//안한다
*/