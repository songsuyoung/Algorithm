#include <bits/stdc++.h>
using namespace std;

bool isVisited[2][500'005];

int BFS(int N, int K)
{
	queue<pair<int, int>> q; // (현재 위치, 현재 시간)

	q.push({ N,0 });
	isVisited[0][N] = 1;

	while (!q.empty())
	{
		int curPos = q.front().first;
		int curTime = q.front().second;
		q.pop();

		// 중요! 누적합으로 K의 위치 갱신
		int newK = K + (curTime * (curTime + 1)) / 2;

		if (newK > 500'000) continue;

		//미리 도착할 때
		if (isVisited[curTime%2][newK])
		{
			return curTime;
		}

		for (int next : {curPos + 1, curPos - 1, curPos * 2})
		{
			if (next < 0 || next > 500'000) continue;
			if (isVisited[(curTime + 1) % 2][next]) continue;

			isVisited[(curTime + 1) % 2][next] = 1;
			q.push({ next, curTime + 1 });
		}
	}

	return -1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	cout << BFS(N, K) << '\n';
}



/*
BFS인데, 수빈이와 동생 모두가 매 초 위치가 바뀜.

수빈이는 다음 위치에 -1/+1/*2/씩 증가하고
동생은 다음 위치 = 현재위치 + 이전 시간 (계속 업데이트)


방문 처리 => 이전 방문 + 1 하도록 함. (시간 초가 누적되어 진다.) => 이를 이용해서 다음 위치 업데이트

*/