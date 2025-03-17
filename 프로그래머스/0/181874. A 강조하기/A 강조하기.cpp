#include <bits/stdc++.h>
using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(int i=0; i<myString.size(); i++)
    {
        myString[i] = tolower(myString[i]);
        
        if(myString[i] == 'a')
        {
            answer += toupper(myString[i]);
        }
        else
        {
            answer += tolower(myString[i]);
        }
    }
    return answer;
}