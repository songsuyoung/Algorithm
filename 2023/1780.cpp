
#include <iostream>
#include <map>
using namespace std;
void Cntpaper(int N,int **paper,pair<int,int> start,pair<int,int> end,map<int,int> &cnt){
    
    if(N<=0)
        return;
    //다른놈이 있는지확인
    bool isCheck=false;
    int benchmark=paper[start.first][start.second];
    
    for(int i=start.first;i<=end.first;i++){
        for(int j=start.second;j<=end.second;j++){
            if(benchmark!=paper[i][j]){
                isCheck=true;
                break;
            }
        }
    }
    
    if(!isCheck){
        cnt.insert(make_pair(benchmark,cnt[benchmark]++));
    }else{
            
    /*
    N(9)/3=3
    0~(N-1) N~(2N-1) N~(2N-1) 2N~3N-1
    
    1]
    [0,0] [0,N-1]
    [N-1,0] [N-1,N-1]
    2]
    [0,N] [0,2N-1]
    [2N-1,0] [2N-1,2N-1]
    3]
    [0,2N]
    [3N-1,0] [3N-1,3N-1]
    
    [N,2N-1] [N,2N-1]
    */
        pair<int,int> plus=make_pair(N/3,N/3);
        //row-col 3방향씩 쪼개기
        Cntpaper(N/3,paper,make_pair(start.first,start.second),make_pair(start.first+plus.first-1,start.second+plus.second-1),cnt);
        Cntpaper(N/3,paper,make_pair(start.first,start.second+plus.second),make_pair(start.first+plus.first-1,2*plus.second-1+start.second),cnt);
        Cntpaper(N/3,paper,make_pair(start.first,start.second+2*plus.second),make_pair(start.first+plus.first-1,end.second),cnt);
        
        Cntpaper(N/3,paper,make_pair(plus.first+start.first,start.second),make_pair(2*plus.first+start.first-1,start.second+plus.second-1),cnt);
        Cntpaper(N/3,paper,make_pair(plus.first+start.first,start.second+plus.second),make_pair(2*plus.first+start.first-1,2*plus.second-1+start.second),cnt);
        Cntpaper(N/3,paper,make_pair(plus.first+start.first,start.second+2*plus.second),make_pair(2*plus.first+start.first-1,end.second),cnt);
        
        Cntpaper(N/3,paper,make_pair(2*plus.first+start.first,start.second),make_pair(end.first,start.second+plus.second-1),cnt);
        Cntpaper(N/3,paper,make_pair(2*plus.first+start.first,start.second+plus.second),make_pair(end.first,2*plus.second-1+start.second),cnt);
        Cntpaper(N/3,paper,make_pair(2*plus.first+start.first,start.second+2*plus.second),make_pair(end.first,end.second),cnt);
    }
}
int main()
{
    
    int N;
    cin>>N;
    
    int **paper=new int*[N+1];
    
    map<int,int> cnt;
    for(int i=-1;i<=1;i++)
        cnt.insert(make_pair(i,0));
        
    for(int i=0;i<N;i++){
        paper[i]=new int[N];
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>paper[i][j];
        }
    }
    
    Cntpaper(N,paper,make_pair(0,0),make_pair(N-1,N-1),cnt);
            //map출력
    map<int,int>::iterator it;
        
    for(it=cnt.begin();it!=cnt.end();it++)
        cout<<it->second<<'\n';
    return 0;
}
