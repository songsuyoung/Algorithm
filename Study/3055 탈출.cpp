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
		weight[wr][wc] = min; //weight�� �ֱ�, �� �� �ɸ����� �ְ�, ���� �������� �ð� - ����ġ�� �� �� �ִ� ���� 1���� Ŭ ��쿡�� 
		//�ǳμ� �ֱ� ������ �ǳʰ�(�׷��� INT_MAX�� �ʱ�ȭ����. �� ��쿡 ������ �ǳʰ� �� ������ �ǹ�)
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
	queue<Pos> water; //���� ��� r,c 
	queue<Pos> ani; //�ִϸ�~
	Pos end;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> road[i][j];

			if (road[i][j] == 'S')
			{
				//����ġ ��ġ
				ani.push(Pos(i, j, 0));
			}
			else if (road[i][j] == '*') //���� �������� �����ϴ�.
			{
				//�� ��ġ
				water.push(Pos(i, j, 0));
			}
		}
	}

	bfs(R, C, road, ani, water, isVisited);
}