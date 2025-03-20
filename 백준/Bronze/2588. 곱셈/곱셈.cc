#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string num1, num2;
	cin >> num1 >> num2;

	vector<int> nums;
	int dec = 1;
	for (int i = num2.size() - 1; i >= 0; i--)
	{
		int carry = 0;
		long long mult = 0;
		string answer = "";
		for (int j = num1.size() - 1; j >= 0; j--)
		{
			mult = (num1[j] - '0') * (num2[i] - '0') + carry;
			carry = mult / 10;
			answer += to_string(mult % 10);
		}
		answer += to_string(carry);
		reverse(answer.begin(), answer.end());
		cout << stoi(answer) << '\n';
		nums.push_back(stoi(answer) * dec);
		dec *= 10;
	}

	int answer = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		answer += nums[i];
	}

	cout << answer << '\n';
}
