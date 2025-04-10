#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> arr(n+1, vector<int>(n+1,0));
    
    for(int i=0; i<results.size(); i++)
    {
        arr[results[i][0]][results[i][1]] = 1; //항상 이김
    }
    
    //1부터 5까지 갈 수 있는 거리를 더해준다.
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (arr[i][k] == 1&& arr[k][j] == 1)
                {
                    arr[i][j] = 1;
                }
            }   
        }   
    }
    
    for (int i = 1; i <= n; i++) 
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 || arr[j][i] == 1)
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}

/*
n명의 권투선수가 권투 대회에 참여 1,n번까지의 번호를 받았음.
만약 A선수가 B 선수보다 실력이 좋다면, A선수는 B선수를 항상 이깁니다.

예)

5명
4-> 항상 3을 이김
4 -> 항상 2를 이김
3 -> 항상 2를 이김
1 -> 항상 2를 이김
2 -> 항상 5를 이김


  1 2 3 4 5
1 1 1
2   4     1
3   1 1
4   1 1 1
5         5

자기 자신 포함 => 4이라는 수를 가짐.
5는 => 2의 수가 4 이기 때문에 자기 자신을 포함해서 5가 된다.
1 1 => 1
2 2 => 1
.. 플로이드 워샬 알고리즘 => 갈 수 있는 모든 경로를 +1 해서 가능 방법
*/