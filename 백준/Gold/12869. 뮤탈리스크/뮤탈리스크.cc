#include <bits/stdc++.h>
using namespace std;

int dp[65][65][65];

int cases[6][3] ={{9,3,1}
				,{9,1,3}
				,{3,9,1}
				,{3,1,9}
				,{1,9,3}
				,{1,3,9}};

int recursive(int one, int two, int three)
{
	if (one < 0)
	{
		one = 0;
	}

	if (two < 0)
	{
		two = 0;
	}

	if (three < 0)
	{
		three = 0;
	}
	if (one == 0 && two == 0 && three == 0)
	{
		//종료
		return 0;
	}

	if (dp[one][two][three] != 987654321)
	{
		return dp[one][two][three];
	}

	
	//6개의 경우의 수들 중 선택
	for (int i = 0; i < 6; i++)
	{
		dp[one][two][three] = min(dp[one][two][three], recursive(one - cases[i][0], two - cases[i][1], three - cases[i][2]) + 1);
	}

	return dp[one][two][three];
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	vector<int> scv(3,0);

	for (int i = 0; i < N; i++)
	{
		cin>>scv[i];
	}

	for (int i = 60; i >= 0; i--)
	{
		for (int j = 60; j >= 0; j--)
		{
			for (int k = 60; k >= 0; k--)
			{
				dp[i][j][k] = 987654321;
			}
		}
	}

	cout<<recursive(scv[0], scv[1], scv[2])<<'\n';
}
