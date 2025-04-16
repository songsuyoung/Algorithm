#include <bits/stdc++.h>
using namespace std;

int dp[45];
int cnt;
int fibonachi(int N)
{
    if (N <= 2)
    {
        return dp[N];
    }

    if (dp[N] != 0)
    {
        return dp[N];
    }
	cnt++;

    return dp[N] = fibonachi(N-1) + fibonachi(N-2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

 
    int N;
    cin>>N;

    dp[1] = 1;
    dp[2] = 1;

    cout<<fibonachi(N)<<' '<<cnt<<'\n';
}
