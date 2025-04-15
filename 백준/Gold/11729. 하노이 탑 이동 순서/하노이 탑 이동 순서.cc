#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> answer;

void hanoi(int N, int from, int temp, int to)
{
	if (N <= 1)
	{
		answer.push_back({from,to});
		return;
	}
	hanoi(N-1, from, to, temp);
	answer.push_back({ from,to });
	hanoi(N-1, temp, from, to);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>> N;

	hanoi(N, 1, 2, 3);

	cout<<answer.size()<<'\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout<<answer[i].first<<' '<<answer[i].second<<'\n';
	}
}
