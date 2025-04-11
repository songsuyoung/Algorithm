#include <bits/stdc++.h>
using namespace std;


int cnt = 0;

void dfs(vector<vector<int>>& computer,vector<bool>& isVisited, int cur)
{	
	isVisited[cur] = true;
	for (int i = 0; i < computer[cur].size(); i++)
	{
		if(isVisited[computer[cur][i]]) continue;

		dfs(computer, isVisited, computer[cur][i]);
		cnt++;
	}
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,M;
	cin>>N>>M;

	vector<vector<int>> computer(N+1); //1부터 시작

	for (int i = 0; i < M; i++)
	{
		int A,B;
		cin>>A>>B;

		computer[B].push_back(A);
	}

	vector<int> counting;
	int maxValue = 0;
	for (int i = 1; i <= N; i++)
	{
		//한번에 많이 해킹할 수 있는 컴퓨터 번호이기 때문에 갈 수 있는 모든 경로 확인
		cnt = 0;
		vector<bool> isVisited(10'005);
		dfs(computer, isVisited, i);
		counting.push_back(cnt);
		maxValue = max(maxValue, cnt);
	}

	for (int i = 0; i < counting.size(); i++)
	{
		if (maxValue == counting[i])
		{
			cout<<i+1<<' ';
		}
	}
}

/*
해커 김지민, N개의 컴퓨터로 이루어져 있다.
한 번의 해킹으로 여러 개의 해킹할 수 있다.

예를 들어,

A -> B 신뢰하는 경우 B를 해킹하면 A 또한 해킹이 가능하다.
computer[A][B] = 1
computer[B][A] = 1

양방향 그래프
*/