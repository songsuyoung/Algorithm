#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input;

	cin>>input;

	string pattern;
	cin>> pattern;

	
	string buffer = "";

	for (int i = 0; i < input.size(); i++)
	{
		buffer+=input[i];

		if (buffer.size() >= pattern.size())
		{
			if (buffer.substr(buffer.size() - pattern.size()) == pattern) 
			{
				buffer.erase(buffer.end() - pattern.size(), buffer.end());
			}
		}
	}

	if (buffer.empty())
	{
		cout<<"FRULA\n";
	}
	else
	{
		cout<<buffer<<'\n';
	}
	return 0;
}

/*
문자열을 폭발..

폭발 문자열이 폭발하면, 그 문자열은 사라지며 남은 문자열은 합쳐지게 된다.

1. 문자열이 폭발 문자열을 포함하고 있으면, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열 만든다.
2. 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
3. 폭발 문자열이 없어질 때까지 반복

예)

=> 햄버거 문제와 비슷하지않나... 란 생각
mirkovniz
C4
-
4 <- 짝이다.
C <- reset 
C <-
z
i
n
v
o
k
r
i
m

버퍼에서 하나씩 더해가고, 패턴크기를 넘어서면, 패턴 크기만큼 뒤에서 잘라본다. 
만약 뒤에서 잘랐을 때 패턴이랑 값이 같다면, 삭제!!!!
=> 즉, 1'000'000 크기이지만, 실제로 비교는 끝에서부터 최대 36까지만 하기 때문에 시간초과가 안난다.
*/
