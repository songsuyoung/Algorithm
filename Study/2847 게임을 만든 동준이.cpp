#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> scores(N,0);

	for (int i = 0; i < N; i++)
	{
		cin >> scores[i];
	}
	int answer = 0;

	for (int i = N - 1; i > 0; i--)
	{
		if (scores[i] <= scores[i - 1])
		{
			int dis=abs(scores[i - 1] - (scores[i]-1));
			scores[i - 1] = scores[i - 1] - dis;
			answer += dis;
		}
	}
	cout << answer << '\n';
}