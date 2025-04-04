#include <bits/stdc++.h>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp(n+2, vector<int>(m+2,0));
    
    //puddle 위치에 -1을 해놓는다.
     for(int i=0; i<puddles.size(); i++)
    {
         dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    dp[n][m] = 1;
    
    for(int i=n; i>0; i--)
    {
        for(int j=m; j>0; j--)
        {
            if(dp[i][j] == -1) continue;
            
            if(dp[i][j+1] != -1)
            {
                dp[i][j]+=dp[i][j+1]%1'000'000'007;
            }
            
            if(dp[i+1][j] != -1)
            {
                dp[i][j]+=dp[i+1][j]%1'000'000'007;
            }
            
            dp[i][j]%=1'000'000'007;
        }
    }

    answer = dp[1][1];
    return answer;
}

/*
집에서 학교가는 길 m x n 
=> 학교에서 -> 집으로 가도록 구현하는게 좋다.
물에 잠긴 지역을 제외,. 오른쪽 아래쪽으로만 움직여서 집으로 가야하며, 최단 경로의 개수를 1'000'000'007 로 나누어야한다.
=> 갈 수 있는 길이기 때문에 -> +1씩 해주면 된다.
만약 아래에서 위로 올라간다면, 
row = {-1,0};
col = {0,-1};
//간다.
// dp로 이루어져야 한다.
*/