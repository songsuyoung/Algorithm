#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, string term)
{
	int pos = 0;

	vector<string> v;
	while ((pos = str.find(term)) != string::npos)
	{
		string tmp = str.substr(0, pos);
		v.push_back(tmp);
		str.erase(0, pos + term.length());
	}
	v.push_back(str);

	return v;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	string pattern;

	cin >> pattern;

	vector<string> plist = split(pattern,"*");

	for (int i = 0; i<N; i++)
	{
		string input;

		cin >> input;

		string answer = "DA";
		
		int idx = input.find(plist[0]);

		if (idx != 0)
		{
			answer = "NE";
		}
		else
		{
			input.erase(0, idx + plist[0].length());
		}

		if (input.length() < plist[1].length())
		{
			answer = "NE";
		}

		while ((idx = input.find(plist[1])) != string::npos)
		{
			if(answer == "NE") break;
			//끝
			input.erase(0, idx + plist[1].length());
		}
		
		if (idx + plist[1].length() < input.length())
		{
			answer = "NE";
		}

		cout << answer << '\n';
	}
}
