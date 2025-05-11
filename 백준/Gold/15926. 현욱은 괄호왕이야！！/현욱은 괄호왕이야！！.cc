#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	//시작점 저장
	stack<pair<char,int>> st;

	string input;
	cin >> input;

	vector<bool> visited(N, false);

	for (int i = 0; i < input.size(); i++)
	{
		char ch = input[i];

		if (ch == '(')
		{
			st.push({ch,i});
		}
		else
		{
			if (st.empty())
			{
				continue;
			}
			//성공 => 2의 배수
			visited[st.top().second] = true;
			visited[i] = true;

			st.pop();
		}
	}

	int maxVal = 0;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (visited[i])
		{
			maxVal++;
		}
		else
		{
			maxVal = 0;
		}

		answer = max(answer, maxVal);
	}

	cout<<answer<<'\n';

	return 0;
}

/*
(())( => () 쌍으로 한다. stack 으로 해보자
만약 실패하면 스택에 있는걸 다 리셋 후 다시 시작한다.
*/