#include <iostream>
#include <queue>
using namespace std;

class Position{
  private:
  int sec;
  int pos;
  
  public:
  Position(int sec,int pos);
  int getPos();
  int getSec();
};

Position::Position(int pos,int sec){
    this->sec=sec;
    this->pos=pos;
}

int Position::getPos(){
    return pos;
}

int Position::getSec(){
    return sec;
}

int bfs(int start,int dest){//너비 우선 탐색 -> queue를 이용한 방법

    bool isVisited[100001]={false,};
    queue<Position> q;
    
    q.push(Position(start,0));
    
    Position *pos;
    
    while(!q.empty()){
        pos=&q.front();
        q.pop();
        
        int idx=pos->getPos();
                
        if(idx<0||idx>100001||isVisited[idx])
            continue;
            
        if(idx==dest){
            break;
        }
            
        isVisited[idx]=true;

        int minus=idx-1;
        int plus=idx+1;
        int mult=idx*2;
        
        
        q.push(Position(plus,pos->getSec()+1));
        q.push(Position(minus,pos->getSec()+1));
        q.push(Position(mult,pos->getSec()+1));
        
    }
    
    return pos->getSec();
}

int main()
{
    
    int start,dest;
    
    cin>>start>>dest;
    
    cout<<bfs(start,dest)<<'\n';
    
    return 0;
}
