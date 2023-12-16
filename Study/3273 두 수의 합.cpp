#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;
	vector<long long> v(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	long long left=0,right=N-1,answer=0;
	long long R;
	cin >> R;
	
	sort(v.begin(), v.end());
	while (left < right)
	{
		long long sum = v[left] + v[right];
		if (sum >= R)
		{
			if(sum==R)
				answer++;
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << answer << '\n';
	return 0;

}