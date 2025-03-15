#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//입력
	int cost[4]; //1대 ,2대 3대 의미;

	for (int i = 1; i <= 3; i++)
	{
		//요금을 입력받는다.
		cin >> cost[i];
	}

	vector<int> time(105, 0);

	int maxTime = 0;
	for (int i = 0; i < 3; i++)
	{
		int st, ed;
		cin >> st >> ed;

		for (int j = st; j < ed; j++)
		{
			time[j]++;
		}

		maxTime = max(maxTime, ed);
	}

	int answer = 0;
	for (int i = 1; i <= maxTime; i++)
	{
		answer+=(time[i] * cost[time[i]]); //시간에 따른 몇 대가 있는지 알 수 있음.
	}

	cout << answer << '\n';
}

/*
상근이는 트럭 3대
트럭 주차하는데 비용이 얼마나 드는지 확인
한 대 주차시 1분 A원
두 대 주차시 1분 B원
세 대 주차시 1분 C원

예)

1대 5원씩(한대 기준임. 즉 1대 -> 5원)
2대 3원씩(한대 기준임. 즉 2대 -> 6원)
3대 1원씩(한대 기준임. 즉 3대 -> 3원)
A B C
5 3 1

1 -> 6
3 -> 5
2 -> 8

정렬

1 -> 6
2 -> 8
3 -> 5

    ------
  ------------
----------- 
1 2 3 4 5 6 7 8 (1-100사이)

1-2 1대 => 5 * 2
2-3 2대 => 6 * 1
3-5 3대 => 3 * 2
5-6 2대 => 6 * 1
6-8 1대 => 5 * 3


10 + 6 + 6 + 6 + 15 => 18 + 25 => 43


105 배열을 만들고 start - end 까지 1씩 채운다.
	* 시간의 Max값을 찾음.
그리고 해당 Max까지 배열을 돌면서 돈을 더하면 된다. (1일때 6, 2일때 5..이런식으로) 
*/