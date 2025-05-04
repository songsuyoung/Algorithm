#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//모두 더한다.

	int N;
	cin>>N;

	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin>>v[i];
	}

	sort(v.begin(), v.end());

	int i=0;
	int answer=0;
	while (i < N)
	{

		int team = v[i];

		if (i + team < v.size())
		{
			answer++;
			i+=team;
		}
		else
		{
			//마지막 한팀 처리
			answer++;
			break;
		}
	}

	cout<<answer<<'\n';

}

/*
알버트가 다니는 학교에서 해커톤, N명 학생 참가 의사

N명을 몇 개의 팀으로 나눠야 하는데, 팀의 개수가 최소

5명

1 2 1 2 1

1은 3개 => 각 1씩 만나니 3/2 => 1팀
2는 2팀 => 2/2 => 1팀


9
2 2 2 3 3 3 2 2 2 

2 6팀/2 => 3팀
3 3팀/3 => 1팀

4탐

9
2 2 2 2 2 3 3 3 3 


2 2 2
=> 정렬한다.
=> 지정된 수 만큼 이동
=> answer++ 하면된다.
*/