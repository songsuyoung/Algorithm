#include <iostream>
#include <queue>
using namespace std;

class Tomato{
    public:
    int row;
    int col;
    int height;
    int days;

    Tomato(int row,int col,int height,int day){
        this->row=row;
        this->col=col;
        this->height=height;
        this->days=day;
    }
};

int bfs(int R,int C,int H,bool isVisited[][110][110],int boxs[][110][110],queue<Tomato> &q,const int &emptyBox){

    int rows[4]={1,-1,0,0};
    int cols[4]={0,0,1,-1};
    //앞뒤 체크...
    int up[2]={1,-1};
    Tomato tmp=q.front();
    int riped=0;
    int days = 0;
    while(!q.empty()){
        if(riped==(R*C*H)){
            break;
        }
        tmp=q.front();
        q.pop();

        if(isVisited[tmp.height][tmp.row][tmp.col]){
            continue;
        }
        isVisited[tmp.height][tmp.row][tmp.col]=true;
        riped++;
        for(int i=0;i<4;i++){
            int nextR=tmp.row+rows[i];
            int nextC=tmp.col+cols[i];
            days = tmp.days + 1;
            if(nextR<0||nextC<0||nextR>=R||nextC>=C||isVisited[tmp.height][nextR][nextC]||boxs[tmp.height][nextR][nextC]!=0){
                continue;
            }
 
            q.push(Tomato(nextR,nextC,tmp.height,days));
        }

        for(int i=0;i<2;i++){
            int nextH=tmp.height+up[i];
            days = tmp.days + 1;
            if(nextH<0||nextH>=H||isVisited[nextH][tmp.row][tmp.col]||boxs[nextH][tmp.row][tmp.col]!=0){
                continue;
            }
            q.push(Tomato(tmp.row,tmp.col,nextH,days));
        }
    }
    if((R*C*H-emptyBox-riped)!=0){
        return -1;
    }

    return days-1;
}
int main(){

    int C,R,H;
    cin>>C>>R>>H;
    
    int boxs[110][110][110];
    bool isVisited[110][110][110]={false,};

    queue<Tomato> q;
    int emptyBox=0;

    for(int i=0;i<H;i++){
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                cin>>boxs[i][r][c];

                if(boxs[i][r][c]==1){
                    q.push(Tomato(r,c,i,0));
                }else if(boxs[i][r][c]==-1){
                    emptyBox++;
                }
            }
        }
    }
    
    cout<<bfs(R,C,H,isVisited,boxs,q,emptyBox)<<'\n';
}