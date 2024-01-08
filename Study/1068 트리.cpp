#include <iostream>
#include <vector>
using namespace std;

int recursive(vector<vector<int>> &trees,int cutNode,int root,int idx)
{
	if (idx == cutNode) return 0;
	if (trees[idx].size() == 0) return 1; //리프 노드임

	int answer = 0;
	for (int i = 0; i < trees[idx].size(); i++)
	{
		answer+=recursive(trees, cutNode, root, trees[idx][i]);
	}

	if (answer == 0) answer += 1;
	
	return answer;
}
int main()
{
	int N;
	cin >> N;

	vector<int> buffer(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> buffer[i];
	}

	vector<vector<int>> trees(N+1);
	int rootNode = 0;
	for (int i = 0; i < N; i++)
	{
		if (buffer[i] == -1) {
			rootNode = i;
			continue;
		}
		trees[buffer[i]].push_back(i);

	//	cout << buffer[i] << ' ' << i << '\n';
	}
	//cout << rootNode << '\n';
	int cutNode;
	cin >> cutNode;

	cout<<recursive(trees, cutNode, rootNode, rootNode)<<'\n';
}