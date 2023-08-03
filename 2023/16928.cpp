#include <iostream>
#include <map>
#include <queue>

using namespace std;

int bfs(bool *isVisited,map<int,int> &object,int start){//너비우선 탐색... 최소를 찾음..
    
    queue<pair<int,int>> q;
    
    q.push(make_pair(start,0));
    
    pair<int,int> *curr;
    while(!q.empty()){
        curr=&q.front();
        q.pop();
        int tmp=curr->first;
        if(object.find(curr->first)!=object.end()){
            tmp=object[curr->first];
        }
        
        if(tmp>100)
            continue;
            
        if(isVisited[tmp])
            continue;
        isVisited[tmp]=true;
        
        if(tmp==100)
            break; //100번째칸 도달.
        
        q.push(make_pair(tmp+1,curr->second+1));
        q.push(make_pair(tmp+2,curr->second+1));
        q.push(make_pair(tmp+3,curr->second+1));
        q.push(make_pair(tmp+4,curr->second+1));
        q.push(make_pair(tmp+5,curr->second+1));
        q.push(make_pair(tmp+6,curr->second+1));

    }
    
    return curr->second;
}
int main()
{
    int N,M;
    cin>>N>>M;
    
    bool isVisited[105]={false,};
    map<int,int> object;
    for(int i=0;i<N+M;i++){
        int x,y;
        cin>>x>>y;
        object.insert(make_pair(x,y));
    }
    
    cout<<bfs(isVisited,object,1);
    
    return 0;
}