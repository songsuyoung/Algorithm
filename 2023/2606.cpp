#include <iostream>
#include <queue>
using namespace std;
int dfs(int N,bool *isVisited,bool computers[][150],int st){
    int cnt=1; //자기자신 포함
    
    if(isVisited[st])
        return 0;
        
    isVisited[st]=true;
    
    for(int i=1;i<=N;i++){
        if(!isVisited[i]&&computers[st][i]){
            cnt+=dfs(N,isVisited,computers,i);
        }
    }
    return cnt;
}

int bfs(int N,bool *isVisited,bool computers[][102]){ //bfs 너비우선탐색 queue dfs 깊이우선탐색 stack

    queue<int> q;
    
    q.push(1);
    int cnt=0;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        if(isVisited[node])
            continue;
        
        isVisited[node]=true;
        cnt++;
        
        for(int i=1;i<=N;i++){
            if(!isVisited[i]&&computers[node][i]){
                q.push(i);
            }
        }
    }
    
    return cnt-1; //자기 자신을 제외한다.
}

int main()
{
    int n,e;
    
    cin>>n>>e;
    
    bool computers[150][150];
    
    for(int i=0;i<e;i++){
        int n1,n2;
        cin>>n1>>n2;
        computers[n1][n2]=true;
        computers[n2][n1]=true;
    }
    
    bool isVisited[150]={false,};
    
    cout<<bfs(n,isVisited,computers);
    
    return 0;
}
