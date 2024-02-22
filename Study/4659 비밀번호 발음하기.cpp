#include <bits/stdc++.h>
using namespace std;

//모음 

set<char> vowels = { 'a','e','i','o','u' };
bool recursive(string input, char cur, char pre, int vowelsCnt,int consonantCnt,bool &isVowels,int idx)
{
	if (vowelsCnt >=3 || consonantCnt>=3 || ((pre == cur) && (cur != 'e' && cur != 'o'))) //ee oo는 가능하기 때문임.
	{ 
		//모음이 3개거나 자음이 3개 연속이면.
		return false;
	}

	if (idx >= input.length())
	{
		return true;
	}
	bool isVowel = vowels.find(cur) != vowels.end();
	bool isPreVowel = vowels.find(pre) != vowels.end();
	if (isVowel && isPreVowel) //모음 모음
	{
		vowelsCnt++;
	}
	else if (isVowel && isPreVowel == false) //모음 자음
	{
		isVowels = true;
		vowelsCnt = 1;
		consonantCnt = 1;
	}
	else if (isVowel == false && isPreVowel) //자음
	{
		vowelsCnt = 1;
		consonantCnt = 1;
	}
	else //자음 자음
	{
		consonantCnt++;
	}

	bool result=recursive(input, input[idx+1], cur, vowelsCnt, consonantCnt, isVowels,idx+1);

	return result;
	//모음에 속해있어? -> isVowels true
	//이전 글자가 모음인데, 현재 글자가 자음이라면 모음cnt=0, 자음cnt++
	//이전 글자가 자음인데, 현재 글자도 자음이라면 자음cnt++
	//이전 글자가 자음인데, 현재 글자가 모음이라면 자음cnt=0, 모음cnt++
	//이전 글자가 모음인데, 현재 글자가 모음이라면 cnt++

}
int main()
{
	//모음 반드시 하나를 포함한다.
	//모음 3개, 자음 3개 연속 불가능.
	//같은 글자가 연속적으로 두번 오면 안되나, ee,oo는 허용한다.
	

	while (true)
	{
		string input;

		cin >> input;

		if (input == "end") break;
		bool isVowels = false;
		bool result = recursive(input, input[0], ' ', 0,0, isVowels, 0) && isVowels == true;
		
		if (result)
		{
			cout << "<"<<input << "> is acceptable.\n";
		}
		else
		{
			cout << "<" << input << "> is not acceptable.\n";
		}
	}

}