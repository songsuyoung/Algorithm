#include <iostream>

using namespace std;

void compressQuad(int quadTree[][65],pair<int,int> start,pair<int,int> end){
    
    //크기가 1일때 검사해야함 -> 어차피 벤치마크에서 나오기 때문에 
    
    int benchmark=quadTree[start.first][start.second];
  
    bool isReapted=false;
    for(int i=start.first;i<=end.first;i++){
        for(int j=start.second;j<=end.second;j++){
            if(benchmark!=quadTree[i][j]){
               isReapted=true;
               break;
            }
        }
    }
                        /*8기준
                    0 - start 3=mid 4=mid+1 7=end
                    [ 0,0 - 3,3 ] 
                    [ 0,4 - 3,7 ]
                    [ 4,0 - 7,3 ]
                    [ 4,4 - 7,7 ]
                    [ ]
                    */
                    //4가지 방향 검사 진행
    //cout<<end.first<<'\n';
    if(!isReapted)
    {
        cout<<benchmark;
        return;
    }
    else{
        cout<<"(";
        int midR=(start.first+end.first)/2;
        int midC=(start.second+end.second)/2;
        compressQuad(quadTree,make_pair(start.first,start.second),make_pair(midR,midC)); //왼쪽위
        compressQuad(quadTree,make_pair(start.first,midC+1),make_pair(midR,end.second)); //오른쪽 위
        compressQuad(quadTree,make_pair(midR+1,start.second),make_pair(end.first,midC)); //왼쪽 아래
        compressQuad(quadTree,make_pair(midR+1,midC+1),make_pair(end.first,end.second)); //오른쪽 아래
        cout<<")";
    }
        
}
int main()
{
    int N;
    cin>>N; //cin은 한줄입력...
    int quadTree[65][65];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
           scanf("%1d",&quadTree[i][j]);
        }
    }

    compressQuad(quadTree,make_pair(0,0),make_pair(N-1,N-1));

    return 0;
}