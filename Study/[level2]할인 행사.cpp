#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string,int> m;
    deque<string> d;
    
    for(int i=0;i<10;i++)
    {
        m[discount[i]]++;
        d.push_back(discount[i]);
    }

    
    for(int i=10;i<discount.size();i++)
    {
        bool isFail=false;
        for(int j=0;j<want.size();j++)
        {
            if(m[want[j]]<number[j])
                isFail=true;
        }

        if(isFail==false)
        {
            answer++;
        }
        m[d.front()]--;
        d.pop_front();
        d.push_back(discount[i]);
        m[d.back()]++;
        
    }
    bool isFail=false;
    for(int j=0;j<want.size();j++)
    {
        if(m[want[j]]<number[j])
            isFail=true;
    }

    if(isFail==false)
    {
        answer++;
    }
    
    return answer;
}