#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int a,b,c,d,e,f;

	cin>>a>>b>>c>>d>>e>>f;

	for (int i = -999; i < 1000; i++)
	{
		for (int j = -999; j < 1000; j++)
		{
			long long dc = a*i+b*j;
			long long df = d*i+e*j;

			if (dc == c && df == f)
			{
				cout<<i<<' '<<j<<'\n';
				break;
			}
		}
	}
}

/*
2개인 연립방정식을 해결하는 방법에 대해 강의하고 숙제를 냄.

-900/900까지 정수를 넣을 수 있음


*/