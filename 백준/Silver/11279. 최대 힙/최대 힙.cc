#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int command;

	cin>>command;

	//기본이 최대힙
	priority_queue<int> pq;
	for (int i = 0; i < command; i++)
	{
		int x;
		cin>>x;

		if (x == 0)
		{
			if (pq.empty() == false)
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
			else
			{
				cout<<0<<'\n';
			}
		}
		else
		{
			pq.push(x);
		}
	}

}