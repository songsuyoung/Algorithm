/*
-1,-1 -1,0 -1,1
0,-1  0,0  0,1
1,-1 1,0  1,1
*/
#include <iostream>
#include <vector>
using namespace std;

bool isChecking(bool **road,int N,int *row,int *col,int &curRow,int &curCol){

    for(int i=0;i<8;i++){
        int newRow=curRow;
        int newCol=curCol;
        while(true){
            if(newRow<0||newCol<0||newRow>=N||newCol>=N)
                break;
             
            if(road[newRow][newCol]){
               return false; //nQueen을놓을 수 없음 
            }
            
            newRow+=row[i];
            newCol+=col[i];
        }
    }
    
    return true;
}
//타
/*
탐색 공간을 줄이기 위해서 cache해놓고 idx값이 비어있으면 계산.
있으면 가져와서 사용하는 방법을 사용해야함.
*/
int putQueen(bool **queen,int N,int *row,int *col,int CurrR,int CurrC,int count,bool *isVisited){
    if(count>=N){
        return 1;
    }
   
    if(CurrR>=N||CurrC>=N){
        return 0;
    }
   
    int ret1=0,ret2=0;
    if(!isVisited[CurrC]&&isChecking(queen,N,row,col,CurrR,CurrC)){
        queen[CurrR][CurrC]=true;
        isVisited[CurrC]=true;
        ret2+=putQueen(queen,N,row,col,CurrR+1,0,count+1,isVisited);
        queen[CurrR][CurrC]=false;
        isVisited[CurrC]=false;
    }

    ret1+=putQueen(queen,N,row,col,CurrR,CurrC+1,count,isVisited);
    
    
    return ret1+ret2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    bool **queen=new bool*[N];
    for(int i=0;i<N;i++){
        queen[i]=new bool[N]{false};
    }
    /*
    -1,-1 -1,0 -1,1
   
    */
    int row[8]={-1,-1,-1,0,0,1,1,1};
    int col[8]={-1,0,1,-1,1,-1,0,1};
    
    bool isColVisited[15]{false};
   
    //14개일때 만개를 넘음 일단 십만개만 만들어보자
    cout<<putQueen(queen,N,row,col,0,0,0,isColVisited)<<'\n';
   
    return 0;
}