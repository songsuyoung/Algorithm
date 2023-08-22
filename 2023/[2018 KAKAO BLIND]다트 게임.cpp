#include <string>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> result;
    for(int i=0;i<dartResult.length();i++){
        
        switch(dartResult[i]){
            case 'S':
                break;
            case 'D':
                result[result.size()-1]=pow(result.back(),2);
                break;
            case 'T':
                result[result.size()-1]=pow(result.back(),3);
                break;
            case '*':
                if(result.size()!=1){ //2배씩 증가
                    result[result.size()-2]*=2;
                }
                result[result.size()-1]*=2; 
                break;
            case '#':
                result[result.size()-1]=-result[result.size()-1];
                break;
            default:
                if(dartResult[i+1]=='0'){
                    result.push_back(10);
                    i+=1;
                }else
                    result.push_back(dartResult[i]-'0'); //숫자로 변경
        }
    }
    
    for(int i=0;i<result.size();i++)
        answer+=result[i];
    
    
    return answer;
}