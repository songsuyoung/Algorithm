#include <bits/stdc++.h>
using namespace std;

int recursive(int N, vector<vector<int>>& arr, vector<bool>& isVisited, int selected, int idx)
{
    if (N/2 <= selected)
    {
        int sum=0, sum1 = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (isVisited[i] && isVisited[j])
                {
                    sum+=arr[i][j] + arr[j][i];
                }
                
                if (!isVisited[i] && !isVisited[j])
                {
                    sum1+=arr[i][j] + arr[j][i];
                }
            }
        }
        return abs(sum1 - sum);
    }
    
    int answer = INT_MAX;
    
    for (int i = idx; i < N; i++)
    {
        if(isVisited[i]) continue;
		isVisited[i] = true;
        answer = min(answer, recursive(N, arr, isVisited, selected+1, i+1));
        isVisited[i] = false;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    vector<vector<int>> arr(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<bool> isVisited(N, 0);
    
    //조합 생각했을 때 8C4 를 의미함 즉, {0,1,2,3} vs {4,5,6,7} 이나 똑같은 선택.
    isVisited[0] = true; //중복 제거에 매우 탁월
    cout<<recursive(N, arr, isVisited, 1, 1)<<'\n';
}

/*
중복 수열 XXX => 조합/중복X

스타트팀의 능력치, 링크팀의 능력치 차가 최소를 가져야 한다.
*/
