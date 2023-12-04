#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int recursive(int N, vector<int> friends[], bool isVisited[],int idx)
{

	//1번에 대한 너비우선탐색으로 해야함

	queue<pair<int,int>> q;
	q.push(make_pair(idx,0));

	int cnt = 0;
	while (!q.empty())
	{
		pair<int,int> fri = q.front();

		q.pop();

		if (isVisited[fri.first]) continue;

		isVisited[fri.first] = true;
		//부모가 1일때에는 자기자신을 친구로 둘 수 없기 때문에 체크하지 않는다.
		if(fri.first!=1)
			cnt++;

		//(1)을 루트로 생각할 때, 밑으로 자식 1개만 검사한다.
		if (fri.second < 2)
		{
			for (int j = 0; j < friends[fri.first].size(); j++)
			{
				q.push(make_pair(friends[fri.first][j], fri.second + 1));
			}
		}
	}

	return cnt;
}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> friends[501];
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		//양방향 그래프
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	bool isVisited[501] = {};

	cout << recursive(N, friends, isVisited,1) << '\n';

}