#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Pos
{
public:
	int _r, _c;
	int _min;
	Pos(){}
	Pos(int r,int c,int min):_r(r),_c(c),_min(min){}
};

void bfs(int R,int C,char road[][55],queue<Pos>& ani, queue<Pos>& water, bool isVisited[][55])
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	bool isWater[55][55] = {};
	int weight[55][55] = {};
	
	for (int i = 0; i < 55; i++)
	{
		for (int j = 0; j < 55; j++)
			weight[i][j] = INT_MAX;
	}
	while (!water.empty())
	{
		int wr = water.front()._r;
		int wc = water.front()._c;
		int min = water.front()._min;

		water.pop();
		if (isWater[wr][wc]) continue;

		isWater[wr][wc] = true;
		weight[wr][wc] = min; //weight값 넣기, 몇 분 걸리는지 넣고, 물이 차오르는 시간 - 고슴도치가 갈 수 있는 분이 1보다 클 경우에는 
		//건널수 있기 때문에 건너고(그래서 INT_MAX로 초기화해줌. 이 경우에 언제든 건너갈 수 있음을 의미)
		for (int i = 0; i < 4; i++)
		{
			int nextR = wr + rows[i];
			int nextC = wc + cols[i];
			
			if (nextR > R || nextC > C || nextR <= 0 || nextC <= 0 || road[nextR][nextC] == 'X' || road[nextR][nextC] == 'D') continue;
			
			water.push(Pos(nextR, nextC, min + 1));
		}
	}

	while (!ani.empty())
	{
		int r = ani.front()._r;
		int c = ani.front()._c;
		int min = ani.front()._min;
		ani.pop();

		if (isVisited[r][c]) continue;

		if (road[r][c] == 'D')
		{
			cout << min << '\n';
			return;
		}
		isVisited[r][c] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextR = r + rows[i];
			int nextC = c + cols[i];
			if (nextR > R || nextC > C || nextR <= 0 || nextC <= 0 || road[nextR][nextC] == 'X' || weight[nextR][nextC] - min <= 1) continue;

			ani.push(Pos(nextR, nextC, min + 1));
		}
	}

	cout << "KAKTUS";
	return;
}
int main()
{
	int R, C;
	cin >> R >> C;

	char road[55][55] = {};
	bool isVisited[55][55] = {};
	queue<Pos> water; //물의 경우 r,c 
	queue<Pos> ani; //애니멀~
	Pos end;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> road[i][j];

			if (road[i][j] == 'S')
			{
				//고슴도치 위치
				ani.push(Pos(i, j, 0));
			}
			else if (road[i][j] == '*') //물은 여러개가 가능하다.
			{
				//물 위치
				water.push(Pos(i, j, 0));
			}
		}
	}

	bfs(R, C, road, ani, water, isVisited);
}