#include <bits/stdc++.h>
using namespace std;

int cnt;
int recursive(string& str, int l, int r)
{

	cnt++;
	if (l >= r)
	{
		return 1;
	}

	if (str[l] != str[r])
	{
		return 0;
	}


	return recursive(str, l+1, r-1);
}

bool isPalindrome(string& str)
{
	return recursive(str, 0, str.size()-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin>>N;

	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin>>str;

		cnt = 0;

		bool isSuccess = isPalindrome(str);

		cout<<isSuccess<<' '<<cnt<<'\n';
	}
}
