#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//N개 작은 값만 남겨둔다.
	priority_queue<int,vector<int>, greater<>> pq;

	int x;
	int i = 0;
	for (; i < N * N; i++)
	{
		cin >> x;

		//5개를 유지한다.
		pq.push(x);

		if (pq.size() > N)
		{
			pq.pop();
		}
	}

	cout<<pq.top()<<'\n';
}