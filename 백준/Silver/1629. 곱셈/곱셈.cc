#include <bits/stdc++.h>
using namespace std;

long long A,B,C;
	
long long func(long long A,long long B)
{
	if(B==1) return A%C;
	long long ret =func(A,B/2)%C;
	ret = (ret*ret)%C; 
	
	if(B%2) 
		ret = (ret*A)%C; 
	return ret;
}
int main()
{
	cin>>A>>B>>C;
	
	cout<<func(A,B);
	return 0;
}