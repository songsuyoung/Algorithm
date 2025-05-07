#include <bits/stdc++.h>
using namespace std;

int answer = INT_MAX;
void recursive(int N, vector<int>& v, int idx)
{
	if (idx == N + 1) {
		int sum = 0;
		for (int i = 1; i <= (1 << (N - 1)); i *= 2) {
			int cnt = 0;
			for (int j = 1; j <= N; j++)
			{
				if (v[j] & i)cnt++;
			}
			sum += min(cnt, N - cnt);
		}
		answer = min(answer, sum);
		return;
	}
	recursive(N, v, idx + 1);
	v[idx] = ~v[idx];
	recursive(N, v, idx + 1);

}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	vector<int> v(44, 0);
	for (int i = 1; i <= N; i++)
	{
		string input;
		cin>>input;

		for (int j = 0; j < input.size(); j++)
		{
			if (input[j] == 'T')
			{
				v[i] |= 1<<j;
			}
		}
	}


	recursive(N, v, 1);

	cout<<answer<<'\n';

	return 0;
}
