#include <bits/stdc++.h>
using namespace std;

bool isChecking(int N, vector<vector<bool>>& board, int &r, int &c)
{
	//선택한 다음 행을 선택하기 때문에, 행에서는 같은 행이 있지않는다.
	int rows[] = {-1,-1,-1};
	int cols[] = {1,0,-1};

	//8방향 N까지 갔을 때 겹치는 게 없어야함. => 행은 확인안해도 된다.
	//위만 확인하면 된다. 생각해보니까 아래는 아직 놓지도 않았음.
	for (int i = 0; i < 3; i++)
	{
		int nextR = r;
		int nextC = c;
		//현재 위치까지만 검사하면 되기 때문에 R까지만 확인하면 된다.
		for (int j = 0; j < r; j++)
		{
			nextR += rows[i];
			nextC += cols[i];

			if(nextR<0||nextC<0||nextR>=N||nextC>=N) break;

			if (board[nextR][nextC])
			{
				return false;
			}
		}
	}

	return true;
}

vector<bool> isColume(20,0);
int recursive(int N, int selected, vector<vector<bool>>& board, int r)
{
	if (selected <= 0)
	{
		return 1;
	}

	if (r >= N)
	{
		return 0;
	}

	int res = 0;
	//중복을 없애기 위해서 r, c을 넘겨야함.
	for (int j = 0; j < N; j++)
	{	
		//이전에 갔던 칼럼값은 방문하지 않는다. (이유 : 위에 같은 칼럼을 가짐)
		if(isColume[j]) continue;

		//놓을 수 있는지 확인한다.
		if (isChecking(N, board, r, j))
		{
			isColume[j] = true;
			//놓는다.
			board[r][j] = 1; //판에 퀸을 놓는다.
			res += recursive(N, selected - 1, board, r + 1); //한 행에 한 줄만 넣는다. 
			board[r][j] = 0; //해제한다.

			isColume[j] = false;
		}
		else
		{
			//다음으로 넘어간다.
			continue;
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<bool>> board(N, vector<bool>(N, 0)); //퀸을 놓을 수 있는 판.
	cout<<recursive(N, N, board, 0)<<'\n';
}

/*
N퀸의 특징

1. 한 행에 하나만 놓을 수 있다. 
	- 퀸 자체가 상하좌우대각선에서 겹치지 않아야하기 때문이다.
2. 한 열에 대해 하나만 놓을 수 있다.
	- 퀸 자체가 상하좌우대각선에서 겹치지 않아야 하기 때문에, 같은 열을 가지면 상에서 만남.
2. 놓기 전에 놓을 수 있는지를 확인해야 한다.
3. 마지막에 도달하는 순간은 항상 참이다.
*/