#include <iostream>
#include <vector>
using namespace std;
int recursive(int M,vector<pair<int, int>> &chickenPos, vector<pair<int, int>> &homePos,vector<bool> &isVisited,int selected,int idx)
{
	if (M == selected)
	{
		vector<int> distance(homePos.size(), 987654);
		int res = 0;
		for (int i = 0; i < chickenPos.size(); i++)
		{
			//선택된 놈이 골라진 것.
			if (isVisited[i])
			{
				for (int j = 0; j < homePos.size(); j++)
				{
					int dist=abs(chickenPos[i].first - homePos[j].first) + abs(chickenPos[i].second - homePos[j].second);
					distance[j] = min(distance[j], dist);
				}
			}
		}

		for (int i = 0; i < distance.size(); i++)
			res += distance[i];
		return res;
	}
	int res = 9876543;

	for (int i = idx; i < chickenPos.size(); i++)
	{
		if (isVisited[i]) continue;
		isVisited[i] = true;
		res=min(res,recursive(M, chickenPos, homePos, isVisited, selected + 1, i));
		isVisited[i] = false;
	}

	return res;
}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> chickenPos;
	vector<pair<int, int>> homePos;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{

			int input;
			cin >> input;

			if (input == 2)
			{
				chickenPos.push_back(make_pair(i, j));
			}
			else if(input==1)
			{
				homePos.push_back(make_pair(i, j));
			}
		}
	}
	
	vector<bool> isVisited(chickenPos.size(), false);
	cout<<recursive(M,chickenPos, homePos,isVisited,0,0)<<'\n';
}