#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> player;
    
    for(int i=0;i<participant.size();i++){
        player[participant[i]]++; //동명이인도 체크
    }
    
    for(int i=0;i<completion.size();i++){
        player[completion[i]]--;
    }
    
    for(int i=0;i<participant.size();i++){
        if(player[participant[i]]!=0)
            answer=participant[i];
         //동명이인도 체크
    }
    
    return answer;
}