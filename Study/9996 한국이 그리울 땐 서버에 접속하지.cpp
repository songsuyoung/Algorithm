#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimter)
{

	int pos = 0;
	vector<string> v;

	while ((pos = input.find(delimter)) != string::npos)
	{
		string substr = input.substr(0, pos);
		v.push_back(substr);
		input.erase(0, pos + delimter.length());
	}

	v.push_back(input);

	return v;

}
int main()
{
	int N;
	cin >> N;
	string pattern;
	cin >> pattern;

	vector<string> patterns = split(pattern, "*");

	for (int i = 0; i < N; i++) //O(N)
	{
		string input;
		cin >> input;

		int idx = 0,endIdx=0;
		for (int j=0; j < input.length() && idx < patterns[0].length(); j++,idx++) //O(100) =>O(100*100) =>1초 가능
		{
			if (input[j] != patterns[0][idx])
				break;
			endIdx = j;
		}
		
		if (idx != patterns[0].length())
		{
			cout << "NE\n";
			continue;
		}

		idx = patterns[1].length() - 1;
		for (int j = input.length() - 1; j > endIdx && idx >= 0; j--, idx--) //O(100) =>O(100*100) =>1초 가능
		{
			if (input[j] != patterns[1][idx])
				break;
		}

		if (idx >= 0 )
		{
			cout << "NE\n";
			continue;
		}
		cout << "DA\n";
	}
}