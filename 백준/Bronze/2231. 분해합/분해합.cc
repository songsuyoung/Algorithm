#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int answer = 0;

	int K = N;
	while (N >= 1)
	{
		string num = to_string(N);

		int sum = N;
		for (int i = 0; i < num.size(); i++)
		{
			sum += (num[i] - '0');
		}

		if (sum == K)
		{
			answer = N;
		}

		N--;
	}

	cout<<answer<<'\n';

	return 0;
}
