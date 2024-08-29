#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1; //1개 선택했을 때와 전부 선택했을 때 경우의 수

    map<string,int> cnts;
    vector<string> type;
    for(int i=0;i<clothes.size();i++)
    {
        if(cnts[clothes[i][1]] == 0)
        {
            type.push_back(clothes[i][1]);
        }
        cnts[clothes[i][1]]++;
    }
    
    for(int i=0;i<cnts.size();i++)
    {
        answer*= (cnts[type[i]]+1); //+1은 전부 고를 확률
    }
    return answer - 1; //아무것도 안입을 확률
}