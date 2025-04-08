#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin>>input;

		stack<char> st;
		bool bIsFail=false;
		for (int j = 0; j < input.size(); j++)
		{
			char ch = input[j];

			if (ch == '(')
			{
				st.push(ch);
			}
			else
			{
				if (st.empty())
				{
					bIsFail=true;
					break;
				}

				st.pop();
			}
		}

		if (st.empty() == false || bIsFail)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
}

/*
()로 이루어진 문자열
VPS ()=> stack 과 관련된 문제
*/