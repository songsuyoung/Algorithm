#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	vector<long long> city;
	vector<long long> lm;

	for (long long i = 0; i < N - 1; i++)
	{
		long long l;
		cin >> l;
		lm.push_back(l);
	}

	for (long long i = 0; i < N; i++)
	{
		long long money;
		cin >> money;
		city.push_back(money);
	}

	 
	long long thresh = city[0];
	long long sum = 0;
	long long preVal=0,val = 0;
	for (int i = 0; i < N-1; i++)
	{
		if (thresh > city[i])
		{
			val = preVal;
			thresh = city[i];
			sum = 0;
		}
		sum += lm[i];
		preVal=min(val + sum * thresh, preVal + lm[i] * city[i]);
	}

	cout << preVal << '\n';
}