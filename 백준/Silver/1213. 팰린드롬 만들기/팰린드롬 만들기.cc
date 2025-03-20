
#include <bits/stdc++.h>
using namespace std;


int arr[26]; //counting arr

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		arr[input[i] - 'A']++; //대문자 배열밖에 없음.
	}

	//절반을 만든다. (앞글자)
	string answer = "";
	string odd = "";

	for (int i = 0; i < 26; i++)
	{
		int cnt = arr[i] / 2;

		if (arr[i] % 2 == 1)
		{
			//홀수를 가운데에 배치하기 위해 빼놓는다.
			odd += 'A' + i;
			arr[i] -= 1; //짝수로 만든다.
		}
		arr[i] -= cnt;
		for (int j = 0; j < cnt; j++)
		{
			answer += 'A' + i;
		}
	}
	
	if (odd.size() >= 2)
	{
		//홀수가 2개 이상이라면, 이 값을 사용해 팰린드롬을 만들 수 없다.
		answer = "I'm Sorry Hansoo";
	}
	else
	{
		answer += odd; //홀수를 먼저 배치한다.

		//절반을 만든다. (뒷글자)
		for (int i = 26; i >= 0; i--)
		{
			int cnt = arr[i];

			for (int j = 0; j < cnt; j++)
			{
				answer += 'A' + i;
			}
		}
	}

	cout << answer << '\n';
}


/*
임한수와 임문빈은 서로 사랑하는 사이..
임한수의 영어 이름의 알파벳 순서를 적절히 바꿔 팰린드롬으로 만들려고 한다.

예)
AABB

-> 조건 : 여러 개 일 때 사전 순으로
A 2
B 2

그러면, 현재 개수 4개


AAAABBCC

2/2 => 1

A 4/2 
B 2/2
C 2/2

하나씩 쌓아감?

AABBCCAA


AAABB

A 3/2 => 2개
B 2/2 => 1개

ABABA

1. 수를 센다..
2. 절반만 반복문을 돈다..
3. 뒤부터 다시 반복문을 돈다. (절반씩 놓는다..)

ABBA => 팰린드롬이고, 남은 수가 1개라면 OK
이미 홀 수 인데, 남은 수가 1개라면 No
팰린드롬이 아닌데, 남은 수가 1개라면 No
*/