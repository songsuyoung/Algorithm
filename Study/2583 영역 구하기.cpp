#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//행에 없는 숫자를 저장한다

//예를 들어 0 6 0 2 7 8 1 3 5
//vector에 저장 <- 4,9
//4 6 9 2 7 8 1 3 5
//9 6 4 2 7 8 1 3 5
//0 위치에 vector를 적절하게 놓고 열 위치에서 검사한다.
//0 7 0 3 8 5 1 6 2 <- 열에 해당 놓은 숫자가 없으면 true (성공)
//열에 해당 숫자가 있으면 빈칸을 false반환 (실패) 다음 경우의 수로 놓기

void bfs(int R,int C,bool area[][101],bool isVisited[][101],vector<int> &v,int i,int j)
{
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    int cnt=0;
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;

        q.pop();

        if(isVisited[r][c]) continue;

        isVisited[r][c]=true;
        cnt++;
        for(int i=0;i<4;i++)
        {
            int nextR=r+rows[i];
            int nextC=c+cols[i];

            if(nextR>=R||nextC>=C||nextR<0||nextC<0||area[nextR][nextC]==true) continue;

            q.push(make_pair(nextR,nextC));
        }
    }
    v.push_back(cnt);
}
int main()
{

    int M,N,K;

    //M = row N=col

    cin>>M>>N>>K;

    bool area[101][101]={};
    for(int i=0;i<K;i++)
    {
        //왼쪽 하단 (x,y) x좌표는 col 시작 좌표,y좌표는 row 끝 좌표
        //오른쪽 상단 (x,y) x-1좌표는 col 끝 좌표, y좌표는 M-y 시작 좌표
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;    //열은 그대로 사용, 행은 M-ey/M-sy 

        for(int i=M-ey;i<M-sy;i++)
        {
            for(int j=sx;j<ex;j++)
            {
                area[i][j]=true;
            }
        }
    }

    //bfs수행.
    bool isVisited[101][101]={};
    int cnt=0;
    vector<int> v;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(area[i][j]==false&&isVisited[i][j]==false)
            {
                cnt++;
                bfs(M,N,area,isVisited,v,i,j);
            }
        }
    }

    cout<<cnt<<'\n';

    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<' ';
}
