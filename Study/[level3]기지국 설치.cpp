#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int first=1;
    
    for(int i=0;i<stations.size();i++)
    {
        int end = stations[i] - w - 1; //9일 때, 6이 나온다. 1부터 6까지 거리 5 + 1을 진행한다.
        
        if(first<=end) //end가 first보다 작은 경우는 겹치는 경우 or 경계선 침범
        {
            int dist = (end - first) + 1; //두 좌표를 뺀 후 +1 을 하면 거리가 나온다.
    
            answer+=(dist/(2*w+1));
            if(dist%(2*w+1))
            {
                answer+=1;   
            }
        }
        
        first = stations[i] + w + 1; //우측 가장 큰 값보다 1 더 간 거리를 구한다.
    }

    
    if(first <= n) //first가 n을 넘었을 경우에는 경계선을 넘어섰기 때문에,
    //위 반복문에서 전부 계산이 완료됐음을 의미한다.
    {

        int dist = (n - first) + 1;
        
        answer+=(dist/(2*w+1));
        if(dist%(2*w+1))
        {
            answer+=1;
        }
    }
    
    return answer;
}