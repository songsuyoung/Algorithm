#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_set<char> vowels = { 'a','e','i','o','u' };
//자음과 모음이 3글자 이상 연속으로 나오는지 확인하는 함수
bool isCheck(const string& input)
{
	//모음 개수
	int vCnt = 0;
	bool bIsVowels = false;
	//자음 개수
	int cCnt = 0;
	
	//vowels 개수가 아예 없는지도 확인.
	int cnt = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (vowels.count(input[i]))
		{
			//모음인데,
			if (bIsVowels == false)
			{
				//모음인데 이전에 모음이 아니었으면
				bIsVowels = true;
				cCnt = 0;
			}
			vCnt++;
			cnt++;
		}
		else
		{
			//자음인데,
			if (bIsVowels)
			{
				//이전에 모음이었으면
				bIsVowels = false;
				vCnt = 0;
			}
			cCnt++;
		}

		if (cCnt >= 3 || vCnt >= 3)
		{
			return false;
		}
	}

	//모음이 하나도 없음
	if (cnt <= 0)
	{
		return false;
	}

	return true;
}

bool dfs(const string& input, int idx)
{
	if (input.size() <= idx + 1)
	{
		return true;
	}
	
	if (input[idx] == input[idx + 1])
	{
		if (input[idx] == 'e' || input[idx] == 'o')
		{
			return true;
		}
		return false;
	}
	
	bool res = dfs(input, idx + 1);

	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;

	while (true)
	{
		cin >> input;

		if (input == "end")
		{
			break;
		}

		cout << "<" << input << ">";

		if (isCheck(input))
		{
			//ee,oo를 제외한 나머지 글자는 연속으로 오면 안된다.
			bool bIsRes = dfs(input, 0);

			if (bIsRes)
			{
				cout << " is acceptable.\n";
			}
			else
			{
				cout << " is not acceptable.\n";
			}
		}
		else
		{
			cout << " is not acceptable.\n";
		}
	}
}

/*
* 좋은 비밀번호 => buddy 발을 하기 좋고, 쉬운 패스워드를 원하나 이런 패스워드는 보안의 문제
* 발음 가능함.
* 
* a,e,i,o,u 중 하나를 반드시 포함
* 모음이 3개 혹은 자음이 3개 연속으로 나오면 안된다. => 연속 체크
* 같은 글자가 연속적으로 두번 오면 안되나 ee, oo 허용
* 
* 테스트 케이스에 대해 검사
*/