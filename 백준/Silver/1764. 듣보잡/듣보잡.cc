#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//사전 순 Set
	set<string> name;

	int N,M;
	cin>>N>>M;

	for (int i = 0; i < N; i++)
	{
		string n;
		cin>>n;

		name.insert(n);
	}

	vector<string> v;
	for (int j = 0; j < M; j++)
	{
		string n;
		cin>>n;

		if (name.find(n) != name.end())
		{
			v.push_back(n);
		}
	}

	cout<<v.size()<<'\n';


	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<'\n';
	}
}

/*
듣도 못한 사람 명단/ 보도 못한 사람 => 둘다 없는 사람 체크
*/