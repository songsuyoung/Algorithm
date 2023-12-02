#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> um;
    vector<int> v;
    priority_queue<int,vector<int>,less<int>> q;
    for(int i=0;i<tangerine.size();i++)
    {
        if(um[tangerine[i]]==0)
            v.push_back(tangerine[i]);
        um[tangerine[i]]++;
    }
    for(int i=0;i<v.size();i++)
    {
        q.push(um[v[i]]);
    }
    
    while(!q.empty())
    {
        k-=q.top();
        q.pop();
        answer++;
        if(k<=0)
            break;
        
    }
    return answer;
}