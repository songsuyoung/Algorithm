#include <vector>
#include <iostream>
using namespace std;
int main() {
	
	int N,M;
	cin>>N>>M;
	
	vector<int> v(N,0);
	
	for(int i=0;i<N;i++) //1,000
	{
		cin>>v[i];
	}
	
	vector<bool> isFall(N,0);
	for(int i=0;i<M;i++) //100,000
	{
		int st,ed;
		
		cin>>st>>ed;
		
		for(int j=st-1;j<ed;j++) //최악의 경우 1,000
		{
			v[j]+=1;
			isFall[j]=true;
		}//비가 내리고
		
		if((i+1)%3 == 0) //3의 배수 날에 비온 지역만 -1
		{
			for(int j=0;j<N;j++)
			{
				if(isFall[j])
				{
					v[j]-=1;
					isFall[j]=false;
				}
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		cout<<v[i]<<' ';
	}
	return 0;
}