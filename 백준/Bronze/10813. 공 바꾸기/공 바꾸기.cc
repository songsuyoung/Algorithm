#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> counting(N+1, 0);
	
	for (int i = 1; i <= N; i++)
	{
		counting[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int st;
		int ed;

		cin >> st >> ed;

		int tmp = counting[st];
		counting[st] = counting[ed];
		counting[ed] = tmp;
	}


	for (int i = 1; i <= N; i++)
	{
		cout << counting[i] << ' ';
	}
}

