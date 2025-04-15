#include <bits/stdc++.h>
using namespace std;

int distance(vector<pair<int, int>>& chicken, vector<pair<int, int>>& home, vector<bool>& isVisited)
{
	vector<int> dist(home.size(), 987654321);
	for (int i = 0; i < isVisited.size(); i++)
	{
		if (isVisited[i])
		{
			//방문 했다는 소리는 여기서부터 모든 거리를 체크
			for (int j = 0; j < home.size(); j++)
			{
				int local = abs(home[j].first - chicken[i].first) + abs(home[j].second - chicken[i].second);
				dist[j] = min(dist[j], local);
			}
		}
	}

	int res = 0;

	//가장 가까운 치킨 거리 확인
	for (int i = 0; i < dist.size(); i++)
	{
		res+=dist[i];
	}

	return res;

}
int recursive(vector<pair<int, int>>& chicken, vector<pair<int, int>>& home, vector<bool>&isVisited, int selected, int idx)
{
	if (selected <= 0)
	{
		//선택 다함.
		return distance(chicken, home, isVisited);
	}

	int res=987654321;
	for (int i = idx; i < chicken.size(); i++)
	{
		if(isVisited[i]) continue;
		isVisited[i] = true; //선택한다.
		res = min(res,recursive(chicken, home, isVisited, selected - 1, i));
		isVisited[i] = false;
	}

	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,M;
	cin>>N>>M;

	vector<pair<int,int>> chicken;
	vector<pair<int, int>> home;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int dest;
			cin>>dest;

			if (dest == 2)
			{
				//치킨 집
				chicken.push_back({i,j});
			}
			else if (dest == 1)
			{
				home.push_back({i,j});
			}
		}
	}

	vector<bool> isVisited(chicken.size(), false);
	cout << recursive(chicken, home, isVisited, M, 0) << '\n';
}

/*
치킨 거리 = |r1-r2| + |c1-c2| 집과 가장 가까운 치킨집 사이의 거리
0 빈칸
1 집
2 치킨집

치킨집과 집의 좌표를 모두 저장한 뒤, 치킨 거리가 가장 작게될 M을 구해야함?

1. 치킨집 3개 선택 => 재귀
2. 집과의 거리를 잰다. => min 들만 더함 (치킨-집 간의 거리중 sum+=min) 
3. min 값을 구한다.
*/