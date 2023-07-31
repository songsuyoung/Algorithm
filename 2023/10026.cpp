#include <iostream>
#include <queue>
using namespace std;
//깊이 우선 탐색
void bfs(int n,char arr[][102],bool isVisited[][102],int &start,int &end,char &label,int *rows,int *cols){

    queue<pair<int,int>> q;
    q.push(make_pair(start,end));
    
    while(!q.empty()){
        pair<int,int> curr =q.front();
        q.pop();
        if(isVisited[curr.first][curr.second])
            continue;
        isVisited[curr.first][curr.second]=true;

        for(int i=0;i<4;i++){
            int newR=curr.first+rows[i];
            int newC=curr.second+cols[i];
            
            char checked=arr[newR][newC];
            
            if(!isVisited[newR][newC]&&checked==label){
                q.push(make_pair(newR,newC));
            }
        }
    }
}

void dfs(char arr[][102],bool isVisited[][102],int &r,int &c,char &label,int *rows,int *cols){
    
    isVisited[r][c]=true;
    
    for(int i=0;i<4;i++){
        int newR=r+rows[i];
        int newC=c+cols[i];
        
        if(!isVisited[newR][newC]&&arr[newR][newC]==label){
            dfs(arr,isVisited,newR,newC,label,rows,cols);
        }
    }
}
void init(int &cnt,bool isVisited[][102],char arr[][102],int n){
    cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            isVisited[i][j]=false;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='G')
                arr[i][j]='R';
        }
    }
}
int main()
{
    char arr[102][102];
    
    int n;
    cin>>n;
    
    char trash;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %1c",&arr[i][j]);
            //한칸 띄어쓰기할 경우 공백, \n 등 다 무시가능
        }
    }
    
    int rows[4]={0,0,-1,1};
    int cols[4]={-1,1,0,0};
    bool isVisited[102][102]={false,};
    int cnt=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!isVisited[i][j]){
                cnt++;
                dfs(arr,isVisited,i,j,arr[i][j],rows,cols);
            }
        }
    }
    
    cout<<cnt<<' ';
    
    init(cnt,isVisited,arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!isVisited[i][j]){
                cnt++;
                dfs(arr,isVisited,i,j,arr[i][j],rows,cols);
            }
        }
    }
    
    cout<<cnt<<'\n';
    return 0;
}