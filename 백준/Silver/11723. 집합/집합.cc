#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);

	int total = 0;

	int N;
	cin>>N;

	for (int i = 0; i < N; i++)
	{
		string command;
		cin>>command;

		int num;

		if (command == "add")
		{
			cin>>num;
			total |= (1<<num);
		}
		else if(command == "check")
		{
			cin>>num;
			
			if (total & (1 << num))
			{
				cout<<1<<'\n';
			}
			else
			{
				cout<<0<<'\n';
			}
		}
		else if (command == "remove")
		{
			cin>>num;

			total &= ~(1<<num); //꺼줌
		}
		else if (command == "toggle")
		{
			cin>>num;

			total ^= (1<<num);
		}
		else if (command == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				total |= (1<<i);
			}

		}
		else if (command == "empty")
		{
			total =0;
		}
	}
}

/*
집합..

set
*/
