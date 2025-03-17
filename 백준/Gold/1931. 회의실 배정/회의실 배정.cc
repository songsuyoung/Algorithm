#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int>& first, const vector<int>& second)
{
	if (first[1] == second[1])
	{
		return first[0] < second[0];
	}

	return first[1] < second[1]; //종료시간이 작은 순으로 정렬한다.
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> time(N, vector<int>(2, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> time[i][0] >> time[i][1];
	}

	sort(time.begin(), time.end(), compare);

	int answer = 1; //처음 시작할 떄 선택함.
	int range = time[0][1];
	for (int i = 1; i < N; i++)
	{
		if (time[i][0] >= range) //끝나는 동시에 다음 회의가 시작될 수 있음
		{
			answer++;
			range = time[i][1];
		}
	}

	cout << answer << '\n';
}


/*
* 한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대해 회의실 사용표를 만들려고 함.
*
* 시작-끝나는 시간 (회의)
* 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수
*
* 예)
* 1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/