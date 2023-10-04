#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    map<int,bool> notUse;
    int answer=n-lost.size();
    //1. 전체 학생 수는 2~30 
    //2. 도난 당한놈은 1~n명 중복 없음
    //3. 여벌 옷 가져온 놈은 1~n명 중복 없음
    //4. 여벌 옷이 있는 놈만 빌려줄 수 있음
    //5. 여벌 옷을 가져온 놈이 체육복 도난 당했을 수도 있음. 이럴 경우에 못빌려줌 
    //여벌 옷을 가져온 애를 확인한다.
    for(int i=0;i<reserve.size();i++){
        notUse[reserve[i]]=1;
    }
    vector<int> newLost;
    for(int i=0;i<lost.size();i++){
        if(notUse[lost[i]]==0){
            newLost.push_back(lost[i]);
        }else{
            notUse[lost[i]]=0;
            answer++;
        }
    }
    sort(newLost.begin(),newLost.end());
    for(int i=0;i<newLost.size();i++){
        if(notUse[newLost[i]-1]){
            notUse[newLost[i]-1]=0;
            answer++;
        }else if(notUse[newLost[i]+1]){
            notUse[newLost[i]+1]=0;
            answer++;
        }
    }
    return answer;
}