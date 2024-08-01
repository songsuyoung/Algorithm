#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    unordered_map<char,bool> skipMatching;
    
    for(int i=0;i<skip.size();i++)
    {
        skipMatching[skip[i]]=true;
    }
    
    for(int i=0;i<s.length();i++)
    {
        int cnt=0,idx = 1;
        
        int num = 0; //숫자
        
        while(cnt<index)
        {
            //숫자화 시켜서 idx를 모드 연산 수행
            num = ( (s[i]-'a') + idx++ ) % 26; //'a'-'z' 26개 단어
            
            if(skipMatching[char('a'+num)])
            {
                continue;
            }
            
            cnt++;
        }
        
        answer+=char('a'+num); //하나씩 덧붙여주면 된다.
    }
    return answer;
}