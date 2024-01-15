#include <string>
#include <map>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    map<int,map<int,map<int,map<int,bool>>>> isVisited;
    
    int curR=0,curC=0;
    for(int i=0;i<dirs.size();i++)
    {
        int nextR=curR,nextC=curC;   
        switch(dirs[i])
        {
            case 'U':
                nextR+=1;
                break;
            case 'D':
                nextR-=1;
                break;
            case 'L':
                nextC-=1;
                break;
            case 'R':
                nextC+=1;
                break;
        }
        
        if(nextR>5||nextC>5||nextR<-5||nextC<-5) continue;
        if(isVisited[curR][curC][nextR][nextC]==false) answer++;
        
        isVisited[curR][curC][nextR][nextC]=true;
        isVisited[nextR][nextC][curR][curC]=true;
        
        curR=nextR;
        curC=nextC;
    }
    
    return answer;
}
