#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string pattern;
	cin >> pattern;

	int starIdx = pattern.find('*');

	string prefix = pattern.substr(0, starIdx); // 처음까지
	string suffix = pattern.substr(starIdx + 1); //끝까지

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		if (input.size() < (prefix.size() + suffix.size()))
		{
			//작으면, NE
			cout << "NE\n";
			continue;
		}

		//앞, 뒤로 자른다.

		string pre = input.substr(0, prefix.size()); //0부터 prefix 사이즈만큼
		string suf = input.substr(input.size() - suffix.size()); //suffix 사이즈만큼

		if (pre == prefix && suffix == suf)
		{
			cout << "DA\n";
		}
		else
		{
			cout << "NE\n";
		}
	}
}

