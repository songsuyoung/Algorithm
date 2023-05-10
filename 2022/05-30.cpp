#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int n;
	cin>>n;

	vector<int> num;

	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		num.push_back(k);
	}
	sort(num.begin(),num.end());

	int search;
	cin >> search;

	if(binary_search(num.begin(),num.end(),search)==1){
		cout<<"0"<<endl;
	}else{
		int cnt=0;
		int i=0;
		for(;i<num.size();i++){	
			if(search<num[i]){
				break;
			}
		}

		int k=(num[i-1]!=search-1)? num[i-1]+1:search;
		
		for(;k<=search;k++){
			for(int j=search;j<num[i];j++){
				if(k==j)
					continue;
				cnt++;
			}
		}

		cout<<cnt<<endl;
	}
}
