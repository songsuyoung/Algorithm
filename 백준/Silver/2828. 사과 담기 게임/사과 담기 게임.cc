#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int apple;

	cin >> apple;

	int answer = 0;
	pair<int,int> cur = {1, 1+M};

	for (int i = 0; i < apple; i++)
	{
		int pos;

		cin >> pos;

		int dest = 0;
		if(cur.first <= pos && cur.second > pos) continue; //안움직여도 된다.

		if (cur.first < pos)
		{
			//+ 우측으로 갈때에는 cur.second를 조정하는게 낫겠다.
			dest = pos - cur.second + 1;
	
			cur.first = cur.first + dest;
		}
		else if (cur.first > pos)
		{
			//-
			dest = cur.first - pos;

			cur.first = cur.first - dest;
		}

		cur.second = cur.first + M;

		answer += abs(dest);
	}

	cout << answer << '\n';
}

/*

상근이 사과담기 게임

스크린은 N칸
바구니는 M칸


	--(바구니)
--------------------------- (스크린)


스크린 위에 사과가 떨어진다.
한 사과가 바닥에 닿는 즉시 다른 사과가 떨어진다.
떨어질때 바구니가 아래에 있음 담는다.
상근이는 사과를 모두 담으려고 한다.

바구니의 이동 최솟값을 구해라


예)

-
-----

1,5,3 => 좌표 => 정렬 1,3,5 => 정렬 ㄴㄴ 순서가 있음.

시작 위치 :맨 왼쪽 M칸 즉, (0, 0+M)


1,2(2는 포함 ㄴㄴ) => 즉 (1,1) 내에 속하는지 확인 => 1 OK


5

int dest = 목표 - M; (가는 위치 dest)

(1+dest,st+M) => 5,5 (OK)

1(이전 위치) + 5(목표 위치) - 1(바구니 크기) => 4
5+1 => 6 (포함 ㄴㄴ)


0+dest(4)
만약 현재 위치보다 목표위치가 작다면, 음수로

cur.first(4) - 3(dest)

int dest = -3 + 1 => abs(2칸) 

5 - 3 + 1 => 3,4

0 + 4 + 2 => 6




5 2

1 5 3

5
int dest = 5 - 2; abs(3)

1 + 5 - 2 => 4,6

3

4-3;

int dest = -3 + 2 => abs(1)

4 - 3 + 2 => 3,5


3+1 => 4


예)

5 4
5

5-4 => 1칸 이동

1 + (5 - 4)
	2, 6

1

현재 위치 2, 6

목표 위치 1


2-1 => 1칸 (굳이 M칸 이동할 필요가 없다..)

2 + (-1 + 4)

1칸 이동해야지 최소


*/

