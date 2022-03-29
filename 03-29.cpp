#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){

    vector<int> num;

    for(int i=1;i<46;i++){
	for(int j=0;j<i;j++){
	    num.push_back(i);
	}
    }

    int num1,num2;

    cin>>num1>>num2;
    cout<<accumulate(&num[num1-1],&num[num2],0);

    
}
