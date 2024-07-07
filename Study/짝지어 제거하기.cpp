#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> st;
    
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty()&&st.top()==s[i])
        {
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    
    answer=st.empty()? 1:0;
    return answer;
}