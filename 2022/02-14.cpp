#include <iostream>
#include <string>
using namespace std;


int main(){
	string color[10]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
	string value[10]={"0","1","2","3","4","5","6","7","8","9"};
	int mul[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

	string input[3];

		cin>>input[0]>>input[1]>>input[2];

	string result="";
	unsigned long long multiply;

	for(int j=0;j<3;j++){
		for(int i=0;i<10;i++){
			if(input[j]==color[i]&&j!=2){
				result+=value[i];
			}
			if(input[2]==color[i])
				multiply=mul[i];
		}
	}
	cout<<stoi(result)*multiply<<endl;

}
