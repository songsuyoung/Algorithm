#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool isAFriendOfDasom(vector<string> &stu, vector<int>& tmp)
{
    int cnt = 0;

    for (int i = 0; i < tmp.size(); i++)
    {
        int row = tmp[i] / 5;
        int col = tmp[i] % 5;

        if (stu[row][col] == 'S')
        {
            cnt++;
        }
    }

    return cnt >= 4;
}

bool IsAdjacentPosition(vector<int>& tmp)
{
    int cnt = 0;

    queue<int> q;

    q.push(tmp[0]);

    vector<bool> isVisited(25, false);
    int rows[4] = { -1,1,0,0 };
    int cols[4] = { 0,0,-1,1 };

    while (!q.empty())
    {
        int cur = q.front();

        q.pop();
        if (isVisited[cur]) continue;
        cnt++;
        isVisited[cur] = true;

        for (int i = 0; i < 4; i++)
        {
            int nr = rows[i] + (cur / 5);
            int nc = cols[i] + (cur % 5);
            int next = nr * 5 + nc;
            if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5 || isVisited[next]) continue;

            if (find(tmp.begin(), tmp.end(), next) != tmp.end())
            {
                q.push(next);
            }
        }
    }
    return cnt >= 7;
}

int recursive(vector<string>& stu,vector<int>& arr, vector<int> &tmp, int idx)
{
    if (7 == tmp.size())
    {
        if (isAFriendOfDasom(stu, tmp))
        {
            if (IsAdjacentPosition(tmp))
            {
                return 1;
            }
        }
     
        return 0;
    }

    int res = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        tmp.push_back(arr[i]);
        res+=recursive(stu,arr, tmp, i + 1);
        tmp.pop_back();
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> stu(5);

    for (int i = 0; i < 5; i++)
    {
        cin >> stu[i];
    }

    vector<int> arr(25, 0);

    for (int i = 0; i < 25; i++)
    {
        arr[i] = i;
    }

    vector<int> tmp;
    //조합을 뽑는다.
    cout<<recursive(stu, arr, tmp, 0);
}