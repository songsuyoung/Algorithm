#include <string>
#include <vector>

using namespace std;

int isDangerous(vector<vector<int>> &board,bool isVisited[][105],pair<int,int> node){
    int size=board.size();
    int cnt=0;
    //위 아래 좌 우 대각선  1,0 -1,0 0,1 0,-1 
    int rows[9]={-1,-1,-1,0,0,0,1,1,1};
    int cols[9]={-1,0,1,-1,0,1,-1,0,1};
    
    for(int i=0;i<10;i++){
        int nextR=node.first+rows[i];
        int nextC=node.second+cols[i];
        if(nextR<0||nextC<0||isVisited[nextR][nextC]||nextR>=size||nextC>=size)
            continue;
        isVisited[nextR][nextC]=true;
        cnt++;
    }
    
    return cnt;
}
int solution(vector<vector<int>> board) {
 
    bool isVisited[105][105]={false,};
    int cnt=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==1){
                cnt+=isDangerous(board,isVisited,make_pair(i,j));
            }
        }
    }
    return board.size()*board.size()-cnt;
}