#include <iostream>
#include <vector>

using namespace std;

int cal(int N, int L, vector<int> &arr)
{
    vector<bool> isVisited(N,false);

    int sum = 0;
    for (int j = 0; j < N - 1; j++)
    {
        if (abs(arr[j] - arr[j + 1]) > 1)
            break;

        if (arr[j] > arr[j + 1])
        {
            // 오른쪽으로 L칸 본다
            int cnt = 0;
            for (int k = 0; k < L; k++)
            {
                if ((j + 1 + k) > N)
                    break;
                if (arr[j + 1] == arr[j + 1 + k])
                {
                    cnt++;
                }
            }

            if (cnt != L)
            {
                break;
            }

            for (int k = 0; k < L; k++)
            {
                isVisited[j+k+1]=true;
            }
        }
        else if ((arr[j] - arr[j + 1]) == -1) // 왼쪽
        {
            int cnt = 0;
            for (int k = 0; k < L; k++)
            {
                if ((j - k) < 0 || isVisited[j-k])
                    break;
                if (arr[j] == arr[j - k])
                {
                    cnt++;
                }
            }

            if (cnt != L)
            {
                break;
            }

            for (int k = 0; k < L; k++)
            {
                isVisited[j-k]=true;
            }
        }

        if ((N - 2) == j)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    int N, L;
    cin >> N >> L;

    vector<vector<int>> rows(N, vector<int>(N));
    vector<vector<int>> cols(N, vector<int>(N));
    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> rows[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cols[i][j] = rows[j][i];
        }
    }


    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum+=cal(N,L,rows[i]);
        sum+=cal(N,L,cols[i]);
    }

    cout << sum << '\n';
}