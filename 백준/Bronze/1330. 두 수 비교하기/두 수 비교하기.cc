#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B;
	cin >> A >> B;

	if (A < B)
	{
		cout << "<\n";
	}
	else if (A == B)
	{
		cout << "==\n";
	}
	else
	{
		cout << ">\n";
	}
}