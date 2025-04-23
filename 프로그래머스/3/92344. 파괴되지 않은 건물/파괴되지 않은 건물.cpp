#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    vector<vector<int>> p_sum(1005, vector<int>(1005,0));
    
    for(int i=0; i<skill.size(); i++)
    {
        int x1 = skill[i][1];
        int y1 = skill[i][2];
        int x2 = skill[i][3];
        int y2 = skill[i][4];
        
        //공격과 회복
        int sum = skill[i][0] == 1? skill[i][5] * -1 : skill[i][5];
        
        //이전 것까지 고려해야하기 때문에 더해줌.
        p_sum[x1][y1] += sum;
        p_sum[x2+1][y1] += -1 * sum;
        p_sum[x1][y2+1] += -1 * sum;
        p_sum[x2+1][y2+1] += sum;
    }
 
    //좌-우 누적
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            p_sum[i][j+1] += p_sum[i][j]; //더함
        }
    }
    
    //상-하 누적
     for(int i=0; i<board[0].size(); i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            p_sum[j+1][i] += p_sum[j][i]; //더함
        }
    }
    
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            if(board[i][j] + p_sum[i][j] > 0)
            {
                answer++;
            }
        }
    }
    return answer;
}

/*
공격을 받으면 내구도가 감소
내구도 0이하면 파괴
회복 스킬로 내구도를 높이려고 함.

파괴되었다가 회복 => 복구된다.
내구도가 0 이하인 파괴된 건물도 내구도가 계속 하락함.

1'000 * 1'000 => 1'000'000 O(N^2) * K
혹시..누적합?

*/