#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

class Position{
    public:
    tuple<int, int, int> pos;
    int min;
    Position(){}
    Position(tuple<int,int,int> pos,int min){
        this->pos=pos;
        this->min=min;
    }
};

int bfs(int L,int R,int C,char building[][35][35],bool isVisited[][35][35],const Position &start,vector<Position> &ends){

    queue<Position> q;
    q.push(start);

    int heights[2]={1,-1};
    int rows[4]={1,-1,0,0};
    int cols[4]={0,0,1,-1};
    int min=0;
    while(!q.empty())
    {
        tuple<int,int,int> pos=q.front().pos;
        min=q.front().min;
        q.pop();

        if(isVisited[get<0>(pos)][get<1>(pos)][get<2>(pos)]){
            continue;
        }
        
        for(int i=0;i<ends.size();i++){
            if(get<0>(pos)==get<0>(ends[i].pos)&&get<1>(pos)==get<1>(ends[i].pos)&&get<2>(pos)==get<2>(ends[i].pos)){
                return min;
            }   
        }
        
        isVisited[get<0>(pos)][get<1>(pos)][get<2>(pos)]=true;
        //위 아래 검사
        for(int i=0;i<2;i++){
            int height=get<0>(pos)+heights[i];

            if(height<0||height>=L||isVisited[height][get<1>(pos)][get<2>(pos)]||building[height][get<1>(pos)][get<2>(pos)]=='#'){
                continue;
            }

            q.push(Position(make_tuple(height,get<1>(pos),get<2>(pos)),min+1));
        }
        //상하좌우 검사
        for(int i=0;i<4;i++){
            int row=get<1>(pos)+rows[i];
            int col=get<2>(pos)+cols[i];

            if(row<0||row>=R||col<0||col>=C||isVisited[get<0>(pos)][row][col]||building[get<0>(pos)][row][col]=='#'){
                continue;
            }

            q.push(Position(make_tuple(get<0>(pos),row,col),min+1));
        }

    }

    return 0;
}
int main()
{
    char building[35][35][35]={};
    bool isVisited[35][35][35]={false,};

    vector<Position> ends;
    while(true){
        
        int L,R,C;
        cin>>L>>R>>C;
        ends.clear();
        
        if(L==0&&R==0&&C==0)
            break;
            
        Position start,end;
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                for(int c=0;c<C;c++){
                    scanf(" %1c",&building[i][j][c]);
                    isVisited[i][j][c]=false;
                    
                    if(building[i][j][c]=='S'){
                        //시작위치
                        start.pos=make_tuple(i,j,c);
                        start.min=0;
                    }else if(building[i][j][c]=='E'){
                        //끝위치
                        ends.push_back(Position(make_tuple(i,j,c),0));
                    }
                }
            }
        }
        getchar();
        
        int escaped=bfs(L,R,C,building,isVisited,start,ends);
    /*
    Escaped in 11 minute(s).
    Trapped!
    */
        if(escaped==0){
            cout<<"Trapped!\n";
        }else{
            cout<<"Escaped in "<<escaped<<" minute(s).\n";
        }
    }
    return 0;
}