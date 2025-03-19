#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    deque<int> dq;
    
    for(int i=0; i<number.size(); i++)
    {
        int num = number[i] - '0';
        
        while(!dq.empty() && k>0 && dq.back() < num)
        {
            dq.pop_back();
            k--;
        }
        dq.push_back(num);
    }
    while(k>0)
    {
        dq.pop_back();
        k--;
    }
    for(int i=0; i<dq.size(); i++)
    {
        answer+=dq[i] + '0';
    }
    return answer;
}