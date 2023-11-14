#include <iostream>
#include <queue>
using namespace std;
/*
1.가장 처음에 봄버맨은 일부 칸에 폭탄을 설치해 놓는다. 모든 폭탄이 설치된 시간은 같다.
2.다음 1초 동안 봄버맨은 아무것도 하지 않는다.

while
3.다음 1초 동안 폭탄이 설치되어 있지 않은 모든 칸에 폭탄을 설치한다. 즉, 모든 칸은 폭탄을 가지고 있게 된다. 폭탄은 모두 동시에 설치했다고 가정한다.
4.1초가 지난 후에 3초 전에 설치된 폭탄이 모두 폭발한다.

3과 4를 반복한다.
*/
class Pos
{
public:
	int _sec;
	pair<int, int> _pos;

	Pos(pair<int, int> pos, int sec) : _pos(pos), _sec(sec){}
};

void print(int R,int C, int arr[][202])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 0) cout << '.';
			else cout << 'O';
		}
		cout << '\n';
	}
}


int main()
{
	//봄버맨은 일부 칸에 폭탄 설치 ( 모든 폭탄 설치 시간 == 3)
	//다음 1초 동안 봄버맨은 아무것도 하지않는다. => 2초

	//즉 처음 시작은 폭탄 설치 시간 2초, sec=1초 에서 시작한다.
	int R, C, N;
	cin >> R >> C >> N;

	int arr[202][202] = {};
	//queue<Pos> q;
	for (int i = 0; i < R; i++)
	{
		char tmp;
		for (int j = 0; j < C; j++)
		{
			cin >> tmp;

			if (tmp == 'O')
			{
				arr[i][j] = 2; //3초 설치
			}
		}
	}

	int sec = 1;

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	queue<pair<int, int>> q;
	while (sec < N)
	{
		//폭탄 전부 설치
		sec++;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j] == 0)
					arr[i][j] = 3; //폭탄은 3초
				else
					arr[i][j] -= 1;
			}
		}

		//print(R, C, arr);
		if (sec == N) break;
		//폭탄 1씩 줄어든다.
		sec++;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				//3초가 아닌 (3초는 현재 놓은 폭탄이기 때문에 배제)
				arr[i][j] -= 1; //1씩 죽인다.
				if (arr[i][j] <= 0) {
					q.push(make_pair(i, j));
				}
			}
		}

		while (!q.empty())
		{
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			arr[i][j] = 0;

			for (int k = 0; k < 4; k++)
			{
				int nextR = i + rows[k];
				int nextC = j + cols[k];
				if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C || arr[nextR][nextC] == 0) continue;

				arr[nextR][nextC] = 0;
			}
		}
		//print(R, C, arr);
	}

	print(R, C, arr);

}
