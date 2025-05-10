#include <bits/stdc++.h>
using namespace std;

int main()
{

	int X;
	cin>>X;

	int prev = 64;
	long long sum = 0;

	vector<int> bars;
	long long total = 0;
	while (prev > 0)
	{
		int cur = prev;
		
		//cout<<bitset<64>(sum)<<' '<<cur<<' '<<total<< '\n';
		if (total + cur <= X)
		{
			sum |= (1LL<<cur); //16번째를 킴
			total+= cur;
			bars.push_back(cur);
		}

		prev/=2;
	}
	cout<<bars.size()<<'\n';
}

/*
지민이 64cm 막대

그는 길이 Xcm 막대를 가지고 싶음.
원래 가지고 있던 막대를 더 작은 막대로 자른 다음에, 풀로 붙여서 길이 Xcm인 막대를 만들려고 한다.

1. 지민이가 가지고 있는 막대의 길이를 모두 더한다. (처음에는 64cm), 합이 X보다 크다면, 아래 과정 반복
2. 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 나눈다.
3. 절반 중 하나를 버리고 남아 있는 막대 길이의 합이 X보다 크다면, 위 자른 막대의 절반 중 하나를 버린다.
4. 이제 남아있는 모든 막대를 풀로 붙여서 Xcm를 만든다.


예)
64 -> 23

64/2 => 32 
32/2 => 16 | 16
16/2 => 8 => (16 + 8) > 23
8/2  => 4(16+4) => 20
4/2  => 2(22+2) => 24
2/2  => 1(22+1) => 23

18 + 4 + 1


2^32 => int
2^64 => long long (long long 비트연산?) => 나눴을 때 크면 버리고 작으면, 비트 키움.


1. while 문 반복 X 일때까지 반복
2. 64/2 => 32 | 32 (32 2개가 나옴) 그 중에서 32 > X 크면 저장 안함. sum + N <= X? bit |연산 
	or sum 을 구함 bit로 더해줌. <=X보다 작으면 비트 연산
3. 반복.
*/