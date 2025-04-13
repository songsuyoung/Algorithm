#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int N;
	cin>>N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
	}

	sort(arr.begin(), arr.end()); //2 3 4 6 8 12 => 0 * 끝번이랑 곱함 => 24

	int begin = 0;
	int last = arr.size()-1;
	
	cout<<arr[begin]*arr[last]<<'\n';


}
