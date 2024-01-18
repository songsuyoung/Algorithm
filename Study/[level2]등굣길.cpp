#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp(n+2,vector<int>(m+2,0));
    
    for(int i=0;i<puddles.size();i++)
    {
        dp[puddles[i][1]][puddles[i][0]]=-1;
    }
    
    dp[0][1]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dp[i][j]==-1){
                dp[i][j]=0;
                continue;   
            }
            if(dp[i][j]!=-1)
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1'000'000'007;
        }
        
    }
    
    return answer=dp[n][m];
}