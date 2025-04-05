#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	int arr[3];
	
	cin>>arr[0]>>arr[1]>>arr[2];

	sort(arr,arr+3);

	if (arr[0] + arr[1] <= arr[2])
	{
		//두 변의 길이가 한변의 길이보다 작거나 같으면 삼각형 조건에 맞지않는다.
		//arr[0] + arr[1] > arr[2]  조건이 맞음
		//즉, arr[0] + arr[1] == arr[2] + 1 과 같은 것
		// arr[0]+arr[1] - 1 == arr[2] 최댓값을 이룸
		arr[2]=arr[0]+arr[1]-1;
	}

	cout<<arr[0]+arr[1]+arr[2]<<'\n';
	return 0;
}