#include <bits/stdc++.h>
using namespace std;

vector<string> answer;
void recursive(vector<char>& op, vector<bool>& isVisited, int idx, string num)
{
	if (idx >= op.size())
	{
		//초과함
		answer.push_back(num);
		return;
	}

	int tmp = num[num.size()-1] - '0';

	for (int i = 0; i < 10; i++)
	{
		if(isVisited[i]) continue;

		if ((op[idx] == '<' && tmp < i) || (op[idx] == '>' && tmp > i))
		{
			isVisited[i] = true;
			recursive(op, isVisited, idx + 1, num + to_string(i));
			isVisited[i] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	vector<char> v(N);
	for (int i = 0; i < N; i++)
	{
		cin>>v[i];
	}

	for (int i = 0; i < 10; i++)
	{
		//10개 중 하나를 선택한다.
		vector<bool> isVisited(10, false);

		isVisited[i] = true;
		recursive(v, isVisited, 0, to_string(i));
	}

	cout<<answer[answer.size()-1]<<'\n';
	cout<<answer[0]<<'\n';
}

/*
 부등호 종류 < >
 k개 나열된 순서열 A

 부등호 앞 뒤에 서로 다른 한 자릿 수 숫자를 넣어서 모든 부등호 관계를 만족하려고 한다.

 예)

 <<<><<><>
 3 4 5 6 1 2 8 ...
 숫자는 모두 달라야한다. => 방문 처리
 10개 중 선택

 부호가 2개면 숫자는 3개 넣을 수 있음 => string으로 관리
 만족하는 최댓값과 최솟값. 

 => 일단 모두 다 선택해 본다.
*/