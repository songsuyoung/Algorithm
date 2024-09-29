#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
    int row;
    int col;
    int K;
    int cnt;
};

int bfs(int R,int C, int K,vector<string> & input)
{
    vector<vector<vector<bool>>> isVisited(K+1, vector<vector<bool>>(R, vector<bool>(C, false)));
    int rows[4] = { -1,1,0,0 };
    int cols[4] = { 0,0,-1,1 };

    queue<Pos> q;

    q.push({ 0,0,K,1 });

    while (!q.empty())
    {
        Pos cur = q.front();

        q.pop();
        if (isVisited[cur.K][cur.row][cur.col]) continue;
        if ((cur.row == R - 1) && (cur.col == C - 1))
        {
            return cur.cnt;
        }
        isVisited[cur.K][cur.row][cur.col] = true;
        for (int i = 0; i < 4; i++)
        {
            int nr = cur.row + rows[i];
            int nc = cur.col + cols[i];

            if (nr < 0 || nc < 0 || nr >= R || nc >= C || isVisited[cur.K][nr][nc]) continue;

            if (input[nr][nc] == '1')
            {
                if (cur.K > 0)
                {
                    q.push({ nr,nc,cur.K - 1,cur.cnt + 1 });
                }
                continue;
            }

            q.push({ nr,nc,cur.K,cur.cnt + 1 });
            
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R, C, K;

    cin >> R >> C >> K;

    vector<string> input(R);

    for (int i = 0; i < R; i++)
    {
        cin >> input[i];
    }

    cout << bfs(R, C, K, input);
}