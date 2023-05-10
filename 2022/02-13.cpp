#include <iostream>
using namespace std;

int main(){
	
	int A,B,C;


	cin>>A>>B>>C;

	A=A+(B+C)/60;
	B=(B+C)%60;

	if(A>=24){
		A%=24;
	}
	cout<<A<<" "<<B<<endl;

	return 0;
}

