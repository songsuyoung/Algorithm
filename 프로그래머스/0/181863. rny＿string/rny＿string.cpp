#include <bits/stdc++.h>
using namespace std;

string solution(string rny_string) {
    string answer = "";
    
    int pos = 0;
    
    while((pos = rny_string.find('m'))!=string::npos)
    {
        string sub = rny_string.substr(0, pos);
        rny_string.erase(0, sub.size() + 1);
        answer+=sub;
        answer+="rn";
    }
    
    if(rny_string.empty() == false)
    {
        answer+=rny_string;
    }
    
    return answer;
}