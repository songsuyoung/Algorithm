#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<string, int> name;
	unordered_map<int, string> number;

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string n;
		cin >> n;
		name[n] = i + 1;
		number[i + 1] = n;
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		
		if (input[0] >= '0' && input[0] <= '9')
		{
			//숫자
			cout << number[stoi(input)] << '\n';
		}
		else
		{
			cout << name[input] << '\n';
		}
	}
}


/*
라이벌 오영식.. 
포켓몬 도감에서 포켓몬의 이름을 보면 포켓몬 번호를 말하라...

*/