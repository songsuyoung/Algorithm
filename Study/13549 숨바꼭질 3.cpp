#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int N, int K)
{
    queue<pair<int, int>> q;

    int minCnt = 987654321;
    q.push({ N,0 });
    bool isVisited[200005] = { false };

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;

        q.pop();

        if (isVisited[cur]) continue;

        if (cur == K)
        {
            return cnt;
        }

        isVisited[cur] = true;

        if (cur * 2 <= 100000)
        {
            q.push({ cur * 2,cnt });
        }

        if (cur - 1 >= 0)
        {
            q.push({ cur - 1,cnt + 1 });
        }

        if (cur + 1 <= 100000)
        {
            q.push({ cur + 1,cnt + 1 });
        }

    }
    
    return -1;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //while (true)
    {
        int N, K;
        cin >> N >> K;

        if (N == K)
            cout << 0 << '\n';
        else
            cout << bfs(N, K)<<'\n';

    }
   
}