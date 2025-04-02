#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin>>N;

	int cnt=0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin>>num;
		int j = 2;
		for (; j < num; j++)
		{
			if (num % j == 0)
			{
				break;
			}
		}

		if (num>1 && j >= num)
		{
			cnt++;
		}
	}

	cout<<cnt<<'\n';
	return 0;
}
