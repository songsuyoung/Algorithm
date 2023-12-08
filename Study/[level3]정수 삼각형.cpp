#include <string>
#include <vector>

using namespace std;
//완전 탐색 
int recursive(vector<vector<int>> &triangle,vector<vector<int>> &dp,int idx,int level)
{
    if(level>=triangle.size()-1)
    {
        return triangle[level][idx];
    }
    
    if(dp[level][idx]!=0)
        return dp[level][idx];
    
    int left=recursive(triangle,dp,idx,level+1);
    int right=recursive(triangle,dp,idx+1,level+1);
    
    dp[level][idx]=max(left,right)+triangle[level][idx];
    
    return dp[level][idx];
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp;
    
    for(int i=0;i<triangle.size();i++)
    {
        dp.push_back(vector<int>(triangle[i].size(),0));
    }
    
    answer=recursive(triangle,dp,0,0);
    
    return answer;
}