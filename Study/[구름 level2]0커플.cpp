#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool compare(int a,int b)
{
	return abs(a)<abs(b);
}
int main() {
	
	int N;
	cin>>N;
	
	vector<int> arr(N);
	
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	
	sort(arr.begin(),arr.end(),compare);
	
	int sum=0;
	
	for(int i=0;i<arr.size()-1;)
	{
		if(arr[i]!=arr[i+1])
		{
			sum+=arr[i];
			sum+=arr[i+1];
		}
		i+=2;
	}
	
	cout<<sum<<'\n';
	return 0;
}