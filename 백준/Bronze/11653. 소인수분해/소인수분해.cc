#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//소인수 분해를 하려면... 최소 공배수를 찾아야함.
	int N;
	cin>>N;

	for (int i = 2; i <= N; i++)
	{
		while (N % i == 0)
		{
			//소수
			N/=i;
			cout<<i<<'\n';
		}
	}
	return 0;
}
