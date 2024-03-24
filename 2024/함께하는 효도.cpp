#include <bits/stdc++.h>
using namespace std;

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};

int recursive(int M, vector<vector<int>> &arr, vector<pair<int,int>> &pos,int sec,int idx)
{
    //....
    if(sec >= M*4) return 0; //0초에서 +3초

    int maxVal = 0;

    for(int i=0;i<4;i++)
    {
        int nextR = pos[idx].first + rows[i];
        int nextC = pos[idx].second + cols[i];

        if(nextR<=0||nextC<=0||nextR>=arr.size()||nextC>=arr.size()) continue;

        //초기화 구문
        pair<int,int> originalPos = pos[idx];
        int tmp = arr[pos[idx].first][pos[idx].second];
        bool isFirst = tmp != 0;

        //수확
        arr[pos[idx].first][pos[idx].second] = 0;

        //위치 이동
        pos[idx].first = nextR;
        pos[idx].second = nextC; 
        
        //다음 idx 이동시킴
        if(isFirst)
            maxVal = max(maxVal,recursive(M,arr,pos,sec+1,(idx+1)%M) + tmp);
        else
            maxVal = max(maxVal,recursive(M,arr,pos,sec+1,(idx+1)%M));

        //원상복구
        pos[idx] = originalPos;

        if(isFirst)
            arr[pos[idx].first][pos[idx].second] = tmp;
        
        isFirst = false;
    }

    return maxVal;

}

int main()
{
    int N,M;
    cin>>N>>M;

    vector<vector<int>> arr(N+1,vector<int>(N+1,0));
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<pair<int,int>> curPos;

    for(int i=0;i<M;i++)
    {
        pair<int,int> pos;
        cin>>pos.first>>pos.second;

        curPos.push_back(pos);
    }

    cout<<recursive(M,arr,curPos,0,0)<<'\n';

    return 0;
}
