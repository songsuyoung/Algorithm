#include <iostream>
#include <deque>
#include <queue>
using namespace std;

//연결된 puyo 개수 리턴
int connectedPuyo(vector<vector<char>> &field)
{
	vector<vector<bool>> connected(12, vector<bool>(6, false));
	vector<vector<bool>> isVisited(12, vector<bool>(6, false));
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	deque<pair<int, int>> d;
	int cnt = 0;
	for (int i = 11; i >= 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
		
			char puyoColor = field[i][j];
			int colorCnt = 0;
			while (!q.empty())
			{
				pair<int, int> pos = q.front();
				q.pop();

				if (isVisited[pos.first][pos.second]) continue;
				isVisited[pos.first][pos.second] = true;
				colorCnt++;
				for (int k = 0; k < 4; k++)
				{
					int nextR = pos.first + rows[k];
					int nextC = pos.second + cols[k];
					
					if (nextR < 0 || nextC < 0 || nextR >= 12 || nextC >= 6 || field[nextR][nextC] == '.' || field[nextR][nextC]!= puyoColor) continue;

					q.push(make_pair(nextR, nextC));
					d.push_back(make_pair(nextR, nextC));
				}
			}

			if (colorCnt >= 4)
			{
				cnt++;
				while (!d.empty())
				{
					connected[d.front().first][d.front().second] = true;
					d.pop_front();
				}
			}
			else
			{
				d.clear();
			}
		}
		
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (connected[i][j])
				field[i][j] = '.'; //물방울 터짐
		}
	}
	return cnt;
}
void fallPuyo(vector<vector<char>>& field)
{

	for (int c = 0; c < 6; c++)
	{
		for (int r = 11; r >= 0; r--)
		{
			if (field[r][c] != '.')
			{
				while (r+1 < 12 && field[r+1][c] == '.')
				{
					field[r + 1][c] = field[r][c];
					field[r][c] = '.';
					r = r + 1;
				}
			}
		}
	}

}
int main()
{
	vector<vector<char>> field(12, vector<char>(6, '.'));
	
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> field[i][j];
		}
	}

	//row 시작점11 col 시작점 0

	//뿌요 상하좌우 연결되어있는지 여부 확인 -bfs (연결되어 있을 경우 true로 표현)
	//true 부분을 모두 .으로 변환
	//각 열에 대해 .이 아니면, .를 만날때까지 한칸씩 이동 후 자기 자신 자리는 .으로 변환
	//열이 끝날 때까지 반복
	int answer = 0;
	while (true)
	{
		int res=connectedPuyo(field);
		if (res == 0) break;
		fallPuyo(field);
		answer++;
	}

	cout << answer << '\n';
}