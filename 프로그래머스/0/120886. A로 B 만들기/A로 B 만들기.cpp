#include <bits/stdc++.h>

using namespace std;

int solution(string before, string after) {
    int answer = 1;
    
    //스펠링 25개
    vector<int> counting(26,0);
    for(int i=0; i<before.size(); i++)
    {
        counting[before[i]-'a']++; //카운팅 배열
    }
    
    for(int i=0; i<after.size(); i++)
    {
        counting[after[i]-'a']--;
    }
    
    for(int i=0; i<26;i++)
    {
        if(counting[i] != 0)
        {
            answer=0;
            break;
        }
    }
    return answer;
}

/*
olleh

순서를 바꾸어 after를 만들 수 있냐?
일단 순서를 바꿔서 만족하려면, 스펠링 개수가 같아야한다.

*/