#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	vector<int> num;

	int cnt;

	cin>>cnt;

	for(int i=0;i<cnt;i++){
		int k;
		cin>>k;
		num.push_back(k);
	}

	int max=*max_element(num.begin(),num.end());
	int min=*min_element(num.begin(),num.end());

	cout<<max*min<<endl;
	
	return 0;
}
