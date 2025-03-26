#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string number;
	cin >> number;

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum += number[i] - '0';
	}

	cout << sum << '\n';
}
