#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int b1=0,b2=0;
    for(int i=0;i<section.size();i++){
        if(section[i]<=b2){
            continue; //이미 칠함.
        }
        if(b1<1&&b2>n){
            continue; //범위를 넘어섰음, 칠할 수 없다.
        }
        
        b1=section[i]-m+1;
        b2=section[i]+m-1;
        b2=b2>n?n:b2;
        answer++;
    }
    return answer;
}