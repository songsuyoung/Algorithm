#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Pos
{
    int row;
    int col;
    int cnt;
    int K;
};

int bfs(int K, int N, int M,vector<vector<int>>& arr)
{
    int rows[] = { -1,1,0,0,-2,-2,-1,-1,1,1,2,2 };
    int cols[] = { 0,0,-1,1,-1,1,-2,2,-2,2,-1,1 };
    vector<vector<vector<bool>>> isVisited(K+1, vector<vector<bool>>(N, vector<bool>(M, false)));

    queue<Pos> q;

    q.push({ 0,0,0,K });

    while (!q.empty())
    {
        Pos cur = q.front();

        q.pop();

        if (isVisited[cur.K][cur.row][cur.col]) continue;
        if (cur.row == (N - 1) && cur.col == (M - 1)) return cur.cnt;
        isVisited[cur.K][cur.row][cur.col] = true;

        for (int i = 0; i < 12; i++)
        {
            if (i >= 4 && cur.K == 0) continue; //4이상 건너 뛸 수 없음
            int nr = cur.row + rows[i];
            int nc = cur.col + cols[i];
            int k = cur.K;
            if (i >= 4)
            {
                k = k - 1;
            }
            if (nr < 0 || nc < 0 || nr >= N || nc >= M || isVisited[k][nr][nc] || arr[nr][nc] == 1) continue;

            q.push({ nr,nc,cur.cnt+1,k });
        }
    }

    return -1;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int K, R, C;
    cin >> K >> C >> R;

    vector<vector<int>> arr(R, vector<int>(C, 0));

    for(int i=0;i<R;i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << bfs(K, R, C, arr);

    
}