#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N;
	cin>>N;

	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		string command;
		
		cin>>command;

		if (command == "push")
		{
			int x;
			cin>>x;

			q.push(x);
		}
		else if (command == "front")
		{
			if (q.empty())
			{
				cout<<-1<<'\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if (command == "back")
		{
			if (q.empty())
			{
				cout<<-1<<'\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
		else if (command == "size")
		{
			cout<<q.size()<<'\n';
		}
		else if (command == "empty")
		{
			cout<<q.empty()<<'\n';
		}
		else if (command == "pop")
		{
			if (q.empty())
			{
				cout<<-1<<'\n';
			}
			else
			{
				cout<<q.front()<<'\n';
				q.pop();
			}
		}
	}
}