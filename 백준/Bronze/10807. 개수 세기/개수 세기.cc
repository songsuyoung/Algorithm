#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	cin >> N;

	vector<int> arr(205);

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		arr[tmp+100]++;
	}

	int v;
	cin >> v;

	cout << arr[v+100] << '\n';
}

