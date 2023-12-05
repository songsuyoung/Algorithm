#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    deque<char> buf;
    
    // 0 1 2 3 4 5
    // [ ] ( ) { } 0번 이동 front=substr(0,s.length());
    // ] ( ) { } [ 1번 이동 front=substr(1,s.length())+substr(0,1);
    for(int i=0;i<s.length();i++)
    {
        buf.clear();
        string tmp=s.substr(i,s.length())+s.substr(0,i);
        bool isCheck=true;
        //s를 왼쪽으로 이동
        for(int j=0;j<tmp.length();j++)
        {
            if(tmp[j]=='('||tmp[j]=='{'||tmp[j]=='[') buf.push_back(tmp[j]);
            else
            {
                if(buf.empty()){
                    isCheck=false;
                    break;
                } //실패
                
                if((buf.back()=='('&&tmp[j]==')')||(buf.back()=='['&&tmp[j]==']')||(buf.back()=='{'&&tmp[j]=='}'))
                {
                    buf.pop_back();
                }
            }
        }
        if(isCheck&&buf.empty())
        {
            answer++;
        }
    }
    return answer;
}