#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void roll(vector<int>& dice, int order)
{
    //2,5을 제외하고 swap
    //3,6 swap 1,3 swap, 4,1 swap, 4,6 swap

    vector<int> tmp(7, 0);
    switch (order)
    {
    case 0:
        
        //down

        tmp[6] = dice[2];
        tmp[2] = dice[1];
        tmp[1] = dice[5];
        tmp[5] = dice[6];

        break;
    case 1:
        //left
        tmp[6] = dice[3];
        tmp[3] = dice[1];
        tmp[1] = dice[4];
        tmp[4] = dice[6];
    
        break;
    case 2:

        //up

        tmp[6] = dice[5];
        tmp[2] = dice[6];
        tmp[5] = dice[1];
        tmp[1] = dice[2];
        break;

    case 3:
        //left

        tmp[6] = dice[4];
        tmp[4] = dice[1];
        tmp[1] = dice[3];
        tmp[3] = dice[6];
        break;
    }

    for (int i = 1; i <= 6; i++)
    {
        if (tmp[i] != 0)
        {
            dice[i] = tmp[i];
        }
    }
}

int cal(int num, int N, int M, vector<vector<int>>& arr, pair<int, int> p)
{
    int sum = 0;

    int rows[4] = { 0,0,1,-1 };
    int cols[4] = { 1,-1,0,0 };

    queue<pair<int, int>> q;
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));
    q.push(p);

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        if (isVisited[pos.first][pos.second]) continue;
        sum += num;
        isVisited[pos.first][pos.second] = true;
        for (int i = 0; i < 4; i++)
        {
            int row = pos.first + rows[i];
            int col = pos.second + cols[i];

            if (row < 0 || col < 0 || row >= N || col >= M || num != arr[row][col] || isVisited[row][col]) continue;

            q.push(make_pair(row, col));
        }
    }

    return sum;
}

void move(int N, int M, int K, vector<vector<int>>& arr, vector<int>& dice)
{

    vector<pair<int, int>> dir =
    {
        {-1,0}, //up
        {0,1}, //right (동)
        {+1,0}, //down
        {0,-1} //left(서)
    };
    //주사위 돌린다.

    int rows[4] = { -1,0,1,0 };
    int cols[4] = { 0,1,0,-1 };

    int cur = 1;
    pair<int, int> pos = { 0,0 };
    int sum = 0;

    for (int i = 0; i < K; i++)
    {
        roll(dice, cur); //돌린다.
        pos.first += rows[cur];
        pos.second += cols[cur];

        if (pos.first < 0 || pos.second < 0 || pos.first >= N || pos.second >= M)
        {
            cur = abs(cur + 2) % 4; //up<->down / left<->right
       
            for (int i = 0; i < 2; i++)
            {
                roll(dice, cur); //돌린다.

                pos.first += rows[cur];
                pos.second += cols[cur];
            }//반대 방향으로 2번 이동

        }
        //점수를 획득한다.
        sum+= cal(arr[pos.first][pos.second], N, M, arr, pos);
        
        //A<B
        if (arr[pos.first][pos.second] > dice[6])
        {
            //반시계방향
            cur -= 1;
            if (cur < 0)
            {
                cur = 3;
            }
        }
        else if (arr[pos.first][pos.second] < dice[6])
        {
            cur += 1;
            if (cur > 3)
            {
                cur = 0;
            }
        }
    }
    //주사위값을 비교
    //A>B 이동 방향 시계방향 회전
    //A<B 반시계 방향 회전
    //A==B 이동방향 변화 없음
    cout << sum << '\n';
}

int main()
{

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> arr(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    //0번 idx는 안건드릴예정
    vector<int> dice = { 0,1,2,3,4,5,6 };

    move(N, M, K, arr, dice);
}