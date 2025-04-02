#include <bits/stdc++.h>
using namespace std;

int dp[100'005];

int fibonachi(int num)
{
    if(num<=1)
    {
        return dp[num];
    }
    
    if(dp[num]!=0)
    {
        return dp[num];
    }
    
    dp[num] = fibonachi(num-2)%1234567 + fibonachi(num-1)%1234567;
    return dp[num];
}

int solution(int n) {
    int answer = 0;
    dp[0] = 0;
    dp[1] = 1;
    
    answer = fibonachi(n)%1234567;
    
    return answer;
}