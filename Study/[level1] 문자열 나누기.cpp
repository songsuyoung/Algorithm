/*
문자열 s가 입력

1. 첫 글자 x
2. 이 문자열을 -> 방향으로 읽어감
x(sameCnt)와 x(differentCnt)가 아닌 글자 수 센다.

if(sameCnt == differentCnt)
{
    //지금까지 읽은 문자열을 분리 (stIdx - edIdx) 분리
    substr(stIdx,edIdx-stIdx+1);
    break; 
}

//만약 if(differentCnt == 0) break?

예시

banana
s=b
d=a
if(s==d) break 1개
s=n
d=a
if(s==d) break 2개
s=n
d=a
if(s==d) break 3개

aaabbaccccabba
s(a)= 4
n(b)= 4
aaabbacc 1개
s(c)= 2
n = 2 
ccab 2개
*/
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int sameCnt=1, differentCnt = 0;
    char st = s[0];
    
    int i=1;
    int len=0;
    while(i<s.length())
    {
        if(st!=s[i])
        {
            differentCnt++;
        }
        else
        {
            sameCnt++;
        }
        
        if(sameCnt == differentCnt)
        {
            len +=(sameCnt + differentCnt);
            if(i+1<s.length())
            {
                st = s[i+1];    
            }
            answer++;
            differentCnt=0;
            sameCnt=1;
            i+=2;
        }
        else
        {
            i++;
        }
    }
    
    if(len!=s.length())
    {
        answer++; 
    }
    return answer;
}