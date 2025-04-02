#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int N;
	cin >> N;

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		stack<char> st;

		st.push(input[0]);
		for (int i = 1; i < input.size(); i++)
		{
			
			if (st.empty() == false && st.top() == input[i])
			{
				st.pop();
			}
			else
			{
				st.push(input[i]);
			}
		}

		if (st.size() <= 0)
		{
			answer++;
		}
	}

	cout << answer << '\n';
}
/*

*/