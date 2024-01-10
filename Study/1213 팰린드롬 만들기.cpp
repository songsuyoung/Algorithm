#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{

	string input;
	cin >> input;

	vector<int> frequency(26, 0);
	for (int i = 0; i < input.length(); i++) {
		frequency[input[i]-'A']++;
	}
	
	deque<char> output;
	while (output.size()<input.length())
	{
		//빈도수가 홀수인것을 찾는다.
		//먼저 배치한다.
		int oddCnt=0;
		for (int i = frequency.size()-1; i>=0; i--)
		{
			if (frequency[i] % 2 != 0)
			{
				oddCnt++;
				output.push_back(i + 'A');
			}
		}

		if (oddCnt >= 2)
		{
			cout << "I'm Sorry Hansoo\n";
			return 0;
		}

		for (int i = frequency.size() - 1; i >= 0; i--)
		{
			for (int j = frequency[i] / 2; j > 0; j--)
			{
				output.push_front(i + 'A');
				output.push_back(i + 'A');
			}

			frequency[i] = 0;
		}

	}

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i];
	}
	cout << '\n';
	return 0;
}