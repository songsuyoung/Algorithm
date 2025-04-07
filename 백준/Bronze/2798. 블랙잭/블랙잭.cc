#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N,M;
	cin>>N>>M;

	vector<int> cards(N);

	for (int i = 0; i < N; i++)
	{
		cin>>cards[i];
	}

	//1. 반복문 방법
	int answer=0;
	for (int i = 0; i < N; i++)
	{
		int sum = cards[i];
		for (int j = 0; j < N; j++)
		{
			if(i == j) continue;
			sum += cards[j];

			for (int k = 0; k < N; k++)
			{
				if (i == k || j == k) continue;
				
				// 선택한다.
				sum+= cards[k];

				if (sum <= M)
				{
					answer = max(answer, sum);
				}

				// 취소한다.
				sum -= cards[k];
			}

			sum -= cards[j];
		}
	}

	cout<<answer<<'\n';
}

/*
카드 합이 21을 넘지 않는 한도 내에서, 카드 합을 최대로 만드는 게임
N장 카드를 숫자가 보이도록 바다엑 놓는다.
딜러는 숫자 M을 크게 외친다.
N장 중 3장의 카드를 골라야한다. 
M을 넘지 않으면서 M과 최대한 가깝게 만들어야한다.

5C3 중 M을 초과하지 않으면서, M과 최대한 가깝게 값을 가져야 한다.

조합의 2가지 방법 3개의 반복문을 돌린다. or 재귀를 돌린다.
*/