#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		vector<pair<int,int>> top;

		int N;
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			int interview, doc;
			cin >> doc >> interview;

			top.push_back(make_pair(doc, interview));
		}

		sort(top.begin(), top.end()); //������ �߽����� ������ ����.

		int cnt = 1; //1���� �׻� �հ�
		int curTop = top[0].second;
		for (int i = 1; i < N; i++)
		{
			if (curTop > top[i].second)
			{
				curTop = top[i].second;
				cnt++;
				continue;
			}
		}
		
		cout << cnt << '\n';
	}
}