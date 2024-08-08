#include <iostream>
#include <vector>
using namespace std;

int main()
{

	int X;
	cin >> X;

	int answer = 1;
	int N = 64;

	vector<int> v;
	int total = 0;

	v.push_back(64);

	while (N!=X)
	{
		N = v.back() >> 1; //나누기 2분의 1 진행
		v.pop_back();

		if (total + N >= X)
		{
			//1개만 저장
			v.push_back(N);
		}
		else
		{
			//2개 저장
			v.push_back(N);
			v.push_back(N);
		}
		
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];	
		}
		
		if (sum == X)
		{
			answer = v.size();
			break;
		}

		if (sum - v.back() < X)
		{
			total = sum - v.back();
		}
	}

	cout << answer << '\n';
}