#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;

	for (int i = 0; i < TC; i++)
	{
		int cnt;
		string input;

		cin >> cnt >> input;
		
		string output = "";
		for (int k = 0; k < input.size(); k++)
		{
			for (int j = 0; j < cnt; j++)
			{
				output += input[k];
			}
		}

		cout << output << '\n';
	}
}

