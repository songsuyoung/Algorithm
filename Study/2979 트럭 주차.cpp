#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int,int> carInEx;
	
	vector<int> money(4,0);
	
	for(int i=1;i<=3;i++)
	{
		cin>>money[i];
	}
	
	for(int i=0;i<3;i++)
	{
		int start,end;
		cin>>start>>end;
		for(int time=start;time<end;time++)
		{
			carInEx[time]++;
		}
	}
	
	int sum=0;
	for(auto time : carInEx)
	{
		sum+=(money[time.second]*time.second);
	}
	cout<<sum<<'\n';
}
