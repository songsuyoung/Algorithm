#include <bits/stdc++.h>
using namespace std;

vector<int> position(100'005,-1);
vector<int> isVisited(100'005, 0); //이미 방문 체크
int BFS(int N, int K)
{
	queue<pair<int,int>> q;

	q.push({N, 0});
	isVisited[N] = 1;
	while (!q.empty())
	{

		pair<int,int> cur = q.front();

		q.pop();

		if (cur.first == K)
		{
			return cur.second;
		}

		for (int next : {cur.first - 1, cur.first + 1, cur.first * 2})
		{
			if (next < 0 || next> 100'000 || isVisited[next] > 0) continue;

			position[next] = cur.first; //다음 이동할 값에 현재 값 삽입
			isVisited[next] = isVisited[cur.first] + 1;
			q.push({next, cur.second + 1});
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int res = BFS(N,K);

	cout<<res<<'\n';

	vector<int> answer;

	int cur = K;
	while (cur != -1)
	{
		answer.push_back(cur);
		cur = position[cur];
	}

	//sort(answer.begin(), answer.end());

	for (int i = answer.size()-1; i>=0 ; i--)
	{
		cout<<answer[i]<<' ';
	}
}

/*
현재 위치 - cnt 를 저장


ed 도달 했을 때 

현재 초에 저장된 이전 초 출력
이전 초 이동 =>



예)

18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 
9 18                    5  10      -1


초반에 모든 위치-이전 위치 값을 -1로 리셋

다음으로 이동할 때 현재 Sec 보다, 다음 이동하는 Sec가 작으면
다음 이동하는 Sec = 현재 Sec 저장
*/
