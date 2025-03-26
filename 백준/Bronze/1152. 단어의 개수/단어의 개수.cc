#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;

	getline(cin, input);

	string tmp = "";
	int cnt = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
		{
			if (tmp.size() != 0)
			{
				cnt++;
			}
			tmp = "";
		}
		else
		{
			tmp += input[i];
		}
	}

	if (tmp.size() != 0)
	{
		cnt++;
	}
	cout << cnt << '\n';
}

