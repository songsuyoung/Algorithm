#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<string> croatia = { {"c="},{"c-"},{"dz="},{"d-"},{"lj"},{"nj"},{"s="},{"z="}};

	string input;

	cin >> input;

	for (const auto& ch : croatia)
	{
		int idx = 0;
		while ((idx = input.find(ch, idx)) != string::npos) //idx 위치부터 ch를 찾는다.
		{
			input.replace(idx, ch.size(), "#");  // 크로아피아 단어를 #로 바꾼다.
		}
	}

	cout << input.size() << '\n';

}
