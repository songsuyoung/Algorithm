#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;

	cin>>N;

	//two pointer 
	long long left = 0, right = 0;

	int answer = 0;
	long long sum = 0;

	while (left <= N)
	{
		if (sum > N)
		{
			sum -= left;
			left++;
		}
		else
		{
			if (sum == N)
			{
				answer++;
			}

			sum += right;
			right++;
		}
	}

	// 자기 자신
	cout<<answer<<'\n';
}
