#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	long long cnt = 0;
	for (int i = 0; i < N; i++) //O(100)
	{
		string input;
		cin >> input;

		stack<char> s;

		for (int j = 0; j < input.length(); j++) //O(100,000)
		{
			if(s.empty())
				s.push(input[j]);
			else
			{
				if (s.top() == input[j])
					s.pop();
				else
					s.push(input[j]);
			}
		}
		if (s.empty()) cnt++;
	}

	cout << cnt << '\n';
}