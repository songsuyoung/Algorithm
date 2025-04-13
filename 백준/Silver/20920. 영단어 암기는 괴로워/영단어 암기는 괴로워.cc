#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool compare(pair<string, int> n1, pair<string, int> n2)
{
	if (n1.second == n2.second)
	{
		if (n1.first.size() == n2.first.size())
		{
			return n1 < n2;
		}
		return n1.first.size() > n2.first.size();
	}
	return n1.second > n2.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//빈도수가 높은 순으로 정렬
	//빈도가 같을 때 길이가 길수록 앞으로 배치
	//길이도 같을 때 사전 순으로 정렬

	int N, M;

	cin>>N>>M;

	unordered_map<string,int> m;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin>>input;

		if (input.size() >= M)
		{
			m[input]++;
		}
	}

	vector<pair<string,int>> v;

	for (const auto& sort : m)
	{
		v.push_back(sort);
	}

	sort(v.begin(), v.end(), compare);


	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i].first<<'\n';
	}
}
