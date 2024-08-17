#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer=0;
    vector<vector<int>> dp(land.size(),vector<int>(land[0].size(),0));
    
    //초기값 업데이트
    for(int i=0;i<4;i++)
    {
        dp[land.size()-1][i] = land[land.size()-1][i];
    }
    
    
    for(int r=land.size()-2;r>=0;r--) //O(N)
    {
        for(int c=0;c<4;c++) 
        {
            for(int j=0;j<4;j++)
            {
                if(c==j) continue;
                dp[r][c] =max(dp[r][c],land[r][c] + dp[r+1][j]); 
            }
        }
    }
    
    for(int c=0;c<=4;c++)
    {
        answer = max(answer, dp[0][c]);
    }
    
    return answer;
}