#include <iostream>
#include <queue>
#include <string>

using namespace std;

string bfs(bool *isVisited,int start,int dest){//bfs
    queue<pair<int,string>> q;
    q.push(make_pair(start,"")); //1234 ""
    pair<int,string> tmp;
    while(!q.empty()){
        
        tmp=q.front();
        int idx=tmp.first;
        string result=tmp.second;
        q.pop();
        
        if(dest==idx){
            return tmp.second;
        }
        
        if(idx<0||idx>=10000){
           continue; 
        }
        
        int index=((idx*2)%10000);
         
        if(!isVisited[index]){
            q.push(make_pair(index,result+"D"));
            isVisited[index]=true;
        }
        index=idx-1<0? 9999:idx-1;
        
        if(!isVisited[index]){
            q.push(make_pair(index,result+"S"));
            isVisited[index]=true;
        }
        index=(idx % 1000) * 10 + idx / 1000;
        
        if(!isVisited[index]){
            q.push(make_pair(index,result+"L"));
            isVisited[index]=true;
        }
        
        index=(idx % 10) * 1000 + idx / 10;
      
        if(!isVisited[index]){
            q.push(make_pair(index,result+"R"));
            isVisited[index]=true;
        }
    }
    return "";
}
void init(bool *isVisited){
    for(int i=0;i<10005;i++){
        isVisited[i]=false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    scanf("%d",&N);
    bool isVisited[10005]={false,};
    vector<string> results;
    for(int i=0;i<N;i++){
        init(isVisited);
        int val;
        int result;
        scanf("%d %d",&val,&result);
        
        results.push_back(bfs(isVisited,val,result));
    }
    
    for(int i=0;i<results.size();i++){
        cout<<results[i]<<'\n';
    }
    return 0;
}