#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    //회전시킬 때 올바른 괄호 문자열의 개수
    for(int i=0; i<s.length(); i++)
    {
        string sub = s.substr(i, s.length()) + s.substr(0,i);
        
        stack<char> st;
        bool bIsFail=false;
        for(int j=0; j<sub.size(); j++)
        {
            char ch = sub[j];
            
            if(ch == '('||ch=='{'||ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty())
                {
                    //실패
                    bIsFail = true;
                    break;
                }
                
                if((ch==')' && st.top()=='(') ||(ch==']' && st.top()=='[')||(ch=='}' && st.top()=='{'))
                {
                    st.pop();
                }
            }
        }
        
        if(bIsFail == false && st.empty())
        {
            answer++;
        }
    }
    
    return answer;
}