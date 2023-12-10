#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char,int> um;
    
    for(int i=0;i<skill.size();i++)
    {
        um[skill[i]]=i+1;
    }
    
    
    for(string s : skill_trees)
    {
        bool isFail=false;
        int curOrder=1;
        for(int i=0;i<s.length();i++)
        {
            if(um[s[i]]==0) continue;
            if(curOrder<um[s[i]])
            {
                isFail=true;
                break;
            }else
            {
                curOrder++;
            }
        }
        if(isFail == false)
            answer++;
    }
    return answer;
}