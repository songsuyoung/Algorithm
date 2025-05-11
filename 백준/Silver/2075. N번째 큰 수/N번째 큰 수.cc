#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N*N, 0);

	for (int i = 0; i < N * N; i++)
	{
		cin>>v[i];
	}

	sort(v.begin(), v.end());

	cout<<v[N*N-N]<<'\n';
}