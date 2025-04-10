#include <bits/stdc++.h>
using namespace std;

vector<int> dp(55);

int dfs(vector<vector<int>>& tree, int parent)
{
	if (tree[parent].size() == 0)
	{
		//leaf node
		return 1; //자기 자신이 leaf 임을 안다
	}

	for (int i = 0; i < tree[parent].size(); i++)
	{
		dp[parent] += dfs(tree, tree[parent][i]);
	}

	return dp[parent];
}

void deleteNode(vector<vector<int>>& tree, int parent)
{
	for (int i = 0; i < tree[parent].size(); i++)
	{
		deleteNode(tree, tree[parent][i]);
	}
	tree[parent].clear();
}



int main()
{
	int N;
	cin>>N;

	vector<int> input(N);

	vector<vector<int>> tree(55);
	
	int root=-1;
	for (int i = 0; i < N; i++)
	{
		cin>>input[i];

		//-1을 찾는다.
		if (input[i] == -1)
		{
			root=i;
		}
		else
		{
			tree[input[i]].push_back(i);
		}
	}

	int K;
	cin>>K;

	deleteNode(tree, K);

	for (auto& node : tree)
	{
		for (int i = 0; i < node.size(); i++)
		{
			if (node[i] == K)
			{
				node.erase(node.begin() + i);
				break;
			}
		}
	}

	if (K == root)
	{
		cout<<0<<'\n';
	}
	else
	{
		cout << dfs(tree, root);
	}
}

/*
* 트리에서 리프 노드란 자식의 개수가 0인 노드를 말한다.
* dp로 각 노드에 lead node 개수를 저장한다. => 총 개수 - dp[2] 를 하면 개수가 나온다.
* dfs로 풀면된다.
* -1은 root 
* -1(i) => 0(j) 0(j) 두개가 들어가고
* 0 => 1 1 두개가 들어감
*/