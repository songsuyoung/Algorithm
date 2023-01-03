#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int input;
	cin >> input;
    
    while(input){
        input--;
	int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
	
	double distance=pow(x2-x1,2)+pow(y2-y1,2);
	int Sum=pow(r1+r2,2);
	int Sub=r1-r2>0? r1-r2:r2-r1;
	Sub*=Sub;

	if(r1==r2&distance==0){
		cout<<-1<<endl;
	}else if(Sum==distance||Sub==distance){
		cout<<1<<endl;
	}else if(Sub<distance&&distance<Sum){
		cout<<2<<endl;
	}else
		cout<<0<<endl;
    }

    return 0;
}
