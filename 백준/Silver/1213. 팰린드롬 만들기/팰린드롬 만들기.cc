
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
	string mid = "";
	for (int i = 26; i >= 0; i--)
	{
		if (arr[i] & 1)
		{
			//홀수 라면, 홀수는 항상 1의 자리가 1임. 짝수는 항상 1의 자리가 0임
			mid += ('A' + i);
			arr[i]--; //카운팅 배열 감소
		}
		
		for (int k = 0; k < arr[i]; k += 2)
		{
			//앞뒤로 붙여준다.
			answer = char(i+'A') + answer;
			answer += char(i + 'A');
		}
	}

	answer.insert(answer.size()/2, mid);

	if (mid.size() >= 2)
	{
		answer = "I'm Sorry Hansoo";
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