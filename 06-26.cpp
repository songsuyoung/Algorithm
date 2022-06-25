#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	vector<string> names;
	int N;
	cin>>N;

	for(int i=0;i<N;i++){
		string tmp;
		cin>>tmp;
		names.push_back(tmp);
	}

	int check=0;
	sort(names.begin(),names.end());
	vector<char> fir;
	for(int i=0;i<names.size();i++){

		for(int j=i+1;j<names.size();j++){
			if(names[i][0]==names[j][0])
				check++;
		}
		if(check>=4){
			fir.push_back(names[i][0]);
		}
		check=0;
	}

	
	fir.erase(unique(fir.begin(),fir.end()),fir.end());

	for(int i=0;i<fir.size();i++)
		cout<<fir[i];
	if(fir.empty())
		cout<<"PREDAJA"<<endl;
}
