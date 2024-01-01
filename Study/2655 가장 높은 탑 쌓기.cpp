#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Brick
{
	int id;
	int bottom;
	int height;
	int weight;
};

pair<int, int> recursive(vector<Brick> &bricks,vector<int> &dp, vector<int>& child, int idx)
{
	if (idx == bricks.size() - 1)
	{
		dp[idx] = bricks[idx].height;
		return make_pair(idx, dp[idx]);
	}

	pair<int, int> preRes = recursive(bricks, dp, child,idx + 1);

	// 큰 순 --idx--- 작은 순(preRes)
	if (bricks[preRes.first].weight < bricks[idx].weight)
	{
		dp[idx] = preRes.second + bricks[idx].height;
		child[idx] = preRes.first;
		return make_pair(idx, dp[idx]);
	}

	// idx(밑면이 넓어야함) ----- i(바텀이 작고, 무게도 적은것 선택 가능)
	int height = 0;
	for (int i = idx+1; i < bricks.size(); i++)
	{
		if (bricks[idx].weight > bricks[i].weight &&dp[idx]<dp[i])
		{
			dp[idx] = dp[i];
			child[idx] = i;
		}
	}
	dp[idx]+= bricks[idx].height;
	return preRes.second > dp[idx] ? preRes : make_pair(idx, dp[idx]);
}

bool compare(const Brick& a,const Brick& b)
{
	return a.bottom > b.bottom;
}

int main()
{
	int N;
	cin >> N;
	vector<Brick> bricks;
	vector<int> dp(N,0);
	vector<int> child(N, -1);

	for (int i = 0; i < N; i++)
	{
		int b, h, w;
		cin >> b >> h >> w;

		bricks.push_back(Brick{i+1,b,h,w });
	}
	sort(bricks.begin(), bricks.end(), compare);
	pair<int, int> res = recursive(bricks, dp, child, 0);

	vector<int> orders;
	int idx = res.first;

	while (idx != -1)
	{
		orders.push_back(bricks[idx].id);
		idx = child[idx];
	}
	cout << orders.size() << '\n';
	for (int i = orders.size() - 1; i >=0;i--)
	{
		cout << orders[i] << '\n';
	}
}