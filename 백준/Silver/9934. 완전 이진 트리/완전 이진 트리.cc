#include <bits/stdc++.h>
using namespace std;

void recursive(vector<int>& v, vector<vector<int>>& tree, int level, int left, int right)
{
	if (left >= right)
	{
		//끝에 도달
		tree[level].push_back(v[left]);
		return;
	}

	int mid = (left+right)/2;

	tree[level].push_back(v[mid]);

	recursive(v, tree, level+1, left, mid-1);
	recursive(v, tree, level+1, mid+1, right);

}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	vector<int> v(pow(2,N)-1);
	vector<vector<int>> tree(N); //레벨에 따라서 배치하기 위함.
	//level = 2, node 2^3-1 개있다는 소리
	for (int i = 0; i < v.size(); i++)
	{
		cin>>v[i];
	}

	recursive(v, tree, 0, 0, v.size()-1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < tree[i].size(); j++)
		{
			cout<<tree[i][j]<<' ';
		}
		cout<<'\n';
	}
}

/*
K인 완전 이진 트리

깊이가 K인 완전 이진 트리는 총 2^K-1 개의 노드로 이루어짐.


1. 상근이는 트리의 루트에 있는 빌딩 앞에 서있다.
2. 현재 빌딩의 왼쪽 자식에 있는 빌딩에 들어가지 않았다면, 왼쪽으로 이동
3. 현재 있는 노드가 왼쪽 자식을 가지고 있지 않거나 이미 들어간 경우에 종이 씀
4. 이미 들어간 상태인데, 오른쪽 자식이 있음 오른쪽으로 이동.

예시가 

2 1 3
1 6 4 3 5 2 7
인걸 보아서 중위 탐색임을 알 수 있음.


중위 탐색으로 알아내는 방법... 

0 1 2 3 4 5 6
1 6 4 3 5 2 7
=> 6/2 => 3번 인덱스가 가운데

/절반씩 줄여 나감 

0 1 2 3   |   4 5 6

3/2 => 1

1 6 | 4 | 3   |   5 | 2 | 7


1 | 4 3     | 5  7

절반씩 분할에서 출력하면 된다?
*/