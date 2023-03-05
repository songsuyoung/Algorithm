#include <iostream>
using namespace std;

int main(){
	
	int A,B,C,D;


	cin>>A>>B>>C>>D;
	A=A+(B+((C+D)/60))/60;
	B=B+((C+D)/60);
	C=(C+D)%60;
	
	if(C>=60){
		B=B+C/60;
		C%=60;
	}
	if(B>=60){
		B%=60;
	}

	if(A>=24){
		A%=24;
	}
	cout<<A<<" "<<B<<" "<<C<<endl;

	return 0;
}

