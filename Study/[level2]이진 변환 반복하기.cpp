#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    
    while(s!="1")
    {
        string buf="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0') answer[1]++;
            else
                buf+=s[i];
        }
        //buf.length()를 2진수로 만드는 값
        
        int num=buf.length();
        string transformBy2="";
        
        while(num>0)
        {
            transformBy2+=((num%2)+'0');
            num/=2;
        }
        
        reverse(transformBy2.begin(),transformBy2.end());
        s=transformBy2; //대체
        
        answer[0]++;
    }
    return answer;
}