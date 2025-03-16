#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;

	getline(cin, input);

	string answer = "";

	for (int i = 0; i < input.size(); i++)
	{
		char ch = tolower(input[i]);
		//1. input을 대소문자 구분 없이 소문자로 변환해준다.
		if (ch >= 'a' && ch <= 'z')
		{
			int idx = ((ch - 'a') + 13) % 26;

			answer += ('a' + idx);
		}
		else
		{
			//실패한 것들, 숫자나 문자는 그냥 저장한다.
			answer += input[i];
		}

	}


	//대문자를 소문자로 바꿔준다.
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			answer[i] = toupper(answer[i]);
		}
	}
	cout << answer << '\n';
}

/*
ROT13 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만듬


0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z

B -> 13글자 밀림 -> O

문자열이 주어졌을 때 13글자를 밀어서 출력.
문제 -> 소문자, 대문자가 주어진다.

1. 소문자와 대문자를 하나의 문자로 합친다. 
소문자로 진행 -> tolower

2. 모드연산과 +13 을 사용해서 적절한 위치를 판단하는데...

'a' + (((eng[i] - 'a') + 13)%26);

'a' + 13 => N으로 변환

3. 대문자인 경우에는 toupper로 바꿔준다.

4. 출력
*/
