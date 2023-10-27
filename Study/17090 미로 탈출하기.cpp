#include <iostream>
using namespace std;

int recursive(int R,int C,int dp[][505],char maze[][505],int r,int c)
{

    if(dp[r][c]==-1)
        return -1; //-1을 만나게 되면 -1 반환
    if(dp[r][c]==1)
        return dp[r][c]; //1을 만나게 되면 1 반환
    if(r<0||c<0||r>=R||c>=C)
        return 1; //통과하면 1반환

    dp[r][c]=-1;

    switch(maze[r][c]){
        case 'U':
        dp[r][c]=recursive(R,C,dp,maze,r-1,c);
        break;
        case 'R':
        dp[r][c]=recursive(R,C,dp,maze,r,c+1);
        break;
        case 'D':
        dp[r][c]=recursive(R,C,dp,maze,r+1,c);
        break;
        case 'L':
        dp[r][c]=recursive(R,C,dp,maze,r,c-1);
        break;
    }

    return dp[r][c];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp[505][505]={};
    char maze[505][505];

    int R,C;
    cin>>R>>C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>maze[i][j];
        }
    }

    int cnt=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(dp[i][j]==-1)
                continue;
            if(dp[i][j]==0){
                dp[i][j]=recursive(R,C,dp,maze,i,j);
            }
            if(dp[i][j]==1){
                cnt++;
            }
        }
    }

    cout<<cnt<<'\n';
}