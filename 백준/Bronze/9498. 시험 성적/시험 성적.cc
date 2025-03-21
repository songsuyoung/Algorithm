#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int score;

	cin >> score;

	string answer = "";
	if (score >= 90)
	{
		answer = "A";
	}
	else if (score >= 80)
	{
		answer = "B";
	}
	else if (score >= 70)
	{
		answer = "C";
	}
	else if (score >= 60)
	{
		answer = "D";
	}
	else
	{
		answer = "F";
	}

	cout << answer << '\n';
}