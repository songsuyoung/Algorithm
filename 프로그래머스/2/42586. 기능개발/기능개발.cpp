#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 작업을 계산한다.
    queue<int> work;
    
    for(int i=0; i<progresses.size(); i++)
    {
        int percentage = 100-progresses[i];
        int day = percentage/speeds[i];
        
        if(percentage%speeds[i] != 0)
        {
            //하루 더 필요함
            day+=1;
        }
        
        work.push(day); //하나씩 저장
    }
    
    if(work.empty() == false)
    {
        int threshold = work.front();
        int cnt=0;
        while(!work.empty())
        {
            if(work.front()>threshold)
            {
                answer.push_back(cnt);
                cnt = 1;
                threshold = work.front(); //덮어씀
            }
            else
            {
                cnt++;
            }

            work.pop();
        }
        if(cnt != 0)
        {
             answer.push_back(cnt);
        }
    }    
    return answer;
}

/*
기능 개발 속도가 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발
뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포

 0   1   2 (순서)
93% 30% 55%
1   30   5 => 작업 속도

각 배포마다 몇 개의 기능이 배포되는지 return 

100-93 => 7%  => speed 1 => 7/1 => 7일간 작업
100-30 => 70% => speed 30 => 70/30 => 3일간 작업
100-55 => 45% => speed 5 => 45/5 => 9일간 작업

앞에 있는 기능이 배포될 때 함께 배포되어짐. 즉 인덱스 순서에 영향을 받음 (선입선출)

7 3 9 계산되어져 있다면,

7일차 때 배포가능한 개수 7,3
9일차 때 배포가능한 개수 9
*/