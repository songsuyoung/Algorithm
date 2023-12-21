#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Pos
{
public:

	bool operator()(Pos& self, Pos& other)
	{
		if (self.cnt == other.cnt)
		{
			if (self.pos.first == other.pos.first)
				return self.pos.second > other.pos.second;

			return self.pos.first > other.pos.first;
		}
		return self.cnt < other.cnt;
	}

	pair<int, int> pos;
	int cnt;
	Pos() {}
	Pos(pair<int, int> p, int c) : pos(p), cnt(c) {}
};

void adjacent(int N, vector<vector<int>> &output,vector<int> friends,queue<pair<int,int>> &q) 
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	vector<vector<int>> board(N,vector<int>(N,0));
	int maxCnt = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c <N; c++)
		{
			int cnt = 0;
			if (output[r][c] != 0)
			{
				board[r][c] = -1;
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int nextR = r + rows[i];
				int nextC = c + cols[i];

				if (nextR >=N || nextC >= N || nextR < 0 || nextC < 0) continue;
				
				for (int j = 0; j < friends.size(); j++)
				{
					if (output[nextR][nextC] == friends[j])
						cnt++;
				}
			}
			board[r][c] = cnt;
			maxCnt=max(maxCnt, cnt);
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == -1 ) continue;

			if (maxCnt == board[i][j])
			{
				q.push(make_pair(i, j));
			}
		}
	}
}
pair<int,int> emptySelected(int N,queue<pair<int, int>>& q,vector<vector<int>> &board)
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	vector<vector<int>> tmp(N,vector<int>(N,0));
	int maxCnt = 0;

	priority_queue<Pos, vector<Pos>, Pos> order;
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();

		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int nextR = pos.first + rows[i];
			int nextC = pos.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N || board[nextR][nextC] != 0) continue;
			cnt++;
		}

		maxCnt=max(maxCnt, cnt);
		tmp[pos.first][pos.second] = cnt;

		order.push(Pos(pos, cnt));
	}
	return order.top().pos;
}

int calculate(int N,vector<vector<int>> &output,vector<vector<int>> &friends)
{
	int statisfaction[5] = { 0,1,10,100,1000 };
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	long long sum = 0;

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			int cnt = 0;
			int curpos = output[r][c];
			for (int i = 0; i < 4; i++)
			{
				int nextR = r + rows[i];
				int nextC = c + cols[i];

				if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;

				for (int j = 0; j < friends[curpos].size(); j++)
				{
					if (output[nextR][nextC] == friends[curpos][j])
						cnt++;
				}
			}
			sum += statisfaction[cnt % 6];
		}
	}

	return sum;

}
int main()
{

	int N;
	cin >> N;


	vector<vector<int>> friends(N*N+1);
	vector<int> orders;
	for (int i = 1; i <= N * N; i++)
	{
		int me;
		cin >> me;
		orders.push_back(me);
		for (int j = 0; j < 4; j++)
		{
			int f;
			cin >> f;

			friends[me].push_back(f);
		}
	}
	vector<vector<int>> output(N, vector<int>(N, 0));
	for (int i = 0; i <orders.size(); i++)
	{
		queue<pair<int, int>> q;
		//비어있는 칸 중 좋아하는 학생이 몇명인지 계산하는 함수 -> 결과값 전달 및 최대 개수 전달
		adjacent(N, output, friends[orders[i]], q);
		//최대 값과 일치하면 비어있는칸이 가장 많은 칸으로 자리 선정 -> 결과값 전달 : 비어있는 개수 전달, 비어있는 최대 개수
		//비어있는 칸도 여러개면 행번호, 열번호 작은 칸으로 -> 가장 먼저 만나는 비어있는 곳 삽입 -> priority_queue 사용
		pair<int, int> res = emptySelected(N, q, output);

		output[res.first][res.second] = orders[i];

	}

	cout << calculate(N,output,friends) << '\n';
	
}