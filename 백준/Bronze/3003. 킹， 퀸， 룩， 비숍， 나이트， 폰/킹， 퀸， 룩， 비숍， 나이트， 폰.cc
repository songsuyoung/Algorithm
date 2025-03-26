#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int success[6] = { 1,1,2,2,2,8 };

	for (int i = 0; i < 6; i++)
	{
		int input;
		cin >> input;

		cout << success[i] - input << ' ';
	}
}
/*
체스판 피스

킹 1, 퀸 1, 룩 2, 비숍 2, 나이트 2개, 폰 8개
*/