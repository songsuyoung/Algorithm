#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> st;
    
    for(int i=0; i<s.size(); i++)
    {
        char ch = s[i];
        
        if(ch=='(')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty())
            {
                answer = false;
                break;
            }
            
            st.pop();
        }
    }
    
    if(st.empty() == false)
    {
        answer = false;
    }
    return answer;
}