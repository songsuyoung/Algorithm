#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    //4 , 3 , 3 =>multi_set? 
    priority_queue<int> work;
    
    for(int i=0;i<works.size();i++)
    {
        work.push(works[i]);
    }
    
    while(n!=0)
    {
        int top=work.top();
        if(work.empty()) break;
        work.pop();
        if(top!=0)
            work.push(top-1);
        n--;
    }
    
    while(!work.empty())
    {
        answer+=work.top()*work.top();
        work.pop();
    }
    return answer;
}