#include <bits/stdc++.h>
using namespace std;

void cantor(string& str, int left, int right)
{
	if (right - left <= 1) //3보다 작으면 진행 안함. 
	{
		//도달 모든 선의 길이가 1
		return;
	}

	int N = (right-left)/3; //0+26 => 26/3 => 8 / (0+8)/3 => 2 / (2/3 => 0
	
	for (int i = left + N + 1; i < right - N; i++)
	{
		str[i] = ' ';
	}

	cantor(str, left, left+N); //0, 8 => 0,2 - 6, 8 => 0, 2, 6, 8

	cantor(str, right-N, right); //18, 26 (포함) => 18,21 
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//미리 string N^3 만큼 만든다.
	
	int N;
	while (cin >> N)
	{
		N = pow(3,N);
		
		string str = "";

		for (int i = 0; i < N; i++)
		{
			str+="-";
		}

		cantor(str, 0, str.size()-1);
		cout<<str<<"\n";
	}
}
