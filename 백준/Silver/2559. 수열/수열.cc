#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int N, K;
	cin >> N >> K;

	vector<int> psum(N+1,0);

	//구간합
	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		psum[i] = psum[i - 1] + input;
	}
	
	int frontIdx = 0, answer = INT_MIN;
	for (int j = K; j <= N; j++)
	{
		answer = max(answer, psum[j] - psum[frontIdx++]);
	}

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