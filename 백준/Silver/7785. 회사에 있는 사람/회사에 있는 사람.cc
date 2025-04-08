#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, bool, greater<>> log;

	int N;
	cin>>N;

	for (int i = 0; i < N; i++)
	{
		string name, record;

		cin>>name>>record;

		if (record == "enter")
		{
			log[name] = true;
		}
		else
		{
			log[name] = !log[name];
		}
	}

	for (const auto l : log)
	{
		if (l.second)
		{
			cout<<l.first<<'\n';
		}
	}
}

/*
* 자유로운 출퇴근 9~6시까지 회사에 있지 않아도 된다.
*/