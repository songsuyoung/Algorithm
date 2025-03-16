#include <bits/stdc++.h>
using namespace std;

//카운팅 배열을 전역변수로 선언하여 0으로 리셋
int counting[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string answer = "";

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;

		int idx = name[0] - 'a';

		counting[idx]++; //a를 뺄경우 0으로 매핑되어진다.
	}
	
	for (int i = 0; i < 26; i++)
	{
		if (counting[i] >= 5)
		{
			answer += ('a' + i);
		}
	}

	if (answer.size() == 0)
	{
		answer = "PREDAJA";
	}

	cout << answer << '\n';
}

/*
상근이는 농구장 청소하는 일을 시작...
상근이는 선발 명단을 작성
선수 이름을 기억하지 못하고, 각 선수의 능력도 알지 못한다.


누가 선발인지 기억하기 쉽게 하기 위해 성의 첫 글자가 같은 선수 4명을 선발하려고 한다.
만약, 첫 글자가 같은 선수가 5명보다 적으면 기권

예)
babic
keksic
boric
bukic
sarmic
balic
kruzic
hrenovkic
beslic
boksic
krafnic
pecivic
klavirkovic
kukumaric
sunkic
kolacic
kovacic
prijestolonasljednikovi


b = 6
k = 7
s = 2
h = 1
p = 2

0번 인덱스를 사용해서 counting 배열
5개 이상 cnt++

5이하일 경우 PREDAJA 출력

*/
