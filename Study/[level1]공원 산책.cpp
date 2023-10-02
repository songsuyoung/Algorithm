#include <string>
#include <vector>
#include <iostream>

using namespace std;
pair<int,int> init(vector<string> &park){
    int curR,curC;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[0].length();j++){
            if(park[i][j]=='S'){
                curR=i;
                curC=j;
                break;
            }
        }
    }
    
    return make_pair(curR,curC);
}
vector<int> solution(vector<string> park,vector<string> routes){
    vector<int> answer;
    //동 -> 0,-1 서 -> 0,1
    //남 -> 1,0 북 -> -1,0
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,1,-1};
    
    pair<int,int> curPos=init(park);
    
    for(int k=0,idx=0;k<routes.size();k++){
        int nextR=curPos.first;
        int nextC=curPos.second;
        
        switch(routes[k][0]){
            case 'E':
                idx=2;
                break;
            case 'S':
                idx=1;
                break;
            case 'W':
                idx=3;
                break;
            case 'N':
                idx=0;
                break;
        }
        bool isCheck=false;
        for(int i=0;i<routes[k][2]-'0';i++){
            nextR+=rows[idx];
            nextC+=cols[idx];
            
            if(nextR<0||nextC<0||nextR>=park.size()||nextC>=park[0].length()||park[nextR][nextC]=='X'){
                isCheck=true;
                break;   
            }
        }
        if(!isCheck){
            curPos=make_pair(nextR,nextC);
        }
    }
    
    answer.push_back(curPos.first);
    answer.push_back(curPos.second);
    
    return answer;
}