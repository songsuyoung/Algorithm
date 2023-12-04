#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int recursive(int N, vector<int> friends[], bool isVisited[],int idx)
{

	//1���� ���� �ʺ�켱Ž������ �ؾ���

	queue<pair<int,int>> q;
	q.push(make_pair(idx,0));

	int cnt = 0;
	while (!q.empty())
	{
		pair<int,int> fri = q.front();

		q.pop();

		if (isVisited[fri.first]) continue;

		isVisited[fri.first] = true;
		//�θ� 1�϶����� �ڱ��ڽ��� ģ���� �� �� ���� ������ üũ���� �ʴ´�.
		if(fri.first!=1)
			cnt++;

		//(1)�� ��Ʈ�� ������ ��, ������ �ڽ� 1���� �˻��Ѵ�.
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

		//����� �׷���
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	bool isVisited[501] = {};

	cout << recursive(N, friends, isVisited,1) << '\n';

}