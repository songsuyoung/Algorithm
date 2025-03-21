#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int n)
{
	return (n % 4 == 0) && ((n % 100 != 0) || (n % 400 == 0));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int year;

	cin >> year;

	cout << isLeapYear(year) << '\n';
}