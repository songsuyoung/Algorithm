#include <bits/stdc++.h>
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	deque<int> dq;

	for (int i = 0; i < N; i++)
	{
		int command;
		cin>>command;

		switch (command)
		{

			int x;
			case 1:
				cin>>x;
				dq.push_front(x);
			break;
			case 2:
				cin>>x;
				dq.push_back(x);
			break;
			case 3:
				if (dq.empty())
				{
					cout<<-1<<'\n';
				}
				else
				{
					cout<<dq.front()<<'\n';
					
					dq.pop_front();
				}
			break;
			case 4:
				if (dq.empty())
				{
					cout<<-1<<'\n';
				}
				else
				{
					cout<<dq.back()<<'\n';
					
					dq.pop_back();
				}
			break;
			case 5:
				cout<<dq.size()<<'\n';
			break;
			case 6:
				cout<<dq.empty()<<'\n';
			break;

			case 7:
				if (dq.empty())
				{
					cout << -1 << '\n';
				}
				else
				{
					cout << dq.front() << '\n';
				}
			break;
			case 8:
				if (dq.empty())
				{
					cout << -1 << '\n';
				}
				else
				{
					cout << dq.back() << '\n';
				}
			break;
		}
	}
}