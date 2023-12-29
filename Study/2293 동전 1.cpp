#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> v(N, 0);
	vector<int> dp(K+1,0);

	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i]; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j - v[i]];
		}
	}
	cout << dp[K];
}

/*
* EX ) K=10
*	 0 1 2 3 4 5 6 7 8 9 10
* 1: 1 1 1 1 1 1 1 1 1 1 1
* 2: 0+1 0+1 1+1 1+1 ... 
* 5:          3+1 4+1 ...
* (dp[j]가 이전 값에 의해 초기화 되어있을 것)
* dp[j]=dp[j]+dp[j-coin]
* coin 이전 위치에는 영향을 주지 않기 때문에.. 
*/