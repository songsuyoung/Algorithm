#include <iostream>
#include <vector>
#include <string>
using namespace std;


int solution(string s)
{
    //항상 최소는 2
    int answer=1;
    
    for(int i=s.length();i>=2;i--)
    {
        for(int j=0;j<s.length();j++)
        {
            //팰린드롬 수
            int left=j;
            int right=j+(i-1);
            if(right>=s.length()) break;
            bool isSuccess=false;
            while(left<right)
            {
                if(s[left++]!=s[right--])
                {
                    isSuccess=false;
                    break;
                }
                isSuccess=true;
            }
            
            if(isSuccess)
            {
                answer=max(answer,i);
                break;
            }
        }
    }
    

    return answer;
}
