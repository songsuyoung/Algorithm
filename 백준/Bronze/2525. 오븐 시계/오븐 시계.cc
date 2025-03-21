#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//45분 앞서는 시간으로 바꾸기
	//time의 경우 시간 - 분으로 바꾸는 것보다 시간 * 0~12 (100-1000) 단위로 분을 0~60 (0-100)사이로 배치
	int h, m;
	cin >> h >> m;

	int plus;
	cin >> plus;

	//분이 입력되어진다.

	h = (24 + (h + (m + plus) / 60)) % 24;
	m = (60 + (m + plus)) % 60;

	cout << h << ' ' << m << '\n';
}