#include <bits/stdc++.h>

using namespace std;

//정렬할 인덱스를 넘기기 위해서 전역변수 사용
int idx = 0;

bool compare(const string& eng1,const string& eng2)
{
    if(eng1[idx]==eng2[idx])
    {
        return eng1<eng2; //같을 경우 사전순 정렬
    }
    
    return eng1[idx]<eng2[idx];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    idx = n;
    
    sort(strings.begin(), strings.end(), compare);
    
    answer = strings;
    
    return answer;
}

/*
sun, bed, car 

n=1

u,e,a

*/