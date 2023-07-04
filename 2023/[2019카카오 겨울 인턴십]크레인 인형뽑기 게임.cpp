#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    //moves 순서만큼 for문 동작 
    //idx판단을 위해서 -1씩 뺌
    stack<int> picks;
    for(int i=0;i<moves.size();i++){
        
        int pick=0;
        for(int r=0;r<board[0].size();r++){
            
            int pick=board[r][moves[i]-1];
            if(pick!=0){
                board[r][moves[i]-1]=0;
                if(!picks.empty()&&picks.top()==pick){
                    picks.pop();
                    answer+=2;
                }else{
                    picks.push(pick);
                }
                break;
            }
            
        }
    }
    return answer;
}