#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool check(int counting[], int threshold[])
{
	for(int i=0; i<4; i++)
	{
		if (counting[i] < threshold[i])
		{
			return false;
		}
	}
	return true;
}
int char2idx(char ch)
{
	if (ch == 'A') return 0;
	if (ch == 'C') return 1;
	if (ch == 'G') return 2;
	if (ch == 'T') return 3;
	return -1;
}

int counting[4];
int threshold[4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int S, P;
	cin >> S >> P;

	//부분 문자열 만큼
	string input;

	cin >> input;

	cin >> threshold[0] >> threshold[1] >> threshold[2] >> threshold[3];

	int answer = 0;

	for (int i = 0; i < P; i++)
	{
		int idx = char2idx(input[i]);

		if (idx == -1) continue;

		counting[idx]++;
	}

	if (check(counting, threshold))
	{
		answer++;
	}

	for (int i = P; i < input.size(); i++)
	{
		int preIdx = char2idx(input[i - P]);
		int Idx = char2idx(input[i]);

		if (preIdx != -1)
		{
			counting[preIdx]--;
		}

		if (Idx != -1)
		{
			counting[Idx]++;
		}
		
		if (check(counting, threshold))
		{
			answer++;
		}
	}
	
	cout << answer << '\n';
}


/*
DNA 문자열은 모든 문자열에 등장하는 문자가 A C G T 인 문자열을 말함.
예) A C K A DNA 문자열은 아니지만 ACCA는 DNA 문자열이다.

임의로 A만 뽑을 경우 보안에 취약..

예를 들어, 

DNA 문자열이 A A A C C T G C C A A 이고,  1,000,000 =>백만
민호가 뽑은 부분 문자열의 길이가 4라고 하자... => 4개 .. 

A 1개 이상, C 1개 이상, G 1개 이상, T 0개 이상..

이때 AAAC
AACC
ACCT

GCCA
만들 수 있는 수 구하는 방법..

[A] -- => A++ => 3
[C] -- => 

*/