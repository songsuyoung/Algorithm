#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M, answer = 0;
	cin >> N>>M;

	string bufferflush;
	getline(cin, bufferflush);


	string str;
	cin >> str;

	string pattern = "IOI";
	int idx = 0,cnt=0;
	vector<int> cnts;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == pattern[idx])
		{
			cnt++;
			idx++;
			if (idx >= pattern.length())
				idx = 1;
		}
		else
		{
			if(cnt!=0)
				cnts.push_back(cnt);
			
			if (str[i] == 'I')
			{
				//I일 때 
				idx = 1;
				cnt = 1;
			}
			else
			{
				idx = 0;
				cnt = 0;
			}
		}
	}
	if(cnt!=0)
		cnts.push_back(cnt);

	for (int i = 0; i < cnts.size(); i++)
	{
		idx = 0;

		if (cnts[i] >= (2*N+1))
		{
			int num=(cnts[i] - 1) / 2;
			answer+=num - (N - 1);
		}
	}
	cout << answer << '\n';
}
