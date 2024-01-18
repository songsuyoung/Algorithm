#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool recursive(string vowels,string buf,const string &word,int &cnt)
{
    if(buf==word)
    {
        return true;   
    }
    if(buf.length()>5) return false; 
    bool output=0;
    cnt++;
    for(int i=0;i<vowels.length();i++)
    {
        output=recursive(vowels,buf+vowels[i],word,cnt);
        if(output==true)
            break;   
    }
    
    return output;
}
int solution(string word) {
    int answer = 0;
    string vowels ="AEIOU";
    recursive(vowels,"",word,answer);
    return answer;
}