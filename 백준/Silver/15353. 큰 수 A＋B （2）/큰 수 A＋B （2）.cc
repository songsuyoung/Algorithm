#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string first, second;

	cin>>first>>second;

	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());

	string output="";
	int i = 0;
	int carry = 0;
	while (i < first.size() && i < second.size())
	{
		int sum = ((first[i]-'0') + (second[i] - '0')) + carry; //숫자로 변환

		carry = sum / 10; //다음 캐리가 있는지 확인
		sum -= (10*carry);
		output+=(sum+'0');
		i++;
	}

	for (; i < first.size(); i++)
	{
		int sum = (first[i]-'0') + carry;
		carry = sum / 10; //다음 캐리가 있는지 확인
		sum -= (10 * carry);
		output += (sum + '0');
	}

	for (; i < second.size(); i++)
	{
		int sum = (second[i] - '0') + carry;
		carry = sum / 10; //다음 캐리가 있는지 확인
		sum -= (10 * carry);
		output += (sum + '0');
	}

	if (carry)
	{
		output+=(carry+'0');
	}

	reverse(output.begin(), output.end());
	cout<<output<<'\n';
}

/*
오큰수..

*/