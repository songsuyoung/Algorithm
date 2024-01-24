#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <regex>
using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;

	int sum=0;
	vector<int> v(N);

	for(int i=0;i<N;i++)
	{
		cin>>v[i];
	}

	for(int i=0;i<K;i++)
	{
		sum+=v[i];
	}

	int maxSum=sum;

	for(int r=K,l=0;r<N;r++,l++)
	{
		sum-=v[l];
		sum+=v[r];

		maxSum=max(maxSum,sum);
	}
	cout<<maxSum<<'\n';

	return 0;
}
/*
수열 

방법 슬라이딩 윈도우 or two pointer 를 이용해서 O(N) 연산을 수행.
그리고 Sum 가장 클 때 maxSum을 교체해준다.
*/