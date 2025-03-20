#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> person = { {1,2,3,4,5}
                                  ,{2,1,2,3,2,4,2,5}
                                  ,{3,3,1,1,2,2,4,4,5,5}}; //반복되어지는 패턴 정의
    vector<int> counting(3,0);
    //종료 조건 : answers 끝날 때까지
    for(int i=0; i<answers.size(); i++)
    {
        int p1 = i%person[0].size();
        int p2 = i%person[1].size();
        int p3 = i%person[2].size();
        
        if(answers[i] == person[0][p1])
        {
            counting[0]++;
        }
        if(answers[i] == person[1][p2])
        {
            counting[1]++;
        }
        if(answers[i] == person[2][p3])
        {
            counting[2]++;
        }
    }
    
    int maxVal = INT_MIN;
    for(int i=0; i<3; i++)
    {
        maxVal=max(maxVal, counting[i]);
    }
    
    for(int i=0; i<3; i++)
    {
        if(maxVal == counting[i])
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}

/*
수포자는 1번 문제를 1,2,3,4,5 순으로 찍음
2번 수포자는 2,1,2,3,2,4,2,5 즉 (2)를 먼저 붙이고 다음 수 1,2,3,4,5
3번 수포자는 3,3,1,1,2,2,4,4,5,5 즉, 3 1 2 4 5 순인데, 두 번씩 찍음

누가 가장 많이 맞췄는가?(복수 허용)
*/
