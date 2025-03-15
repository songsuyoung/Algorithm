#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	int answer = 1;
	
	//1을 뺐기 때문에 짝수 -> 홀수 /홀수 -> 짝수가 된다. 
	int len = input.size() - 1;

	// 원래 짝수일 경우에는 +1 해주고, 아닐 경우에는 가운데 값을 계산할 필요가 없다(짝이 없기때문)
	int iter = len % 2 == 0 ? (len / 2) : (len / 2) + 1;

	for (int i = 0; i < iter; i++)
	{
		
		if (input[i] != input[len - i])
		{
			answer = 0; //팰린드롬 아님
			break;
		}
	}

	cout << answer << '\n';
}

/*
알파벳 소문자로 이루어진 단어 주어짐.

예)

반복은 len/2만큼 돌면된다 즉. 2번
len = 5-1
i = 0
arr[i] == arr[len-i] ? 
0 1 2 3 4 
level
0 1 2 3
noon

len = 3; => 1번
i = 0

len-0 =>3, 0비교 1-2번 비교
팰린드롬 (i len-i)


*/