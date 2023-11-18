#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
- 방향이 정해져있기 때문에 isVisited (즉, 조합/순열일 경우에 사용)
- 선택해/안해 방법 

군인 친구 -> 누나 3명 

시골 

(이해 ㄴㄴ 왜 뭐가?)
*/

enum RGB
{
    R=0,
    G=1,
    B=2,
};
int recursive(int idx,int N,int selected,int dp[][3],int rgb[][3])
{
    if(idx==N)
        return 0;
    
    int res=INT_MAX;

    if(dp[idx][selected]!=0)
        return dp[idx][selected];
    switch(selected)
    {
        case R:
            dp[idx][selected]=min(recursive(idx+1,N,G,dp,rgb)+rgb[idx][R],recursive(idx+1,N,B,dp,rgb)+rgb[idx][R]);
        break;
        case G:
            dp[idx][selected]=min(recursive(idx+1,N,R,dp,rgb)+rgb[idx][G],recursive(idx+1,N,B,dp,rgb)+rgb[idx][G]);
        break;
        case B:
            dp[idx][selected]=min(recursive(idx+1,N,R,dp,rgb)+rgb[idx][B],recursive(idx+1,N,G,dp,rgb)+rgb[idx][B]);
        break;
    }

    return dp[idx][selected];
}
int main()
{

    int N;
    cin>>N;

    int rgb[1001][3]={};
    int dp[1001][3]={};
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>rgb[i][j];
        }
    }
    int res=INT_MAX;
    for(int i=0;i<3;i++)
        res=min(res,recursive(0,N,i,dp,rgb));
    cout<<res<<'\n';
}