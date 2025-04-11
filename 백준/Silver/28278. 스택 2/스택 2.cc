#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	stack<int> stk;

	for (int i = 0; i < N; i++)
	{
		int command;
		cin>>command;

		switch (command)
		{
			case 1:
			int x;
			cin>>x;

			stk.push(x);
			break;

			case 2:
				if (stk.empty())
				{
					cout<<-1<<'\n';
				}
				else
				{
					cout<<stk.top()<<'\n';
					stk.pop();
				}
			break;

			case 3:
				cout<< stk.size()<<'\n';

			break;

			case 4:
				cout<<stk.empty()<<'\n';
			break;

			case 5:
				if (stk.empty())
				{
					cout<<-1<<'\n';
				}
				else
				{
					cout<<stk.top()<<'\n';
				}
			break;
		}
	}
}