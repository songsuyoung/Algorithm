#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;

	cin>>input;

	unordered_set<string> contain;
	for (int i = 1; i <= input.size(); i++)
	{
		//패턴 생성

		for (int j = 0; j < input.size()-i+1; j++)
		{
			string sub = input.substr(j,i); //j~j+1
			
			if (contain.find(sub) == contain.end())
			{
				contain.insert(sub);
			}
		}
	}

	cout<<contain.size()<<'\n';
}

/*
듣도 못한 사람 명단/ 보도 못한 사람 => 둘다 없는 사람 체크
*/