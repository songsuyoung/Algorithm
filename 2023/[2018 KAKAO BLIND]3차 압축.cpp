#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> dic;
    
    for(int i=0;i<26;i++){
        string tmp(1,'A'+i); //char를 문자열로 변경할때.. word 1글자를 tmp로 바꾼다..의미
        dic[tmp]=i+1;
        
    } //초기 사전 준비
    
    for(int i=0;i<msg.length();){
        string word(1,msg[i]);
        string findWord="";
        
        for(int j=i+1;dic.find(word)!=dic.end();j++){ //findWord를 못찾으면 멈춘다.
            findWord=word;
            word+=msg[j];
            i=j; //i는 생성된 문자의 다음 글자를 의미하기 때문에 i=j..
        }
        answer.push_back(dic[findWord]);
        if(dic.find(word)==dic.end()) //없으면 생성 있으면 색인번호 출력
            dic[word]=dic.size()+1;
    }
    return answer;
}