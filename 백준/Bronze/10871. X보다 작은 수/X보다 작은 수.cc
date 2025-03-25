#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	//N개, 수열 A, 정수 X
	int N, X;
	
	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp < X)
		{
			cout << tmp << ' ';
		}
	}
}
