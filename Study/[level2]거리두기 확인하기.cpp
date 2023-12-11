#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
//한줄 넘김
//예를들어, ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"] 이 배열만 넘김..
bool bfs(vector<string> &places,queue<pair<int,int>> &q, bool isVisited[][6],int boundary){
    
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    
    while(!q.empty()){
        
        pair<int,int> curr=q.front();
        q.pop();
        
        if(isVisited[curr.first][curr.second]){
            continue;
        }
        
        isVisited[curr.first][curr.second]=true;
        //cout<<curr.first<<' '<<curr.second<<'\n';
        for(int i=0;i<4;i++)
        {
            int nextR=curr.first+rows[i];
            int nextC=curr.second+cols[i];
            
            if(nextR<0||nextC<0||nextR>=boundary||nextC>=boundary||places[nextR][nextC]=='X') continue;
            if(places[nextR][nextC]=='P') return false; //상하좌우에 사람이 있으면 안된다.
            
            if(places[nextR][nextC]=='O')
            {
                for(int k=0;k<4;k++)
                {
                    int nextRR=nextR+rows[k];
                    int nextCC=nextC+cols[k];
                    
                    if(nextRR==curr.first&&nextCC==curr.second||nextRR<0||nextCC<0||nextRR>=boundary||nextCC>=boundary) continue;
                    
                    if(places[nextRR][nextCC]=='P'){
                        return false;
                    }
                }
                //빈자리일 때, curr 위치를 제외하고 나머지 위치에 사람이 존재하면 실패
            }
        }
    }
    
    //무사히 queue를 다돌은경우
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0;i<places.size();i++){
        queue<pair<int,int>> q;
        bool isVisited[6][6]={false,};
        
        for(int j=0;j<places[i].size();j++){
            for(int k=0;k<places[i][j].length();k++){
                  
                if(places[i][j][k]=='P'){
                    q.push(make_pair(j,k));//row,col 삽입.
                }   
            }
        }
            
        if(bfs(places[i],q,isVisited,5)){
            answer.push_back(1);
        } //하나라도 false가 있으면 j문 탈출... 
        else{
            answer.push_back(0);     
        }
          
    }
    return answer;
}