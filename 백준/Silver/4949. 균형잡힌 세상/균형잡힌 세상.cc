#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (true)
	{
		string input;

		getline(cin, input);

		if (input.size() == 1&& input == ".")
		{
			break; //종료조건
		}

		string sub="";
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '(' || input[i] == ')' || input[i] == '[' || input[i] == ']')
			{
				sub+=input[i];
			}
		}

		stack<char> st;
		bool bIsFail = false;

		for (int i = 0; i < sub.size(); i++)
		{
			char ch = sub[i];

			if (ch == '(' || ch == '[') //열려있거나
			{
				st.push(ch);
			}
			else if (ch == ')' || ch == ']') //닫혀있을때
			{
				if (st.empty()) //비어있으면, 실패
				{
					bIsFail = true;
					break;
				}
				
				if ((st.top() == '(' && ch == ')') ||(st.top() == '[' && ch == ']'))
				{
					st.pop();
				}
				else
				{
					bIsFail = true;
					break;
				}
			}
		}

		if (bIsFail == false && st.empty())
		{
			cout << "yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
}

/*
 소괄호, 대괄호 만 판단 => 1대1 매핑 => 스택

*/