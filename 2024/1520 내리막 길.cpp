#include <iostream>
#include <vector>
using namespace std;

int recursive(int R,int C,vector<vector<int>> &map, vector<vector<int>> &dp,int r,int c)
{
    if(r==R&&c==C) return 1;

    int res=0;

    if(dp[r][c]!=-1) return dp[r][c];

    dp[r][c]=0; //방문 처리 오류

    if((r+1)<=R&&map[r][c]>map[r+1][c])
    {
        dp[r][c]+=recursive(R,C,map,dp,r+1,c);
    }

    if((c+1)<=C&&map[r][c]>map[r][c+1])
    {
        dp[r][c]+=recursive(R,C,map,dp,r,c+1);
    }

    if((r-1)>=1 && map[r][c]>map[r-1][c])
    {
        dp[r][c]+=recursive(R,C,map,dp,r-1,c);
    }

    if((c-1)>=1 && map[r][c]>map[r][c-1])
    {
        dp[r][c]+=recursive(R,C,map,dp,r,c-1);
    }

    return dp[r][c];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R,C;

    cin>>R>>C;


    vector<vector<int>> map(R+1,vector<int>(C+1,0));
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin>>map[i][j];
        }
    }

    vector<vector<int>> dp(R+1,vector<int>(C+1,-1));

    cout<<recursive(R,C,map,dp,1,1)<<'\n';
}