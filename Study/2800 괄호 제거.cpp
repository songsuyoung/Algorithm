#include <bits/stdc++.h>

using namespace std;

vector<string> res;

void recursive(int size,vector<bool> &isVisited,deque<char>& original, vector<pair<int,int>> &brackets,int selected,int idx)
{
	//base case
	if (size<=selected)
	{
		//완성
		//선택된 idx만 제거, 나머지 괄호를 제거한다.
		//처음에는 가장 큰 idx
		int idx = brackets.size() - 1;
		string output = "";
		for (int i = 0; i < original.size(); i++)
		{

			if (original[i] == '(' || original[i] == ')')
			{
				for (int j = 0; j < isVisited.size(); j++)
				{
					if (isVisited[j] && (i == brackets[j].first || i == brackets[j].second))
					{
						output += original[i];
						break;
					}
				}
			}
			else
			{
				output += original[i];
			}
		}
		res.push_back(output);
		return;

	}

	for (int i = idx; i < brackets.size(); i++)
	{
		if (isVisited[i]) continue;
		isVisited[i] = true;
		recursive(size, isVisited, original, brackets, selected + 1, i);
		isVisited[i] = false;
	}

}
int main()
{
	string s;
	cin >> s;

	stack<int> stackIdx;
	vector<pair<int, int>> bracket;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			stackIdx.push(i);
		else if (s[i] == ')')
		{
			bracket.push_back(make_pair(stackIdx.top(), i));
			stackIdx.pop();
		}
	}

	deque<char> input;
	for (int i = 0; i < s.length(); i++)
	{
		input.push_back(s[i]);
	}

	//괄호 쌍이 n개 있다면 n-1개 이내로 선택 후 출력
	vector<bool> isVisited(bracket.size(), false);
	for (int i = 0; i < bracket.size(); i++)
	{
		recursive(i, isVisited, input, bracket, 0, 0);
	}


	sort(res.begin(), res.end());

	res.erase(unique(res.begin(), res.end()), res.end());
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << '\n';
	}
}