#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	
	int N;
	cin>>N;
	
	int sum=0;
	for(int i=0;i<N;i++)
	{
		int tmp;
		cin>>tmp;
		sum+=tmp;
	}
	
	string output="";
	while(sum!=0)
	{
		output+=to_string(sum%8);
		sum/=8;
	}
	
	reverse(output.begin(),output.end());
	
	cout<<output<<'\n';
	
	return 0;	
}