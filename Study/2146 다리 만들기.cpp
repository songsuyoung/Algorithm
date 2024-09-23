#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int N,vector<vector<int>>& maps, vector<vector<bool>>& isVisited, int idx, pair<int,int> st,queue<pair<pair<int,int>,int>> &zoneQueue)
{
    queue<pair<int, int>> q;

    q.push(st);

    int rows[4] = { -1,1,0,0 };
    int cols[4] = { 0,0,-1,1 };

    while (!q.empty())
    {
        pair<int, int> cur = q.front();

        q.pop();

        if (isVisited[cur.first][cur.second]) continue;

        isVisited[cur.first][cur.second] = true;
        maps[cur.first][cur.second] = idx;
        zoneQueue.push({ { cur.first,cur.second },0 });
        for (int i = 0; i < 4; i++)
        {
            int nr = cur.first + rows[i];
            int nc = cur.second + cols[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= N || isVisited[nr][nc] || maps[nr][nc] == 0) continue;

            q.push({ nr,nc });
        }
    }
}


int bfs(int N, vector<vector<int>>& zone, queue<pair<pair<int, int>, int>>& q,int idx)
{
    vector<vector<bool>> isVisited(N, vector<bool>(N, 0));

    int rows[4] = { -1,1,0,0 };
    int cols[4] = { 0,0,-1,1 };

    int minCnt = 987654321;

    while (!q.empty())
    {
        pair<int, int> cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (isVisited[cur.first][cur.second]) continue;
        if (zone[cur.first][cur.second] != 0 && zone[cur.first][cur.second] != idx)
        {
            minCnt = min(minCnt, cnt);
            continue;
        }

        isVisited[cur.first][cur.second] = true;

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.first + rows[i];
            int nc = cur.second + cols[i];

            //자기랑 같은 경우에는 안감.
            if (nr < 0 || nc < 0 || nr >= N || nc >= N || isVisited[nr][nc]) continue;

            if (zone[nr][nc] == 0)
            {
                q.push({ { nr,nc },cnt + 1 });
            }
            else
            {
                q.push({ { nr,nc },cnt });
            }
        }
    }

    return minCnt;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    

     //1. 구역을 만든다.
    int N;
    cin >> N;

    vector<vector<int>> maps(N,vector<int>(N,0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> maps[i][j];
        }
    }

    vector<vector<bool>> isVisited(N, vector<bool>(N, 0));

    queue<pair<pair<int, int>,int>> q;

    int idx = 2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maps[i][j] == 0 || isVisited[i][j]) continue;

            bfs(N, maps, isVisited, idx++,make_pair(i,j), q);

            //여기와서
            minVal = min(minVal, bfs(N, maps, q,maps[i][j]));
        }
    }

    cout << minVal << '\n';
}