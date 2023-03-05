#include <iostream>
#include <vector>

using namespace std;

int main(){

	int Y=0,M=0;
	int input;

	cin>>input;

	vector<int> fee;
	for(int i=0;i<input;i++){
		int num;
		cin>>num;
		fee.push_back(num);
	}

	for(int i=0;i<fee.size();i++){
		Y+=fee[i]/30;
		M+=fee[i]/60;
	}

	if(((Y+fee.size())*10)>((M+fee.size())*15)){
		cout<<"M "<<(M+fee.size())*15<<endl;	
	}else if(((Y+fee.size())*10)<((M+fee.size())*15))
		cout<<"Y "<<(Y+fee.size())*10<<endl;
	else
		cout<<"Y M "<<(Y+fee.size())*10<<endl;
}
