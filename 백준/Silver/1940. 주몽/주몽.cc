#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int M;
	cin >> M; //두 번호를 합쳐서 M에 도달 해야 한다.

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	int left = 0;
	int right = arr.size() - 1; 
	//두 포인터 인덱스 정렬

	int answer = 0;
	while (left < right)
	{
		int sum = arr[left] + arr[right];

		if (sum < M)
		{
			left++;
		}
		else if (sum > M)
		{
			right--;
		}
		else
		{
			answer++;
			left++;
			right--;
		}
	}

	cout << answer << '\n';
}

/*
철기군이 입을 갑옷

갑옷을 만드는 재료들은 각각 고유번호를 가지고 있다.
두 개의 재료를 만드는데 두 재료의 고유한 번호를 합쳐서 M이 되면, 갑옷을 만들 수 있다.

예)

재료 개수 6
M = 9

2 7 4 1 5 3

2 + 7 = 9
1 + 5 + 3 = 9

한 번 씩만 사용해서 갑옷을 만들 수 있음.
=> 두 재료의 고유한 번호를 합쳐서 M 즉, 두 번호 합쳐서 만듬.

1 2 3 4 5 7

2 + 7 = 9
4 + 5 = 9

투 포인터?

1 2 3 4 5 7

1 + 7 < M left 증가
2 + 7 == M cnt+1, right 감소, left 증가 (각 한번씩 사용)
3 + 5 < M left 증가
4 + 5 == M cnt+1, right 감소, left 증가 right < left 멈추기.

1 + 9 > M right 감소
*/