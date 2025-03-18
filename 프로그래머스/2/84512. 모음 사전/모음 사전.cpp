#include <bits/stdc++.h>
using namespace std;

char eng[5] = {'A','E','I','O','U'};
int answer = 0;

void recursive(string str,const string &word,int &cnt)
{
    if(str == word)
    {
        cout<<cnt<<'\n';
        answer = cnt;
        return;
    }
    if(str.length()>5) return;
    
    cnt++;
    
    for(int i=0; i<5; i++)
    {
        recursive(str+eng[i],word,cnt);
    }
}
int solution(string word) {
    int cnt=0;
    recursive("", word, cnt);    
    return answer;
}

/*
A E I O U만을 사용하여 만들 수 있는 길이 5이하의 모든 단어

첫 번째 단어 A
그 다음 단어 AA
마지막 단어는 UUUUU

=> 순서를 고려하면 되는건가?
=> 5개 밖에 없기 때문에 미리

A AA AAA AAAA AAAAA
    => 교집합을 진행해야함.. 마지막 AAAAA를 제외하고
    => 뒤에서 부터 AAAAE AAAEE AAEEE AEEEEE
E EE EEE EEEE EEEEE
I II III IIII IIIII
O
U

=> 전부 push_back 한 뒤에 찾은 word값의 index 위치 return?
*/