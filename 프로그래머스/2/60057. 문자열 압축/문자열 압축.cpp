#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = s.length(); //가질 수 있는 가장 긴 길이
    
    string output="";
    //가장 단축할 수 있는 방법
    //abcdabcd => 8개 일때
    //2abcd => 4개만큼 잘랐을 때 가장 압축할 수 있음. 그래서 절반 만큼 자를 수 있도록 한다.
    for(int i=1; i<=s.length()/2; i++)
    {
        unordered_map<string,int> counting;
        output="";
        string pat = s.substr(0, i); //0에서 2개 자름 
        
        for(int j=i; j<s.length(); j+=i)
        {
            string compare = s.substr(j, i); //j부터 j+i까지가 아니라 j에서 i개 자름을 의미
            
            if(pat == compare)
            {
                counting[pat]++;
            }
            else
            {
                int cnt = counting[pat] + 1; //초기값 안더해짐
                if(cnt > 1)
                {
                     output+=to_string(cnt);    
                }
                counting[pat] = 0; //다시 리셋
                output+=pat;
                pat = compare;
            }
        }
        int cnt = counting[pat] + 1; //초기값 안더해짐
        if(cnt > 1)
        {
              output+=to_string(cnt);    
        }
        output+=pat;
        
        answer = min(answer, (int)output.length());
    }
    return answer;
}

/*
문자열에서 같은 값이 연속해서 나타나는 것을 그 문자의 개수와 반복되는 값으로 표현,,
더 짧은 문자열로 줄여서 표현하는 알고리즘을 공부하고 있다.
예)
가장 가질 수 있는 큰 압축 길이는 len만큼임.. 
abbc => 압축해도 4개면 하지않는게 낫지..
a2bc => 4개

예)
aabbaccc 일 때 => 7개.. 압축 ㄴㄴ..

2a2ba3c => 7개
=> a가 1개를 만들 때 => len길이
=> a에서 2개씩 자를 때 => 2a
=> b에서 2개씩 자를 때 => 2a2b
=> a에서 2개씩 자를 때 => 2a2a
.. counting 배열.. 2개인지 몇 개인지 체크해야함. 압축가능한 수를 찾기 위해
=> 2a2b, c를 
*/