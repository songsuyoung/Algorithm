#include <bits/stdc++.h>
using namespace std;

/*
	동시에 건물 짓기가 가능함
	이미 지어진 건물의 경우와 아직 지어지지않은 건물을 확인해야한다.
	이미 지어진 경우, 해당 값을 가져온다.
	지어지지 않은 경우, 깊이 우선 탐색을 수행한다.

	10 20 30 걸렸다면, 30분이면 세 건물다 완성되었을 것. 즉 Max 값과 현재 값을 더한 후 결과값을 추린다.
*/
int dfs(int N, vector<pair<int, vector<int>>>& building, vector<int> &dp, vector<bool> &isVisited,int idx)
{

	isVisited[idx] = true;

	if (dp[idx] != 0)
		return dp[idx];


	int minTime = 0;
	for (int i = 0; i < building[idx].second.size(); i++)
	{
		if (isVisited[building[idx].second[i]])
		{
			//방문했으면 dp값을 가져온다.
			minTime=max(minTime,dp[building[idx].second[i]]);
		}
		else
		{
			//방문 안했으면 방문하러 들어간다.
			minTime = max(minTime,dfs(N, building, dp, isVisited, building[idx].second[i]));
		}
	}

	return dp[idx] = building[idx].first + minTime;
}
int main()
{
	int N;

	cin >> N;

	vector<pair<int, vector<int>>> building(N+1);

	for (int i = 1; i <=N; i++)
	{
		int min;
		cin >> min;

		building[i].first = min;
		while (true)
		{
			int preBuilding;
			cin >> preBuilding;

			if (preBuilding == -1) break;

			building[i].second.push_back(preBuilding);
		}
	}

	vector<int> dp(N + 1, 0); //건물의 최종 시간을 저장하기 위한 dp
	vector<bool> isVisited(N + 1, 0); //건물의 최종 시간을 저장하기 위한 dp

	for (int i = 1; i <= N; i++)
	{
		cout<< dfs(N, building, dp, isVisited, i)<<'\n';
	}
}
// 1
// 2
// 3
// 4