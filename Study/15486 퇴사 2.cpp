#include <iostream>
#include <vector>
using namespace std;

int recursive(int N,vector<pair<int, int>>& time, vector<int> &dp,int idx)
{
    if (idx >= time.size())
    {
        //끝에 도달
        return 0;
    }

    if (dp[idx] != 0) return dp[idx];

    //선택한다.
    if (idx + time[idx].first <= N)
    {
        dp[idx] = max(dp[idx], recursive(N, time,dp, idx + time[idx].first)) + time[idx].second;
    }

    dp[idx] = max(dp[idx], recursive(N, time, dp, idx + 1));

    return dp[idx];
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
   
    int N;
    cin >> N;

    vector<pair<int, int>> time(N);
    vector<int> dp(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> time[i].first >> time[i].second;
    }

    cout<<recursive(N,time,dp,0)<<'\n';
}