#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long recursive(int N, vector<long long> &dp)
{
    if (N<0)
    {
        return 0;
    }
    if (N == 0)
    {
        return dp[N];
    }
    
    if (dp[N] != 0)
    {
        return dp[N];
    }

    long long first = recursive(N-1,dp);

    long long second = recursive(N-2,dp);

    long long third = recursive(N-3,dp);
    
    return dp[N] = (first + second + third) % 1'000'000'009;
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    vector<long long> dp(1000005, 0);

    for (int i = 0; i < T; i++)
    {
        int dst;
        cin >> dst;
    
        dp[0] = 1;
        cout<<recursive(dst,dp)<<'\n';
    }
}