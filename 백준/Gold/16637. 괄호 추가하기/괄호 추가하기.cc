#include <bits/stdc++.h>
using namespace std;

int operate(int num1, int num2, char op)
{
	switch (op)
	{
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
	}
}
int answer = INT_MIN;
void recursive(vector<int>& number, vector<char>& op, int idx, int sum)
{
	if (idx >= op.size())
	{
		//선택할 수 없음.
		answer = max(answer, sum);
		return;
	}

	//옆에 있는걸 선택한다.
	recursive(number, op, idx + 1, operate(sum, number[idx + 1], op[idx]));

	if (idx + 2 < number.size())
	{
		//멀리 있는걸 먼저 계산 한다.
		int num = operate(number[idx + 1], number[idx + 2], op[idx + 1]);

		recursive(number, op, idx+2, operate(sum, num, op[idx])); //3만큼 뛰어넘음
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	string input;
	cin>>input;

	//op과 number를 나눈다.
	vector<char> op;
	vector<int> number;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			number.push_back(input[i]-'0'); //숫자로 변환한다.
		}
		else
		{
			op.push_back(input[i]);
		}
	}

	recursive(number, op, 0, number[0]); //0은 항상 포함한다. 왜냐면 시작점이기때문 

	cout<<answer<<'\n';
}

// num num1 num2
//    +    *

//   num1 * num2 먼저 계산
//   + num