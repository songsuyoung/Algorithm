#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_set<string> pikachu = {"pi","ka","chu"};

	string input;
	cin>>input;

	bool bIsSuccess = true;
	string temp = "";
	for (int i = 0; i < input.size(); i++)
	{
		temp+=input[i];

		if (pikachu.find(temp) != pikachu.end())
		{
			temp = "";
		}
	}

	if (temp.empty())
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}