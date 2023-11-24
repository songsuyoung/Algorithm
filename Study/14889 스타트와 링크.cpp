#include <iostream>
using namespace std;


int recursive(int N, int arr[][22], bool isVisited[], int r, int selected)
{
    if (r >= N) return 0;
    if (selected == (N / 2))
    {
        //다골랐음 두 팀 사이의 능력치 전달에 대한 완탐 진행
        int start = 0;
        int link = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (isVisited[i] && isVisited[j])
                {
                    start += arr[i][j] + arr[j][i];
                }
                else if(isVisited[i]==false &&isVisited[j]==false){
                    link += arr[i][j] + arr[i][j];
                }
            }
        }
        return abs(start-link);
    }
    int minVal = INT_MAX;
    for (int i = r; i < N; i++)
    {
        if (isVisited[i]) continue;
        isVisited[i] = true;
        minVal = min(minVal, recursive(N, arr, isVisited, i, selected + 1));
        isVisited[i] = false;
    }

    return minVal;
}
int main()
{
    int arr[22][22] = {};
    bool isVisited[22] = {};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    cout << recursive(N, arr, isVisited, 0, 0);
}