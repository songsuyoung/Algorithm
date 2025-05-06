#include <bits/stdc++.h>
using namespace std;

long long check(vector<int>& arr, long long mid)
{
	long long cnt = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= mid)
		{
			cnt += (arr[i] - mid);
		}
	}

	return cnt;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin>>N>>M;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}

	sort(arr.begin(), arr.end());

	long long answer = 0;

	// N = 1'000'000 2억 안넘음
	long long left = 0;
	long long right = arr[arr.size()-1];

	while (left <= right)
	{
		long long mid = (left+right)/2;

		//높이 H를 지정 => mid
		long long tree = check(arr, mid);

		if (tree < M)
		{
			//N보다 작을 경우, mid 크기를 너무 크게 잡음 왼쪽으로 이동
			right = mid - 1;
		}
		else
		{
			answer = max(answer, mid);
			//N보다 클 경우, mid 크기를 너무 작게 잡음 오른쪽으로 이동
			left = mid + 1;
		}
	}

	cout<<answer<<'\n';
}

/*
나무 M미터

상근이는 절단기에 높이 H를 지정
높이가 H보다 큰 나무는 H위의 부분이 잘릴 것.
낮으면, 안잘림


예)

20 15 10 17

상근이가 높이 H 지정

5 0 10 2 로, 길이가 5인 나무와 2인 나무를 가지고 갈 것임.

나무를 필요한 만큼만 가져가려고 할 때 적어도 M미터 나무를 가져가기 위해 절단기 설정 높이의 최댓값은?

예)
 0 1  2  3
10 15 17 20

(0+3)/2 = 1 => H = 15로 설정


- 0 2 5 => 7m == 7m


만약 17이 될 경우

- - 0 3 => 3<7 작기 때문에 좌측으로 이동

만약 10이 될 경우
0 5 7 10 => 23>7 크기 때문에 우측으로 이동


예)
0 1  2  3  4
4 26 40 42 46

(0+4)/2 => 2

H = 40

- - 0 2 6 => 8<20 좌측 이동
(0+2)/2 => 1

H=26

- - 14 18 20 => 


높이 최소 4~46사이!

*/