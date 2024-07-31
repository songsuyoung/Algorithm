#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{

	string A, B;
	cin >> A >> B;

	string output = "";

	if (A.length() < B.length())
		swap(A, B);

	int len = A.length() - B.length(); //수가 나옴
	//for문은 B가 기준으로 돌아간다.

	int num = 0;
	int idx = 0;
	for (int i = B.length() - 1; i >= 0; i--)
	{
		idx = i + len;
		int a = A[idx] - '0';
		int b = B[i] - '0';

		int sum = a + b + num;
		num = sum / 10; //올림 수 있으면 더할 예정
		output += (sum % 10) + '0';
	}

	for (idx-=1; idx >= 0; idx--)
	{
		int sum = (A[idx] - '0') + num;
		num = sum / 10; //올림 수 있으면 더할 예정
		output += (sum % 10) + '0';
	}

	if (num != 0)
	{
		output += num + '0';
	}
	
	for (int i = output.length() - 1; i >=0;i--)
	{
		cout << output[i];
	}
}