#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int,double> a,pair<int,double> b){
    if(a.second==b.second) //실패율이 같은 스테이지 경우
        return a.first<b.first; //작은 번호부터
    return a.second>b.second; //큰 실패율부터
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> divFail;
    
    int totalFre=0;
    //1이상 N+1이하 
    int *freCount=new int[N+2]{0};
    for(int i=0;i<stages.size();i++){ //5 ( 1 2 3 4 5 6 )
        freCount[stages[i]]++;//빈도수 체크
        totalFre+=stages[i];
    }
    //stages 사이즈가 유저 수이다.
    double div=0.0;
    for(int i=1;i<=N;i++){
        div+=freCount[i-1];
        double tmp=0;
        if(stages.size()-div!=0)
            tmp=(double)freCount[i]/(double)(stages.size()-div);
        divFail.push_back(make_pair(i,tmp));
    }

    sort(divFail.begin(),divFail.end(),compare);
    
    for(int i=0;i<divFail.size();i++){
        answer.push_back(divFail[i].first);
    }
    return answer;
}