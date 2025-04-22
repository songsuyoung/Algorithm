#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	vector<int> arr(N);

	for (int i = 0; i < arr.size(); i++)
	{
		cin>>arr[i];
	}

	sort(arr.begin(), arr.end());

	int answer=0;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			answer += arr[j];
		}
	}

	cout<<answer<<'\n';
}

/*
1~N번 까지 있고, i번 사람이 돈을 인출하는데 걸리는 시간 Pi

예) 5명

3,1,4,3,2
1 2 3 4 5 (번줄)

돈 인출하는 수가 가장 적은 사람부터 줄을 세움
*/