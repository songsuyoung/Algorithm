#include <string>
#include <vector>
#include <queue>
using namespace std;
class Pos
{
    public:
    pair<int,int> pos;
    int cnt;
    Pos(pair<int,int> p,int c):pos(p),cnt(c){}
};
int bfs(vector<string> &maps,pair<int,int> end,pair<int,int> start)
{
    queue<Pos> q;
    q.push(Pos(start,0));
    bool isVisited[101][101]={};
    int rows[4]={-1,1,0,0};
    int cols[4]={0,0,-1,1};
    
    while(!q.empty())
    {
        pair<int,int> pos=q.front().pos;
        int cnt=q.front().cnt;
        
        q.pop();
        if(isVisited[pos.first][pos.second]) continue;
        if(pos==end)
        {
            return cnt;
        }
        
        isVisited[pos.first][pos.second]=true;

        for(int i=0;i<4;i++)
        {
            int nextR=pos.first+rows[i];
            int nextC=pos.second+cols[i];
            
            if(nextR>=maps.size()||nextC>=maps[0].length()||nextR<0||nextC<0||maps[nextR][nextC]=='X') continue;
            q.push(Pos(make_pair(nextR,nextC),cnt+1));
        }
    }
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    int r,c=0;
    
    pair<int,int> start;
    pair<int,int> mid;
    pair<int,int> end;
    for(int i=0;i<maps.size();i++)
    {
        for(int j=0;j<maps[i].size();j++)
        {
            if(maps[i][j]=='S')
            {
                start=make_pair(i,j);
            }else if(maps[i][j]=='L')
            {
                mid=make_pair(i,j);
            }else if(maps[i][j]=='E')
            {
                end=make_pair(i,j);
            }   
        }
    }
    
    int isFind=bfs(maps,mid,start);
    if(isFind==-1)
    {
        answer=-1;   
    }
    else
    {
        int isExit=bfs(maps,end,mid);   
        if(isExit==-1)
            answer=-1;
        else
            answer=isExit+isFind;
    }
    
    return answer;
}