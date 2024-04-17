#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<string> nums; //알아서 정렬할 수 있도록 priority_queue 사용

bool compare(string &a,string &b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void remove(queue<char> &q)
{
	string output = "";
	while (!q.empty())
	{
		if (q.size() != 1 && output.length() == 0 && q.front() == '0')
		{
			q.pop();
			continue;
		}
		output += q.front();
		q.pop();
	}

	if (output.length() != 0)
	{
		nums.push_back(output);
	}
}
int main()
{
	long long N;
	cin >> N;

	queue<char> q;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] >= '0' && input[i] <= '9')
			{
				q.push(input[i]);
			}
			else
			{
				remove(q);
			}
		}

		remove(q);
	}

	sort(nums.begin(), nums.end(), compare);

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << '\n';
	}
}