#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

int bfs(string begin,string target,vector<string> words)
{
    queue<pair<string,int>> q;
    unordered_map<string,bool> isVisited; 
    q.push(make_pair(begin,0));
    
    while(!q.empty())
    {
        string curStr=q.front().first;
        int cnt=q.front().second;
        q.pop();
        
        if(curStr==target) return cnt;
        if(isVisited[curStr]) continue;
        isVisited[curStr]=true;
        
        //cout<<curStr<<' '<<cnt<<'\n';
        for(int i=0;i<words.size();i++)
        {
            int dif=0;
            for(int j=0;j<words[i].length();j++)
            {
                if(curStr[j]!=words[i][j])
                    dif++;
                
                if(dif>=2) break;
            }
            if(dif<=1)
            {
                q.push(make_pair(words[i],cnt+1));
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    
    int answer=bfs(begin,target,words);
    
    return answer;
}