#include <iostream>
#include <queue>
using namespace std;

class Pos
{
public:
    pair<int, int> _pos;
    int _cnt;

    Pos(pair<int, int> p, int cnt) : _pos(p), _cnt(cnt) {}
};

int bfs(int N, pair<int, int> s, pair<int, int> e)
{
    int rows[8] = {-2,-1,-2,-1,2,1,2,1};
    int cols[8] = {-1,-2,1,2,-1,-2,1,2};

    queue<Pos> q;
    q.push(Pos(s, 0));
    bool isVisited[301][301] = {};
    while (!q.empty())
    {
        pair<int, int> pos = q.front()._pos;
        int cnt = q.front()._cnt;

        q.pop();
        if (pos == e)
            return cnt;
        if (isVisited[pos.first][pos.second]) continue;

        isVisited[pos.first][pos.second] = true;

        for (int i = 0; i < 8; i++)
        {
            int nextR = pos.first + rows[i];
            int nextC = pos.second + cols[i];

            if (nextR >= N || nextC >= N || nextR < 0 || nextC < 0 || isVisited[nextR][nextC]) continue;

            q.push(Pos(make_pair(nextR, nextC), cnt + 1));
        }
    }
    return -1;
}
int main()
{
    int T;
    cin >> T;

    pair<int, int> start, end;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        cout << bfs(N, start, end) << '\n';
    }

}
