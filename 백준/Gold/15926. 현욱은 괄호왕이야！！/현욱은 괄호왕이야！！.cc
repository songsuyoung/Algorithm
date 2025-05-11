#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	//시작점 저장
	stack<int> st;

	string input;
	cin >> input;

	//vector<bool> bits(N, false);
	int maxVal = 0;
	int answer = 0;
	st.push(-1); //이전위치부터 해야지, 고려되어진다. 모든 길이가
	for (int i = 0; i < input.size(); i++)
	{
		char ch = input[i];

		if (ch == '(')
		{
			st.push(i);
		}
		else
		{

			st.pop();
			//성공 => 2의 배수
			if (st.empty() == false)
			{
				answer = max(answer, abs(st.top() - i));
			}
			else{
				st.push(i);
				continue;
			}
		}
	}

	cout<<answer<<'\n';
	return 0;
}

/*
(())( => () 쌍으로 한다. stack 으로 해보자
만약 실패하면 스택에 있는걸 다 리셋 후 다시 시작한다.
*/