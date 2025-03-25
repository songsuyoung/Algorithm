#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	cin >> N;

	string tmp = "";
	while (N > 0)
	{
		int mod = N % 2;
		tmp += mod + '0';
		N /= 2;
	}

	reverse(tmp.begin(), tmp.end());

	cout << tmp << '\n';
}
