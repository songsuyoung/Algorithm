#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//idx반환 - 괄호 체크 함수 
int checkPare(string p) {
    int idx;
    int checks = 0;

    for (idx = 0; idx < p.length(); idx++) {
        char tmp = p[idx];

        if (tmp == '(')
            checks++;
        else {
            checks--;
        }
        
        if (checks == 0)
            return idx;
    }

    return idx-1; //올바르면 p.length 길이의 idx가 반환된다.
}
/*
문자열 u가 올바른 문자열이라면 p는 v가 되고,
문자열 u가 올바른 문자열이 아니라면,
(를 붙이고 v실행 )를 붙임.
*/
//재귀
bool isVaild(string pares){
    
    stack<char> s;
    
    for(int i=0;i<pares.length();i++){
        if(pares[i]=='(')
            s.push(pares[i]);
        else{
            if(s.empty())
                return false;
            s.pop();
        }
    }
    return s.empty();
}
string reverse(string u){
    
    string reverseString="";
    
    for(int i=0;i<u.length();i++){
        if(u[i]=='(')
            reverseString+=")";
        else
            reverseString+="(";
    }
    
    return reverseString;
}

string cutPare(string w) {

    if(w.length()==0)
        return "";
    int idx = checkPare(w); //균형잡힌 마지막 idx
    
    string u = w.substr(0, idx+1);
    string v = w.substr(idx+1, w.length()); //균형잡히지 않은 Idx-마지막까지

    if(isVaild(u)){//완벽한 균형잡힌 괄호
        return u+cutPare(v);
    }else{
        u.erase(0,1);
        u.erase(u.length()-1,u.length());
        return "("+cutPare(v)+")"+reverse(u);
    }
}

string solution(string p) {
    return cutPare(p);
}