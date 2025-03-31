#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, B;

	cin >> N >> B;

	string output = "";
	while (N > 0)
	{
		int num = N % B;

		if (num >= 10)
		{
			num = 'A' + (num-10);
		}
		else
		{
			num = '0' + num;
		}

		output += num;
		N /= B;
	}

	reverse(output.begin(), output.end());
	cout<<output<<'\n';
}

/*
B진법 수 N이 주어짐. =>10진수로 바꿔라

*/
