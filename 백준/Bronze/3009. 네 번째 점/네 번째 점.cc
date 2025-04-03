#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<bool> isVisitedX(1001,0);
	vector<bool> isVisitedY(1001, 0);
	for (int i = 0; i < 3; i++)
	{
		int dotX,dotY;
		cin>>dotX>>dotY;

		isVisitedX[dotX] = !isVisitedX[dotX];
		isVisitedY[dotY] = !isVisitedY[dotY];
	}

	pair<int,int> dot;

	for (int i = 0; i < 1000; i++)
	{
		if (isVisitedX[i])
		{
			dot.first = i;
		}

		if (isVisitedY[i])
		{
			dot.second = i;
		}
	}

	cout<<dot.first<<' '<<dot.second<<'\n';

	return 0;
}
/*
3개의 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해 필요한 4점 찾는 문제..

*       *(7,7)

*       ?(7,5)
5 5
5 7
7 5

두 짝이 이루어지지 않는 값 2개를 찾는다.

*/
