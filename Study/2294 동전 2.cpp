#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    
    vector<int> dp(K+1,1000001);
    dp[0]=0;
    
    //j원 개수 저장
    for(int i=0;i<N;i++)
    {
        int coin;
        cin>>coin;
         for(int j=coin;j<=K;j++)
        {
            dp[j]=min(dp[j],dp[j-coin]+1);    
        }
    }
    
    if(dp[K]>=1000001) cout<<-1<<'\n';
    else
        cout<<dp[K]<<'\n';
    return 0;
}