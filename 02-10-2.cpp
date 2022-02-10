#include <iostream>
using namespace std;

int main(){
	int homeToSchool;
	int SchoolToPc;
	int PcToPEI;
	int PEIToHome;

	int minute;
	int second;

	cin>>homeToSchool>>SchoolToPc>>PcToPEI>>PEIToHome;
	
	minute=homeToSchool/60+SchoolToPc/60+PcToPEI/60+PEIToHome/60;
	second=(homeToSchool%60+SchoolToPc%60+PcToPEI%60+PEIToHome%60);

	if(second>=60){
		minute+=second/60;
		second%=60;
	}	
	
	cout<<minute<<endl;
	cout<<second<<endl;
}
