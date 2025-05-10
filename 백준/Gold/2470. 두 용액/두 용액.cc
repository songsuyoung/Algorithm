#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	//용액 
	vector<long long> solutions(N);

	for (int i = 0; i < N; i++)
	{
		cin>>solutions[i];
	}

	sort(solutions.begin(), solutions.end());

	//left 초기값
	int left =0;
	//right 가장 오른쪽 값
	int right = N-1;

	int dist = INT_MAX; //가장 작은 값을 만드는 문제
	
	vector<long long> answer(2);
	while (left < right)
	{
		//임시값
		long long temp = solutions[right] + solutions[left];
		// abs(왼쪽 - 오른쪽) => min값 저장
		//두 값을 더해서 0보다 작으면 왼쪽 이동
		//거리는 양방향 고려하지 않기 위해서
		if (abs(temp) < dist)
		{
			answer[0] = solutions[left];
			answer[1] = solutions[right];
			dist = abs(temp);
		}

		if (temp > 0)
		{
			right --;
		}
		else
		{
			left ++;
		}
	}
	
	cout<<answer[0]<<' '<<answer[1]<<'\n';
}
/*
KOI 부설 과학 연구소에서는 많은 산성용액과 알칼리성 용액을 가지고 있음.
산성 1~10억
아칼릴 -1~-10억

두 산성 + 알칼리 => 0에 가까운 용액을 만들려고 한다.

예) -2 4 -99 -1 98

정렬 -99 -2 -1 4 98

-99 + 98 = -1

-1 < 0
-2 + 98 >= 0

-2 + 4 >= 2
-2 - 1 < 0

*/