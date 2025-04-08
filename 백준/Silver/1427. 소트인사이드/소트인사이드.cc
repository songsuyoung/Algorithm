#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin>>input;

	sort(input.begin(), input.end(),greater<>());

	cout<<input<<'\n';
}
