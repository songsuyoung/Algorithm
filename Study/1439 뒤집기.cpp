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
		//�޶����� vector�� push

		//1. ���࿡ ���� ���ڰ� 0�ε�, ���� ���ڰ� 1�� ��쿡 OneCnt�� 1 �����Ѵ�.

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