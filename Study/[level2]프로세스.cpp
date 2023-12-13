#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int,vector<int>,less<int>> q;
    queue<pair<int,int>> wait;
    for(int i=0;i<priorities.size();i++)
    {
        q.push(priorities[i]);
        wait.push(make_pair(priorities[i],i));
    }
    
    while(!wait.empty())
    {
        if(q.top()==wait.front().first)
        {
            answer++;
            if(wait.front().second==location) break;
            q.pop();
            wait.pop();
        }else
        {
            wait.push(wait.front());
            wait.pop();
        }
    }
    return answer;
}