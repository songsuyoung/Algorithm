#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> parth;
    bool answer=true;
    for(int i=0;i<s.length();i++){
        char tmp=s[i];
        
        if(tmp=='('){
            parth.push(tmp);   
        }else{
            if(parth.empty()){
                answer=false;
                break;
            }
            char tmp2=parth.top();
            parth.pop();
        }
    }
    if(!parth.empty()){
        answer=false;
        while (!parth.empty()) {
		    parth.pop();
	    }
    }
    return answer;
}