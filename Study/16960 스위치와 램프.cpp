#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool isCheck(int M,bool *lamp){
    
    int cnt=0;
    for(int i=1;i<=M;i++){
        if(lamp[i]){
            cnt++;
            lamp[i]=false;
        }
    }
    
    return cnt>=M;
}

void onLamp(int idx,map<int,vector<int>> &button,bool *lamp){
    for(int i=0;i<button[idx].size();i++){
        lamp[button[idx][i]]=true;
    }
}

int main()
{
    
    int N,M;//스위치, 램프
    
    bool lamp[2005]={false,}; //스위치 1부터 시작
    bool isVisited[2005]={false,}; //button 방문 여부 
    map<int,vector<int>> button; //스위치 버튼, 스위치 숫자 - 연결된 램프 idx
    cin>>N>>M;
    
    for(int i=1;i<=N;i++){
        int lampCnt;
        cin>>lampCnt;
        for(int j=0;j<lampCnt;j++){
            int lampIdx;
            cin>>lampIdx;
            
            button[i].push_back(lampIdx); //램프 idx저장장
        }
    }
    
    for(int i=1;i<=N;i++){ //램프를 하나씩 꺼볼 예정
        //1번 인덱스부터 빼고 확인
        
        for(int j=1;j<=N;j++){
            if(i==j){
                continue;
            }
            onLamp(j,button,lamp);
        }
        if(isCheck(M,lamp)){
            cout<<'1';
            return 0;
        }
    }
    cout<<'0';
    return 0;
}