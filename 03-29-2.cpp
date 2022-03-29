
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    string number;
    int N;

    cin>>N>>number;

    int sum=0;
    for(int i=0;i<N;i++)
	sum+=(int)number[i]-'0';
	cout<<sum<<endl;    
    return 0;   
}
