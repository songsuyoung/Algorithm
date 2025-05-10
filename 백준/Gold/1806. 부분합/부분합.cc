#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,S;

	cin >> N >> S;

	vector<long long> v(N);

	for (int i = 0; i < N; i++)
	{
		cin>>v[i];
	}

	int left = 0;
	long long sum = 0;
	int dist = 987654321; //최소값을 구하기 위해 큰 값으로 리셋
	

	for (int right = 0; right < N; right++)
	{
		sum += v[right];

		while (sum >= S)
		{
			//S 이상이 되는 것 중 가장 짧은 길이
			dist= min(dist, abs(right - left + 1));
			sum -= v[left++];
		}
	}

	if (dist == 987654321)
	{
		dist = 0;
	}

	cout<<dist<<'\n';
}

/*
10'000 이하의 자연수로 이루어진 길이 N짜리 수열

연속된 수들의 부분합 중에 그 합이 S이상이 되는 것 중 가장 짧은 것의 길이를 구하는 프로그램

예) 투포인터

5 1 3 5 10 7 4 9 2 8

정렬

1 2 3 4 5 5 7 8 9 10
  - - - - - -

1. S값을 초과하면 왼쪽 이동
2. S값을 초과하지않으면 오른쪽 이동 하면서 sum을 만듬
3. 배열이 right에 끝에 도달해도, left 값이 right에 도달할때까지 반복문을 돌리낟.


*/