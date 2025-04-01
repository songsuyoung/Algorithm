#include <bits/stdc++.h>
using namespace std;

bool compare(string& a, string& b)
{
	if (a.size() == b.size())
	{
		return a<b;
	}
	return a.size()<b.size();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;

	cin>>TC;

	vector<string> v;
	for (int t = 0; t < TC; t++)
	{
		string input;
		cin>>input;

		string output="";
		for (int i = 0; i < input.size(); i++)
		{
			char ch = input[i];

			if (ch>='0'&&ch<='9')
			{
				output+=ch;
			}
			else
			{
				if (output.empty() == false)
				{
					v.push_back(output);
					output = "";
				}
			}
		}

		if (output.empty() == false)
		{
			v.push_back(output);
			output = "";
		}
	}

	vector<string> nums;

	for (int i = 0; i < v.size(); i++)
	{
		int pre = 0;
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] != '0')
			{
				pre = j;
				break;
			}
		}

		if (pre == 0 && v[i][0] == '0')
		{
			pre=v[i].size()-1;
		}

		nums.push_back(v[i].substr(pre, v[i].size()));
	}

	sort(nums.begin(),nums.end(), compare);

	for (int i = 0; i < nums.size(); i++)
	{
		cout<< nums[i]<<'\n';
	}

}

/*
상근이는 숫자를 모두 찾은뒤 비내림차순으로 정렬

예

01
2
3456
478
*/

