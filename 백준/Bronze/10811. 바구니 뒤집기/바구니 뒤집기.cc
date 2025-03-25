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
		
		for (int j = 0; j < (ed-st)/2 + 1; j++)
		{
			swap(counting[st + j], counting[ed - j]);
		}
	}


	for (int i = 1; i <= N; i++)
	{
		cout << counting[i] << ' ';
	}
}

