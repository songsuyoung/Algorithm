#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string first, second;

	cin >> first >> second;

	int maxLen = first.size()>second.size()? first.size() : second.size();

	//123
	for (int i = first.size(); i < maxLen; i++)
	{
		first.insert(0,"0");
	}

	//500 => 005로 만들어준다
	for (int i = second.size(); i < maxLen; i++)
	{
		second.insert(0,"0");
	}

	string output = "";
	int carry = 0;
	for(int i= maxLen-1; i>=0; i--)
	{
		int sum = ((first[i] - '0') + (second[i] - '0')) + carry; //숫자로 변환

		carry = sum / 10; //다음 캐리가 있는지 확인
		sum -= (10 * carry);
		output += (sum + '0');
	}

	if (carry)
	{
		output += (carry + '0');
	}

	reverse(output.begin(), output.end());

	cout << output << '\n';
}