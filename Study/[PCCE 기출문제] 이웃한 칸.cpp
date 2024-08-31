#include <bits/stdc++.h>
using namespace std;

/*
각 칸마다 색이 칠해진 2차원 격자 보드판
위 아래 왼쪽 오른쪽 칸 중 같은 색깔로 칠해진 칸의 개수를 구하려고 함.
board[h][w]와 같은 색으로 이루어진 칸. 
*/

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int rows[4] = {-1,1,0,0};
    int cols[4] = {0,0,-1,1};
    
    for(int i=0;i<4;i++)
    {
        int nr = rows[i] + h;
        int nc = cols[i] + w;
        
        if(nr<0||nc<0||nr>=board.size()||nc>=board[0].size()||board[h][w]!=board[nr][nc]) continue;
        answer++;
    }    
    
    return answer;
}