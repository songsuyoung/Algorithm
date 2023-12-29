//완전 탐색을 이용해 모든 경우를 살펴본 후 가장 작은 값을 리턴한다.
//C=1000, N<=20 이지만, (20*1000)^2 = 20000*20000   400 000 000 => 대략 4초 
//dp를 이용해서 문제 범위를 n번으로 줄인다. 20*1000 => 20000번으로 줄임.
//골5 15:14초 완료
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recursive(int C, vector<int> &dp,vector<pair<int,int>> &cities)
{
	if (C <= 0) return dp[0];

	if (dp[C] != INT_MAX) return dp[C];

	for (int i = 0; i < cities.size(); i++)
	{
		dp[C] = min(dp[C], recursive(C - cities[i].second, dp, cities) + cities[i].first);
	}

	return dp[C];
}
int main()
{
	int C, N;
	cin >> C >> N;

	vector<pair<int, int>> cities(N);
	vector<int> dp(C*2,INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> cities[i].first >> cities[i].second;
	}

	cout<<recursive(C,dp,cities);
}