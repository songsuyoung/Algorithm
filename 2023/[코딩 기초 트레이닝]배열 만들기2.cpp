#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    bool isChecking=false;
    for(int i=l;i<=r;i++){
        string num=to_string(i);
        for(int j=0;j<num.length();j++){
            if((num[j]-'0')!=0&&(num[j]-'0')!=5){
                isChecking=true;
                break;
            }
        }
        if(!isChecking)
            answer.push_back(i);
        isChecking=false;
    }
    
    if(answer.empty()){
        answer.push_back(-1);
    }
    return answer;
}
