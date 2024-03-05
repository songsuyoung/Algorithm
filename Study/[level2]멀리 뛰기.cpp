#include <string>
#include <vector>

using namespace std;

int recursive(int n,int *dp)
{
    if(n<0) return 0;
    if(n==0)
    {
        return 1;
    }
    
    if(dp[n]!=0) return dp[n];
    int oneStep = recursive(n-1,dp)%1234567;
    int twoStep = recursive(n-2,dp)%1234567;
    
    return dp[n]=(oneStep+twoStep)%1234567;
}

long long solution(int n) {
    int dp[2002]={0,};
    long long answer = recursive(n,dp);

    return answer;
}