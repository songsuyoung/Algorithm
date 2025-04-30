#include <bits/stdc++.h>
using namespace std;

int Jump(int R, int C, vector<string>& board, pair<int, int> junan)
{
	int rows[] = { -1,1,0,0 };
	int cols[] = { 0,0,-1,1 };

	vector<vector<bool>> isVisited(305, vector<bool>(305, false));
	queue<pair<int, int>> q;

	q.push(junan);

	vector<string> tmp = board;
	int answer = 0;
	while (!q.empty())
	{
		queue<pair<int,int>> tmp = q;

		answer++;

		while (!tmp.empty())
		{
			pair<int,int> cur = tmp.front();
			tmp.pop();

			if(isVisited[cur.first][cur.second]) continue;

			if (board[cur.first][cur.second] == '#')
			{
				return answer;
			}
			isVisited[cur.first][cur.second] = true;

			for (int i = 0; i < 4; i++)
			{
				int nextR = rows[i] + cur.first;
				int nextC = cols[i] + cur.second;

				if(nextR<0||nextC<0||nextR>=R||nextC>=C||isVisited[nextR][nextC]) continue;

				if (board[nextR][nextC] != '1')
				{
					tmp.push({nextR,nextC});
				}
				else
				{
					q.push({nextR, nextC});
				}
			}
		}
	}


	return -1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	cin>>N>>M;

	vector<string> board(N);

	pair<int,int> junan;
	pair<int,int> target;

	cin>>junan.first>>junan.second;
	cin>>target.first>>target.second;

	//1씩 감소시켜야한다.
	junan.first -= 1;
	junan.second -= 1;
	target.first -= 1;
	target.second -= 1;

	for (int i = 0; i < N; i++)
	{
		cin>>board[i];
	}

	cout<<Jump(N,M,board,junan)<<'\n';

}
