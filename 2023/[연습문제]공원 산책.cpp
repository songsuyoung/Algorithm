#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isGoing(vector<string> &park,int N,int M,int *DirX,int *DirY,int dir,int cnt,int curX,int curY){

    for(int i=0;i<cnt;i++){
        curX+=DirX[dir];
        curY+=DirY[dir];
        
        if(curX<0||curY<0||curX>=M||curY>=N)
            return false;
        if(park[curY][curX]=='X')
            return false;
    }
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int DirX[4]={0,0,-1,1};
    int DirY[4]={-1,1,0,0};

    int curX=0,curY=0;
    
    int N=park.size();
    int M=park[0].length();
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            if(park[i][j]=='S'){
                curX=j;
                curY=i;
                break;
            }
    }

    for(int i=0;i<routes.size();i++){
        char dir=routes[i][0];
        int numsDir=0;
        switch(dir){
            case 'N':
                numsDir=0;
                break;
            case 'S':
                numsDir=1;
                break;
            case 'W':
                numsDir=2;
                break;
            case 'E':
                numsDir=3;
                break;
        }
        int cnt=routes[i][2]-'0';
     
        if(isGoing(park,N,M,DirX,DirY,numsDir,cnt,curX,curY)){
            curX+=(DirX[numsDir]*cnt);
            curY+=(DirY[numsDir]*cnt);
        }
    }
    
    answer.push_back(curY);
    answer.push_back(curX);
    return answer;
}