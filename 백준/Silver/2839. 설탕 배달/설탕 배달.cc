#include <bits/stdc++.h>
using namespace std;

int answer = 987654321;
vector<bool> visited(5001, false); // N의 최대 범위에 맞춰서

void recursive(int N, int cnt)
{
	if (N < 0)
		return;

	if (N == 0)
	{
		answer = min(answer, cnt);
		return;
	}

	if (visited[N]) return; // 이미 본 N은 다시 안봄
	visited[N] = true;

	recursive(N - 5, cnt + 1);
	recursive(N - 3, cnt + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	recursive(N, 0);	
	
	if (answer == 987654321) cout << -1 << '\n';
	else cout << answer << '\n';
	return 0;
}

/*
18 - (5*3) => 3
*/