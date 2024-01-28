#include <bits/stdc++.h>
using namespace std;
int N;
int main()
{
	cin>>N;
	vector<int> solution(N,0);

	for(int i=0;i<solution.size();i++)
	{
		cin>>solution[i];	
	}
	int left=0,right=solution.size()-1;
	
	long long minVal= LONG_MAX;
	pair<int,int> min;
	while(left<right)
	{
		long long sum = solution[left]+solution[right];
		
		if(abs(sum)<=abs(minVal))
		{
			minVal=sum;
			min=make_pair(solution[left],solution[right]);
		}
		
		if(sum<0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	
	cout<<min.first<<' '<<min.second<<'\n';
	return 0;
}