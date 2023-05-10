#include <iostream>
using namespace std;

int main(){
	int A,B;
	cin>>A>>B;

	string result = A>B? ">":(A<B)? "<":"==";

	cout<<result<<endl;
}
