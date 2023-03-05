#include <iostream>
using namespace std;


int main(){

	char space[9][9];

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>space[i][j];
		}
	}

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			cout<<space[i][j];

	int count=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(!((i+j)%2)&&space[i][j]=='F'){
				count++;
			}

		}
	}
	cout<<count<<endl;
}
