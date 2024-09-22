#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
    bool isBreak;
    int row;
    int col;
};

int bfs(vector<string>& arr, int R, int C)
{
    vector<vector<vector<bool>>> isVisited(2, vector<vector<bool>>(R, vector<bool>(C, false)));
    
    queue<pair<Pos, int>> q;

    q.push({ {false,0,0},1 });

    int rows[4] = { -1,1,0,0 };
    int cols[4] = { 0,0,-1,1 };
    while (!q.empty())
    {
        Pos cur = q.front().first;
        int cnt = q.front().second;

        q.pop();
        if (isVisited[cur.isBreak][cur.row][cur.col]) continue;
        if (cur.row == (R - 1) && cur.col == (C - 1)) return cnt;

        isVisited[cur.isBreak][cur.row][cur.col] = true;

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.row + rows[i];
            int nc = cur.col + cols[i];

            if (nr < 0 || nc < 0 || nr >= R || nc >= C || isVisited[cur.isBreak][nr][nc]) continue;
            
            if (arr[nr][nc] == '1')
            {
                if (cur.isBreak == false)
                {
                    //벽이고, 부순다. 
                    q.push({ {true,nr,nc},cnt + 1 });
                }

                //이미 벽을 부쉈으면, 가질 못함.
                continue;
            }

            q.push({ {cur.isBreak,nr,nc},cnt + 1 });
        }
    }

    return -1;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int R, C;

    cin >> R >> C;

    vector<string> arr(R);

    for (int i = 0; i < R; i++)
    {
        cin >> arr[i];
    }

    cout<<bfs(arr, R, C);
     
}