#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;

    //패턴을 만든다
    vector<pair<int,int>> v = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
    
    //기울기 공식 (y2-y1)/(x2-x1)
    for(int i=0; i<v.size()/2; i++)
    {
        pair<int,int> preIdx = v[i];
        pair<int,int> sufIdx = v[v.size()-i-1];
        
        //0이 될 확률
        if(dots[preIdx.first][0] == dots[preIdx.second][0] || dots[sufIdx.first][0] == dots[sufIdx.second][0]) continue;
        
        double scope1 = (double)(dots[preIdx.first][1] - dots[preIdx.second][1])/(dots[preIdx.first][0] - dots[preIdx.second][0]);
        double scope2 = (double)(dots[sufIdx.first][1] - dots[sufIdx.second][1])/(dots[sufIdx.first][0] - dots[sufIdx.second][0]);
    
        if(scope1 == scope2)
        {
            answer=1;
            break;
        }
    }

    return answer;
}