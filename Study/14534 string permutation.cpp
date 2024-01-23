#include <bits/stdc++.h>
using namespace std;

void recursive(string input, vector<bool>& isVisited, string output)
{
	if (input.length() == output.length())
	{
		cout << output << '\n';
		return;
	}

	for (int i = 0; i < input.length(); i++)
	{
		if (isVisited[i]) continue;
		isVisited[i] = true;
		recursive(input, isVisited, output + input[i]);
		isVisited[i] = false;
	}
}
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		
		cout << "Case # " << i << ":\n";
		vector<bool> isVisited(input.length());
		recursive(input, isVisited,"");
	}
}