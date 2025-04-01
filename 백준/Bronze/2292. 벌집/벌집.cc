#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//6*i 등비수열
	int input;
	cin>>input;

	int answer = 1;
	long long sum=2;
	
	for (int i=0; sum <= input; i++)
	{
		sum += (6 * i); //등비 수열
		answer = i;
	}

	answer++;
	if (input == 1)
	{
		answer=1;
	}

	cout<<answer<<'\n';
}

/*

 +3 +4 +

*/

