#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int money;
	cin >> money;

	money = 1000 - money; //거스름돈 받아야함.
	//500 -> 100 -> 50 -> 10 -> 5 -> 1
	//   /5     /2     /5   /2   /5
	// 1     2      3     4   5   6 => 홀수일 때 /5 짝수일 때 /2

	int changesCnts=0;

	int changes = 500,k=5,cnt=0;
	while (money != 0)
	{
		if ((cnt % 2) != 0) k = 2;
		else
			k = 5;

		changesCnts += (money / changes);
		money %= changes;
		changes /= k;
		cnt++;
	}

	cout << changesCnts << '\n';
}