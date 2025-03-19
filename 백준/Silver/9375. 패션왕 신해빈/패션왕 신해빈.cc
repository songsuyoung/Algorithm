#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		vector<string> v;
		unordered_map<string, int> cnt;

		int M;
		cin >> M;

		for (int j = 0; j < M; j++)
		{
			string name, type;
			cin >> name >> type;
			
			if (cnt.find(type) == cnt.end())
			{
				//없을 때 추가
				v.push_back(type);
			}
			cnt[type]++; //같은 이름을 가진 의상은 없기 때문에 카운트만 센다.	
		}

		int answer = 1;

		for (int i = 0; i < v.size(); i++)
		{
			//옷을 안입는 경우의 수를 포함
			answer *= (cnt[v[i]] + 1);
		}

		//전부 안입었을때 1을 빼준다.
		cout << answer - 1 << '\n';
	}
}


/*

*/