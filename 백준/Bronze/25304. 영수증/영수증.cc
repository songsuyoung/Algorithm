#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//각 물건의 가격과 개수
	// 총금액을 보고 검사
	int X;
	cin >> X; //총 금액
	int N;
	cin >> N; //물건의 개수

	int total = 0;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		total += (a * b);
	}

	string answer = "No";
	if (total == X)
	{
		answer = "Yes";
	}

	cout << answer << '\n';
}