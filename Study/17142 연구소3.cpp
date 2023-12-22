#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
class Pos
{
public:
	Pos(pair<int,int> p,int c) : pos(p),cnt(c){}
	pair<int, int> pos;
	int cnt;
};
int bfs(int total,vector<vector<int>> &board,queue<Pos> &q)
{

	int rows[4] = { -1, 1, 0, 0 };
	int cols[4] = { 0, 0, -1, 1 };
	int size = board.size();
	vector<vector<bool>> isVisited(size, vector<bool>(size, false));

	while (!q.empty())
	{
		pair<int, int> p = q.front().pos;
		int cnt = q.front().cnt;
		q.pop();
		
		if (isVisited[p.first][p.second]) continue;
		
		isVisited[p.first][p.second] = true;
        if(board[p.first][p.second]!=-1)
		    total--;
		if (total <= 0) return cnt;

		for (int i = 0; i < 4; i++)
		{
			int nextR = p.first + rows[i];
			int nextC = p.second + cols[i];

			if (nextR < 0 || nextC < 0 || nextR >= size || nextC >= size || board[nextR][nextC] == 1) continue;

			q.push(Pos(make_pair(nextR, nextC), cnt + 1));
		}
	}

	return -1;
}
int recursive(int M,int total,vector<vector<int>>& board, vector<pair<int,int>>& birus, vector<bool>& isVisited, int idx,int selected)
{
	if (selected >= M)
	{
		queue<Pos> q;
		for (int i = 0; i < birus.size(); i++)
			if (isVisited[i])
				q.push(Pos(birus[i],0));
            else
            {
                board[birus[i].first][birus[i].second]=-1;
            }
		//다고름
		int cnt=bfs(total,board,q);
        for (int i = 0; i < birus.size(); i++)
			if (isVisited[i]==false)
			    board[birus[i].first][birus[i].second]=2;

		return cnt;
	}
	int res = INT_MAX;
	for (int i = idx; i < birus.size(); i++)
	{
		if (isVisited[i]) continue;
		isVisited[i] = true;
		int tmp=min(res,recursive(M, total,board, birus, isVisited, i,selected+1));
		isVisited[i] = false;
		if (res != -1 && tmp == -1) continue;
		res = tmp;
	}
	return res;
}
int main()
{
	int N,M;
	cin >> N >> M;
	vector<vector<int>> board(N,vector<int>(N,0));
	vector<pair<int, int>> birus;
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 2)
			{
				birus.push_back(make_pair(i, j));
			}
			if (board[i][j] == 1 || board[i][j]== 2) continue;
			cnt++;
		}
	}
    cnt+=M;
	vector<bool> isVisited(birus.size(), false);

	//바이러스 고른다.
	int answer=recursive(M,cnt,board, birus, isVisited, 0,0);
	if (answer == INT_MAX)
		cout << -1 << '\n';
	else
		cout << answer << '\n';
}