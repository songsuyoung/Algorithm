#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long factorial(int N)
{
	if (N <= 1)
	{
		return 1;
	}

	return factorial(N-1)*N;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	cout<<factorial(N)<<'\n';
}
