#include <bits/stdc++.h>
using namespace std;

int recursive(vector<vector<int>>& triangle,int dp[][505], int r, int c)
{
    if(r>=triangle.size() || c>=triangle[r].size())
    {
        //최대로 도착
        return 0;
    }
    
    if(dp[r][c] != -1)
    {
        return dp[r][c];
    }
    
    dp[r][c] = max(dp[r][c], recursive(triangle, dp, r+1,c) + triangle[r][c]); //대각선-왼쪽 이동
    dp[r][c] = max(dp[r][c], recursive(triangle, dp, r+1,c+1) + triangle[r][c]); //대각선-오른쪽 이동
   
    return dp[r][c];
}

int solution(vector<vector<int>> triangle) {
    int dp[505][505]; //왼쪽 대각선을 선택했냐, 오른쪽 대각선을 선택했냐에 따라 달라진다.

    //0도 포함이기 때문에, 0일때 효율성이 떨어짐. -1로 초기화를 진행한다. 
    memset(dp, 0, sizeof(int)*505*505);
    
    int answer = 0;
    //= recursive(triangle,dp, 0,0); => bottom - up 방식 (시간초과)
    
    //top-down 방식 => 반복문
    dp[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); i++)
    {
        for(int j=0; j<triangle[i].size(); j++)
        {
            dp[i][j] = dp[i-1][j] + triangle[i][j];
            
            if(j-1>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + triangle[i][j]);
            }
            
            answer = max(answer, dp[i][j]);
        }
    }

    return answer;
}

/*

아래 칸으로 이동할 때 대각선-오른쪽/대각선-왼쪽 한칸 

row = {1,1};
col = {-1,1};

예를 들어, 3에서 그 아래칸의 8 or 1

트라이앵글이 매개변수로 주어질 때 거쳐간 순자의 최댓값을 return => dp
건너간 값을 누적해서 최대값을 찾는 문제 => dfs 구현 (왼쪽으로 또는 오른쪽으로 이동)
*/