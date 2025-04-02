#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int i=0;
    for(; i<completion.size(); i++)
    {
        if(participant[i]!=completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    
    if(answer.empty())
    {
        answer = participant[i];
    }
    return answer;
}

/*

participant 참가한 선수 이름
completion 완주한 선수 이름

완주 못한 선수 이름 ret => 동명이인이 있을 수 있다. map으로 <이름, 개수><-participant  기준, completion 포함되어있음 개수 감소
*/