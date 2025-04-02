#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> participantCnt;
    
    for(int i=0; i<participant.size(); i++)
    {
        participantCnt[participant[i]]++;
    }
    
    for(int j=0; j<completion.size(); j++)
    {
        participantCnt[completion[j]]--;
    }

    for(const auto& cnt : participantCnt)
    {
        if(cnt.second>0)
        {
            answer=cnt.first;
            break;
        }
    }
    
    return answer;
}

/*

participant 참가한 선수 이름
completion 완주한 선수 이름

완주 못한 선수 이름 ret => 동명이인이 있을 수 있다. map으로 <이름, 개수><-participant  기준, completion 포함되어있음 개수 감소
*/