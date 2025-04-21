#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	

	unordered_map<char,int> eng[200'005];

	string input;
	cin>>input;

	int len = input.size();

	for (int i = 0; i < len; i++)
	{
		char ch = input[i];

		for (const auto& pre : eng[i]) //이전 것
		{
			eng[i+1][pre.first] += eng[i][pre.first];
		}

		eng[i+1][ch]++; //현재 것
	}

	int M;
	cin>>M;

	for (int i = 0; i < M; i++)
	{
		char ch;
		int st, ed;
		cin >> ch >> st >> ed;

		cout << eng[ed + 1][ch] - eng[st][ch] << '\n';
	}
}

/*
문자열에서 특정 알파벳이 몇 번 나타나는지 알아봐서 자주 나타나는 알파벳이 중지나 검지 위치에 오는 알파벳인지 확인하면 실용적

각 문자에 대해 개수를 센다..


문자열 길이 2'000 char-int
s

s 1

se

s 1
e 1

seu
s 1
e 1
u 1

*/