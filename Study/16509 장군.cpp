#include <iostream>
#include <queue>
using namespace std;

class Pos
{
public:
	pair<int, int> _pos;
	int _cnt;

	Pos(pair<int,int> pos,int cnt):_pos(pos),_cnt(cnt){}
};
int bfs(pair<int, int>& start, pair<int, int>& dest)
{

	queue<Pos> q;

	//상하 좌우
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	int nextRows[4][4] = { {-1,-1,-2,-2},{1,1,2,2},{1,-1,2,-2},{1,-1,2,-2} };
	int nextCols[4][4] = { {1,-1,2,-2},{1,-1,2,-2},{-1,-1,-2,-2},{1,1,2,2} };
	
	bool isVisited[10][9] = {};
	int R = 10, C = 9;
	q.push(Pos(start, 0));
	while (!q.empty())
	{
		pair<int, int> cur = q.front()._pos;
		int cnt = q.front()._cnt;

		q.pop();
		if (isVisited[cur.first][cur.second]) continue;

		if (cur == dest)
		{
			return cnt;
		}
		isVisited[cur.first][cur.second] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextR = cur.first + rows[i];
			int nextC = cur.second + cols[i];

			if (nextR >= R || nextC >= C || nextR < 0 || nextC < 0) continue;

			for (int j = 0; j < 4; j++)
			{
				int nextRR = nextR + nextRows[i][j];
				int nextCC = nextC + nextCols[i][j];

				if (nextRR >= R || nextCC >= C || nextCC < 0 || nextRR < 0) continue;
				if ((j < 2 && nextRR == dest.first && nextCC == dest.second)) break;
				if (j >= 2)
				{
					q.push(Pos(make_pair(nextRR, nextCC), cnt + 1));
				}
			}
		}

	}

	return -1;
}
int main()
{

	//호근이 놈이 동아리방에 있는 장기를 할 예정
	//상이 왕 위치까지 가는 최소 비용 구하기 문제
	// 상은 상,하,좌,우,대각선 두칸 이동이 가능함

	pair<int, int> pos, king;

	cin >> pos.first >> pos.second;
	cin >> king.first >> king.second;

	cout << bfs(pos, king);
}