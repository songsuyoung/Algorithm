#include <bits/stdc++.h>
using namespace std;

int combination(int N, int K)
{
	if (K == 0)
	{
		return 1;
	}
	if (N <= 1)
	{
		return 1;
	}

	return N*combination(N-1, K-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin>>N>>K;

	cout<<combination(N, K)/combination(K, K)<<'\n';

}

// 5/2

// 5 * 4 / 2 * 1 => 20/2