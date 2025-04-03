#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int X,Y,Z;
	cin>>X>>Y>>Z;

	if (X == Y && Y == Z && Z == 60)
	{
		cout<<"Equilateral\n";
	}
	else
	{
		int Res = X+Y+Z;

		if (Res != 180)
		{
			cout<<"Error\n";
		}
		else
		{
			if (X == Y || Y == Z || X == Z)
			{
				cout<<"Isosceles\n";
			}
			else
			{
				cout << "Scalene\n";
			}
		}
	}
	return 0;
}