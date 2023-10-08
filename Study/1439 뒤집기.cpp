#include <iostream>
using namespace std;


int main() {

	string input;
	cin >> input;

	int zeroCnt = 0;
	int oneCnt = 0;
	if (input[0] == '0') {
		zeroCnt++;
	}
	else {
		oneCnt++;
	}

	for (int i = 1; i < input.length(); i++) {
		//달라지면 vector에 push

		//1. 만약에 이전 숫자가 0인데, 이후 숫자가 1일 경우에 OneCnt를 1 증가한다.

		if (input[i - 1] == '0' && input[i] == '1')
		{
			oneCnt++;
		}
		else if (input[i - 1] == '1' && input[i] == '0') 
		{
			zeroCnt++;
		}
	}
	cout << min(oneCnt, zeroCnt);
}