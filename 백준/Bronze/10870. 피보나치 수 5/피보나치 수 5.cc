#include <bits/stdc++.h>
using namespace std;

int fibonaci(int N)
{
	if (N <= 1)
	{
		return N;
	}

	return fibonaci(N-1) + fibonaci(N-2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	cout<< fibonaci(N)<<'\n';
}
