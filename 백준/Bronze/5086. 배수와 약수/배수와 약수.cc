#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	while (true)
	{
		int answer = 0;

		int num1, num2;

		cin>>num1>>num2;

		if(num1 == 0 && num2 == 0) break;

		if (num2 % num1 == 0)
		{
			//약수이다.
			answer=1;
		}
		else if (num1 % num2 == 0)
		{
			//배수이다.
			answer = 2;
		}

		switch (answer)
		{
			case 0:
				cout<<"neither\n";
			break;
			case 1:
				cout << "factor\n";
			break;
			case 2:
				cout << "multiple\n";
			break;
		}
	}
}
