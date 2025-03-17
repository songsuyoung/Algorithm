#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &first, vector<int>& second)
{
    return first[1] < second[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end(),compare);
    
    int range = routes[0][1];
    for(int i=1; i<routes.size(); i++)
    {
        //cout<<routes[i][0]<<' '<<routes[i][1]<<' '<<range<<'\n';
        if(routes[i][0]>range)
        {   
            answer++;
            range = routes[i][1];
        }
    }
    return answer;
}

/*
고속도로 단속용 카메라

차량 경로 routes
모든 차량이 한 번은 단속용 카메라를 만나도록 하려면 최소 몇 대의 카메라를 설치해야하는지

예)

=>10'000대, -30,000~30,000 -> 즉 60'000만 => 2차원 배열로 하면, 시간초가 발생 6억번...
-20,-15
-14,-5
-18,-13
-5,-3




couting 배열이 되나?

-5+30'000 => 299995 299996 299997 299998..
*/