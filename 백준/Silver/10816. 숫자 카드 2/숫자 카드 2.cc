#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<int, int> couting;

	int N;
	cin>>N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin>>num;

		couting[num]++; //빈도 체크
	}

	int M;
	cin>>M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin>>num;

		cout<<couting[num]<<' ';
	}
}

/*
숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때 몇 개? 
*/