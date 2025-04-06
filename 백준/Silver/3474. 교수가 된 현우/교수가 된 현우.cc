#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int TC;

	cin>>TC;

	for (int i = 0; i < TC; i++)
	{
		int N;
		cin>>N;

		//10의 개수를 구하는 문제
		int two=0,five=0;
		
		for (int j = 2; j <= N; j *= 2)
		{
			//2의 배수로 나올 수 있는 수 구하기
			two += N/j;
		}

		for (int j = 5; j <= N; j *= 5)
		{
			//2의 배수로 나올 수 있는 수 구하기
			five +=N/j;
		}
		int minVal = min(two,five);

		cout<<minVal<<'\n';
	}
}