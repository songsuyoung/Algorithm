#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int recursive(int N, vector<vector<int>>& arr, vector<bool>& isVisited, int selected, int idx)
{
    if (selected <= 0)
    {
        int sum=0, sum1 = 0;
        for (int i = 0; i < N; i++)
        {
            if (isVisited[i])
            {
				for (int j = i + 1; j < N; j++)
				{
					if (isVisited[j])
					{
						sum += arr[i][j] + arr[j][i];
					}
				}
            }
            else
			{
				for (int j = i + 1; j < N; j++)
				{
					if (isVisited[j] == false)
					{
                        sum1 += arr[i][j] + arr[j][i];
					}
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
        answer = min(answer, recursive(N, arr, isVisited, selected-1, i+1));
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
    cout<<recursive(N, arr, isVisited, N/2, 0)<<'\n';
}

/*
중복 수열 XXX => 조합/중복X

스타트팀의 능력치, 링크팀의 능력치 차가 최소를 가져야 한다.
*/
