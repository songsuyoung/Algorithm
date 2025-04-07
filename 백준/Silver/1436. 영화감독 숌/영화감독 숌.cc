#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	int num = 666;

	int count=1;
	while (true)
	{
		string target = to_string(num);

		//숫자에 666이 들어가있는지 확인
		for (int i = 0; i < target.length() - 2; i++)
		{
			if (target[i] == '6' && target[i + 1] == '6' && target[i + 2] == '6')
			{
				if (count == N)
				{
					cout << num<< '\n';
					return 0;
				}
				count++;
				break;
			}
		}

		num++;
	}
	return 0;
}
