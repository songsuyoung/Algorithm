#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    if(number.size()==k) return answer;
    deque<char> d;
    int cnt=0;
    for(int i=0;i<number.size();i++)
    {
            //삭제
        while(!d.empty()&&cnt<k&&d.back()<number[i])
        {
            d.pop_back(); //뒤에 있는 수가 number[i]보다 작으면 팝한다.
            cnt++;
        }
        d.push_back(number[i]);
    }
    
    while(!d.empty())
    {
        if(d.size()==(k-cnt)) break;
        answer+=d.front();
        d.pop_front();
    }
    
    return answer;
}