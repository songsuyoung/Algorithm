#include <vector>
#include <queue>
using namespace std;

class Position{
    int row;
    int col;
    int cnt;
    
    public:
    Position(int row,int col,int cnt){
        this->row=row;
        this->col=col;
        this->cnt=cnt;
    }
    
    int getCnt(){
        return cnt;
    }
    
    int getRow(){
        return row;
    }
    int getCol(){
        return col;
    }
};
int bfs(vector<vector<int>> &maps,vector<vector<bool>> &isVisited,int row,int col){
    
    int cnt=0;
    queue<Position> q;
    
    q.push(Position(row,col,1));   
    
    int Rows[4]={1,-1,0,0};
    int Cols[4]={0,0,1,-1};
    bool isFinish=false;
    while(!q.empty()){
        Position node=q.front();
        q.pop();
        
        if(isVisited[node.getRow()][node.getCol()])
            continue;
         
        isVisited[node.getRow()][node.getCol()]=true;

        for(int i=0;i<4;i++){
            int nextC=node.getCol()+Cols[i];
            int nextR=node.getRow()+Rows[i];
        
            if(nextC<0||nextR<0||nextC>=maps[0].size()||nextR>=maps.size())
                continue;
        
            if(!isVisited[nextR][nextC]&&maps[nextR][nextC]){
                q.push(Position(nextR,nextC,node.getCnt()+1));
                if(maps.size()-1==nextR&&maps[0].size()-1==nextC){
                    cnt=node.getCnt()+1;
                    isFinish=true;
                    continue;
                }   
            }
        }
    }
    
    if(!isFinish)
        return -1;    
    return cnt;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    vector<vector<bool>> isVisited;
    
    for(int i=0;i<maps.size();i++){
        vector<bool> v;
        for(int j=0;j<maps[0].size();j++){
            v.push_back(false);
        }
        isVisited.push_back(v);
    }
    
    answer=bfs(maps,isVisited,0,0);
    
    return answer;
}