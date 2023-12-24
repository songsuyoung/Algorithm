
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Pos
{
public:
	Pos(pair<int, int> p, int c) : pos(p), cnt(c) { }
	pair<int, int> pos;
	int cnt;
};
//
bool isRedFirst(int dir, pair<int, int> red, pair<int, int> blue)
{
	//갈 수 있는 구간을 먼저 확인하고  ->뚫려있는지 확인
	//레드 인지 블루가 먼저 갈지 정하기

	switch (dir)
	{
	case 0: //북
		return blue.first > red.first && blue.second == red.second;
	case 1: //남
		return blue.first < red.first && blue.second == red.second;
	case 2: //서
		return blue.first == red.first && blue.second > red.second;
	case 3: //동
		return blue.first == red.first && blue.second < red.second;
	}

	return false;

}
/*
			-1,0 (0)
		0,-1(2)	0,1(3)
			1,0 (1)
*/
int bfs(vector<vector<char>>& board, pair<int, int>& red, pair<int, int>& blue)
{

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	queue<Pos> r;
	queue<Pos> b;

	r.push(Pos(red, 0));
	b.push(Pos(blue, 0));

	//blue가 옆인지 
	//red가 옆인지 확인
	while (!r.empty() && !b.empty())
	{
		Pos curR = r.front();
		Pos curB = b.front();
		r.pop();
		b.pop();
		
		if (curR.cnt >= 10||curB.cnt>=10) break;

		for (int i = 0; i < 4; i++)
		{
			/*
			red - blue가 누가 먼저 나가는지 검사
			red 가 먼저 나갈시 blue도 같이 나가면 (두 queue 는 pop)
			red만 나가면 return cnt;
			blue만 나가면 blue 경우의 수 pop
			 */
			if (isRedFirst(i, curR.pos, curB.pos))
			{//red -cur

				int nextRRed = curR.pos.first, nextCRed = curR.pos.second;
				int nextRBlue = curB.pos.first, nextCBlue = curB.pos.second;
				bool isRed = false, isBlue = false;
				{
					int nextR = curR.pos.first + rows[i];
					int nextC = curR.pos.second + cols[i];
				
					while (board[nextR][nextC] != '#')
					{
						nextRRed = nextR;
						nextCRed = nextC;

						//red가 먼저 나가야함.
						if (board[nextRRed][nextCRed] == 'O')
						{
							isRed = true;
							nextRRed = -1;
							nextCRed = -1;
							break;
						}
						nextR += rows[i];
						nextC += cols[i];
					}
					
				}
				{
					int nextR = curB.pos.first + rows[i];
					int nextC = curB.pos.second + cols[i];

					while (board[nextR][nextC] != '#' && (nextR != nextRRed || nextC != nextCRed))
					{
						nextRBlue = nextR;
						nextCBlue = nextC;

						if (board[nextRBlue][nextCBlue] == 'O')
						{
							isBlue = true;
							break;
						}

						nextR += rows[i];
						nextC += cols[i];
					}
				}
				
				if (!isRed && !isBlue)
				{
					r.push(Pos(make_pair(nextRRed, nextCRed), curR.cnt+1));
					b.push(Pos(make_pair(nextRBlue, nextCBlue), curB.cnt+1));
				}
				else if (isRed && !isBlue)
				{
					return 1;
				}
				
			}
			else
			{
				//blue는 먼저 나가면 return -1.
				int nextRBlue = curB.pos.first, nextCBlue = curB.pos.second;
				int nextRRed = curR.pos.first, nextCRed = curR.pos.second;
				{
					bool isFail = false;
					int nextR = curB.pos.first + rows[i];
					int nextC = curB.pos.second + cols[i];

					while (board[nextR][nextC] != '#')
					{
						nextRBlue = nextR;
						nextCBlue = nextC;

						if (board[nextRBlue][nextCBlue] == 'O')
						{
							isFail = true;
							break;
						}
						nextR += rows[i];
						nextC += cols[i];
					}

					if (isFail)
						continue;

					b.push(Pos(make_pair(nextRBlue, nextCBlue), curB.cnt + 1));
				}
				{
					int nextR = curR.pos.first + rows[i];
					int nextC = curR.pos.second + cols[i];
					
					while (board[nextR][nextC] != '#' && (nextR != nextRBlue || nextC != nextCBlue))
					{
						nextRRed = nextR;
						nextCRed = nextC;

						if (board[nextRRed][nextCRed] == 'O')
						{
							return 1;
						}

						nextR += rows[i];
						nextC += cols[i];
					}

					r.push(Pos(make_pair(nextRRed, nextCRed), curR.cnt + 1));
				}
				
			}
		}
	}

	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int R, C;
	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C));
	pair<int, int> redPos;
	pair<int, int> bluePos;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 'R')
				redPos = make_pair(i, j);
			else if (board[i][j] == 'B')
				bluePos = make_pair(i, j);
		}
	}

	cout<<bfs(board, redPos, bluePos)<<'\n';

}
