#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<string,bool> firstWords;
    
    string preWord=words[0];
    firstWords[words[0]]=true;
    for(int i=1;i<words.size();i++)
    {
        if(firstWords[words[i]]==true||preWord[preWord.length()-1]!=words[i][0])
        {//8/3=>2
            answer.push_back((i%n)+1);
            answer.push_back((i/n)+1);
            break;
        }
        
        if(firstWords[words[i]]==false)
        {
            firstWords[words[i]]=true;
        }
        preWord=words[i];
    }
    
    if(answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}