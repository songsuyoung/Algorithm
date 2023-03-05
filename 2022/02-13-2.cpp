#include <iostream>
using namespace std;

bool leapYear(int year){

	if(!(year%4)){
		if((year%100)||!(year%400)){
			return true;
		}
	}

	return false;
}
int main(){
	
	int year;

	cin>>year;

	cout<<leapYear(year)<<endl;

}
