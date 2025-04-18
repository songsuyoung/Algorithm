#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& val1, pair<int, int>& val2)
{
	return val1.first<val2.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,K;
	cin>>N>>K;

	vector<int> dp(K+2, 0);
	vector<pair<int,int>> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin>>arr[i].first>>arr[i].second; //무게, 가치
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = K; j >= arr[i].first; j--) //무게로 -> 무게 초과를 어떻게 확인하지?아..어차피 배열이 K까지구나
		//냅색 알고리즘은 각 아이템은 한 번만 쓸 수 있음이 핵심이라, 뒤에서 부터 계산을 수행해야한다.
		{
			dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
		}
	}

	cout<<dp[K]<<'\n';
}

/*
N, K 무게 버틸 수 있음... => 가치의 합 최대

무게 작은 순으로 정렬
3 6
4 8
5 12
6 13

0 1 2 3 4 5 6 7
---------------
0 0 0 6 6 6 6 6
0 0 0 0 8 8 8 14
0 0 0 0 0 12 12 14


1 5
2 3

0 2 2 2 2
0 0 7 9 9


4 7
6 13
4 8
3 6
5 12


0 0 0 0 0 0 13 13
0 0 0 0 8 8 13 13
0 0 0 6 8 8 13 14
0 0 0 0 12 12 12 13 14

*/