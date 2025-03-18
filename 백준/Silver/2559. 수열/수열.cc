#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int N, K;
	cin >> N >> K;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int frontIdx = 0;
	int sum = 0; //-100 ~ 100 이상의 수를 100'000 이하이면.. 최대수 100 * 100'000 => 10'000'000 -> 즉 int 커버가능
	
	for (int i = 0; i < K; i++)
	{
		sum += arr[i];
	}

	int answer = sum;

	for (int i = K; i < N; i++)
	{
		answer = max(answer, sum);
		sum -= arr[frontIdx++];
		sum += arr[i];
	}

	answer = max(answer, sum);

	cout << answer << '\n';
	
}


/*
어떤 정수의 수열이 주어졌을 때
연속적인 며칠 동안의 온도의 합이 가장 큰 값을 알아 보고자 한다...

이틀간의 합 = 21
5일간의 합 = 31 -> 윈도우 슬라이딩 기법
앞부분을 더하고 뒷부분 빼고 (즉 deque 사용) => 또는 앞부분을 가리키는 frontIdx값
더할 수 있는 sum 

실제 값을 가지고 나오는 것이 아니기 때문에 정수형 2개로 확인한다.
*/