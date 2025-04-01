#include <bits/stdc++.h>
using namespace std;

string solution(string my_string) {
    string answer = "";
    
    unordered_set<char> st;
    
    for(int i=0; i<my_string.size(); i++)
    {
        if(st.find(my_string[i]) == st.end())
        {
            answer+=my_string[i];
            st.insert(my_string[i]);
        }
    }
    return answer;
}