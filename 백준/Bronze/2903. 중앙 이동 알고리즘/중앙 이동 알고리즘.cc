#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int dot = 2;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		dot = dot * 2 - 1;
	}

	cout << dot * dot << '\n';
}

