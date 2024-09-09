#include <bits/stdc++.h>

using namespace std;

/*
두 사람이 선물을 주고 받은 기록
(이번달까지)두 사람 사이에 더 많은 선물을 준 사람이 다음 달에 +1
선물 기록 ㄴㄴ
    선물 지수 : 선물 준 수 - 받은 선물
    두 사람의 선물 지수도 같음 다음달에 선물 노노
*/
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map <string, pair<int,int>> person; //first 준 횟수, second 받은 횟수
    map <string,int> output;
    
    map <string, map<string,int>> sender;  //보내는 사람
    
    for(int i=0;i<gifts.size();i++)
    {
        int idx = gifts[i].find(' ');
        string A = gifts[i].substr(0,idx);
        string B = gifts[i].substr(idx+1,gifts[i].length());
        
        sender[A][B]++; //A가 B에게 준다.
        
        person[A].first ++; //A가 B에게 준 횟수
        person[B].second ++; //B가 A에게 받은 횟수
      
    }
    
    for(int i=0;i<friends.size();i++)
    {
        for(int j=0;j<friends.size();j++)
        {
            if(i==j) continue;
            
            int A = sender[friends[i]][friends[j]]; //i가 j에게 준 값 5번
            int B = sender[friends[j]][friends[i]]; //j가 i에게 준 값 3번 j->i에게 줘야함.
            
            if((A==0&&B==0) || A==B) //못받거나 같을 때 
            {
                int percentage1 = person[friends[i]].first - person[friends[i]].second;
                int percentage2 = person[friends[j]].first - person[friends[j]].second;
                
                if(percentage1<percentage2) //i<j
                {
                     output[friends[j]]++;
                }
                else if(percentage1>percentage2)
                {
                     output[friends[i]]++;
                }
            }
            else if(A<B)
            {
                //i->j 
                output[friends[j]]++;
            }
            else
            {
                output[friends[i]]++;
            }
        }
    }
    
    for(int i=0;i<friends.size();i++)
    {
        answer=max(answer,output[friends[i]]/2);
    }
    return answer;
}