#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int num;
	while (cin >> num)
	{
		long long num2 = 0;

		int cnt = 0;
		while(true)
		{
			num2 = (10 * num2 + 1);

			if (num2 % num == 0)
			{
				cout << cnt+1 << '\n';
				break;
			}
			num2 %= num; //너무 큰 수를 방지하기 위해서 모드 연산을 수행해서 줄임.
			// 어차피 패턴은 반복되어지니까
			cnt++;
		}
	}

}
/*
2와 5로 나누어 떨어지지 않는 정수 n )10'000

각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램

예)
3 = 11
7 = 111
9901


*/