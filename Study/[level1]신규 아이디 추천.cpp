#include <string>
#include <iostream>
#include <cctype>
#include <regex>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp="";
    //1,2 진행 대문자를 소문자로 치환, 소문자, 숫자, -, _, .을 제외한 모든 문자 제거
    for(int i=0;i<new_id.length();i++){
        if(new_id[i]>='A'&&new_id[i]<='Z'){
            tmp+=tolower(new_id[i]);
        }else if(new_id[i]>='a'&&new_id[i]<='z'||new_id[i]=='.'||new_id[i]=='-'||new_id[i]=='_'||(new_id[i]>='0'&&new_id[i]<='9')){
            tmp+=new_id[i];
        }
    }
    //3차 진행 : '..'->'.'으로 변환
    answer=regex_replace(tmp,regex("[.]+"),".");
    //4단계
    if(answer[0]=='.'){
        answer.erase(answer.begin(),answer.begin()+1);
    }
    if(answer[answer.length()-1]=='.'){
        answer.erase(answer.end()-1,answer.end());
    }

    //5단계
    if(answer.length()==0){
        answer="a";
    }
    //6단계
    if(answer.length()>15){
        //idx16번부터 끝까지 제거
        answer.erase(answer.begin()+15,answer.end());
        if(answer[answer.length()-1]=='.')
            answer.erase(answer.end()-1,answer.end());
    }
    
    //7단계
    for(int i=answer.length();i<3;i++){
        answer+=answer[i-1];
    }
    
    cout<<answer.length()<<'\n';

    return answer;
}