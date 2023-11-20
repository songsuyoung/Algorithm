#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<bool> res;

	vector<bool> input(N,0); //N개를 0으로
	for (int i = 0; i < N; i++)
	{
		bool tmp;
		cin >> tmp;
		res.push_back(tmp);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (res[i] != input[i])
		{
			input[i] = !input[i];
			if(i+1<N)
				input[i + 1] = !input[i+1];
			if(i+2<N)
				input[i + 2] = !input[i+2];
			cnt++;
		}
	}

	cout << cnt << '\n';

	// 0 0 1 1 1 0 0
	// 0 0 1 0 0 1 0
}