#include <iostream>
using namespace std;

int main(){

	int prizeMoney;
	cin>>prizeMoney;

	int tax=prizeMoney*0.22;
	int recTax=prizeMoney*0.80;
	recTax=(prizeMoney-recTax)*0.22;
	
	cout<<prizeMoney-tax<<" "<<prizeMoney-recTax<<endl;
}
