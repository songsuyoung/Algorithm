#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int rows[4] = { -1, 0, 1, 0 };
int cols[4] = { 0, -1, 0, 1 };

vector<vector<vector<int>>> dir = { {{0}, {1}, {2}, {3}}, {{1, 3}, {0, 2}}, {{0, 3}, {2, 3}, {1, 2}, {0, 1}}, {{0, 1, 3}, {0, 2, 3}, {1, 2, 3}, {0, 1, 2}}, {{0, 1, 2, 3}} };

int recursive(vector<vector<int>>& arr, vector<vector<int>>& isVisited, int row, int col)
{
    if (row == arr.size())
    {
        return 0;
    }

    int cnt = 0, res = 0;

    if (arr[row][col] >= 1 && arr[row][col] < 6)
    {
        int idx = arr[row][col] - 1;
        for (int k = 0; k < dir[idx].size(); k++)
        {
            queue<pair<int, int>> q;
            for (int l = 0; l < dir[idx][k].size(); l++)
            {
                int nextR = row;
                int nextC = col;
                while (true)
                {
                    nextR += rows[dir[idx][k][l]];
                    nextC += cols[dir[idx][k][l]];
                    if (nextR < 0 || nextC < 0 || nextR >= arr.size() || nextC >= arr[0].size() || arr[nextR][nextC] == 6)
                        break;
                    if (isVisited[nextR][nextC] || arr[nextR][nextC] != 0)
                        continue;

                    q.push(make_pair(nextR, nextC));
                    isVisited[nextR][nextC] = 1;
                    cnt += 1;
                }
            }

            if (col + 1 >= arr[0].size())
            {
                res = max(res, recursive(arr, isVisited, row + 1, 0) + cnt);
            }
            else
            {
                res = max(res, recursive(arr, isVisited, row, col + 1) + cnt);
            }

            while (!q.empty())
            {
                int nextR = q.front().first;
                int nextC = q.front().second;
                q.pop();
                isVisited[nextR][nextC] = 0;
                cnt -= 1;
            }
        }
    }
    else
    {
        if (col + 1 >= arr[0].size())
        {
            res = max(res, recursive(arr, isVisited, row + 1, 0) + cnt);
        }
        else
        {
            res = max(res, recursive(arr, isVisited, row, col + 1) + cnt);
        }
    }

    return res;
}
int main()
{

    int row, col;
    cin >> row >> col;

    vector<vector<int>> arr(row, vector<int>(col, 0));

    int zeroCnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 0)
                zeroCnt++;
        }
    }
    vector<vector<int>> isVisited(row, vector<int>(col, 0));
    cout << zeroCnt - recursive(arr, isVisited, 0, 0) << '\n';
}