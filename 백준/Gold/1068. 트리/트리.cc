#include <bits/stdc++.h>
using namespace std;

vector<int> dp(55, 0);
int dfs(vector<vector<int>>& tree, int parent, int& deleteNode)
{
	
	int cnt=0;
	for (int i = 0; i < tree[parent].size(); i++)
	{
		if (tree[parent][i] == deleteNode) continue; //탐색 금지

		dp[parent] += dfs(tree, tree[parent][i], deleteNode);
		cnt++;
	}
	
	// 리프노드
	if (cnt == 0)
	{
		//leaf node
		return 1; //자기 자신이 leaf 임을 안다
	}

	return dp[parent];
}


int main()
{
	int N;
	cin >> N;

	vector<int> input(N);

	vector<vector<int>> tree(55);

	int root = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];

		//-1을 찾는다.
		if (input[i] == -1)
		{
			root = i;
		}
		else
		{
			tree[input[i]].push_back(i);
		}
	}

	int K;
	cin >> K;

	if (K == root)
	{
		cout<<0<<'\n';
	}
	else
	{
		cout << dfs(tree, root, K)<<'\n';
	}
}