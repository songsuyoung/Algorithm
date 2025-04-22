#include <bits/stdc++.h>
using namespace std;

int oper(int num1, int num2, char op)
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

void recursive(vector<int>& num, vector<char> &op, int idx, int sum)
{
	if (op.size() <= idx)
	{
		answer = max(answer, sum);
		return;
	}
	//선택 안한다. => 즉 바로 계산
	recursive(num, op, idx+1, oper(sum, num[idx+1], op[idx]));

	// 두칸 떨어진거 선택 => ㄴㄴ 먼저 계산하고 앞에꺼와 계산
	if (idx + 2 < num.size())
	{
		//선택한다. => 현재꺼 말고 다른 걸 먼저 계산
		int temp = oper(num[idx + 1], num[idx + 2], op[idx + 1]); //다음거 먼저 계산
		recursive(num, op, idx + 2, oper(sum, temp, op[idx])); //현재거 계산 후 현재, 다음을 건너뜀 -> 2칸, idx+2를 넘김
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

	vector<int> num;
	vector<char> op;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			num.push_back(input[i]-'0');
		}
		else
		{
			op.push_back(input[i]);
		}
	}

	recursive(num, op, 0, num[0]);

	cout<<answer<<'\n';
}

/*
정수와 연산자 +,-,* 연산자 우선순위는 모두 같음. => 완전 탐색 - 최댓값
무엇부터 계산하는지에 따라서 연산이 달라짐.

1. operation 뽑아냄.
2. operator 뽑아냄.
-> operator를 기준으로 while문 
-> 연산자 1개, 숫자 2개를 업데이트
-> 마지막 값 저장하고 answer에 max값 저장. 


* op랑 num값이 존재할 때 실제로의 경우의 수
* 1. 현재 idx를 먼저 계산한다.
* 2. 다음 idx를 먼저 계산한다.
*	-> 이 경우를 만족하려면 다음 idx의 숫자 num[idx+1]값과 num[idx+2] 값이 존재해야한다.
* 
* 두 경우의 수를 체크하면 풀 수 있는 문제..
*/