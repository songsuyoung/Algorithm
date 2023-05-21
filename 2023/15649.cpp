/*
base case 저장된 vector개수가 같을 때 출력
recursive case
초기 
1 -> 2 (m과 같음 1 2출력) -> pop_back의해 2제거 -> 방문 해제
1 -> 3 (위와 같음) -> pop_back -> 방문 해제
1 -> 4 (위와 같음) -> pop_back -> 방문 해제 -> 1이 끝났기에, pop_back, 방문 해해제
2 -> 1 (위를 반복)...
*/
#include <iostream>
#include <vector>

using namespace std;

void PrintSeqNum(bool isvisited[],int n,int m,vector<int> &seqNum){
    //basecase
    
    if(seqNum.size()==m){
        for(int i=0;i<seqNum.size();i++)
            cout<<seqNum[i]<<' ';
        cout<<'\n';
        return ;
    }
    
    for(int i=0;i<n;i++){
        if(!isvisited[i]){
            isvisited[i]=true;
            seqNum.push_back(i+1);
            PrintSeqNum(isvisited,n,m,seqNum);
            seqNum.pop_back();
            isvisited[i]=false;
        }
            
    }
}

int main()
{
    
    int N,M;
    
    cin>>N>>M;
    bool *isvisited=new bool[N]{false};
    vector<int> seqNum;
    PrintSeqNum(isvisited,N,M,seqNum);
    return 0;
}