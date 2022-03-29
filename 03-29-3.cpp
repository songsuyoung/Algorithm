#include <iostream>
#include <vector>
using namespace std;

int main(){

    string line;

    vector<int> alpha;

    for(int i=0;i<27;i++){
	alpha.push_back(-1);
    }

    cin>>line;

    for(int i=0;i<line.size();i++){
	for(int j=0;j<27;j++){
	    if(line[i]==(97+j)||line[i]==(65+j))
		alpha[j]++;
	}
    }

    int max_index=max_element(alpha.begin(),alpha.end())-alpha.begin();

    for(int i=0;i<27;i++){
	if(alpha[max_index]==alpha[i]&&max_index!=i){
	    max_index=63;
	    break;    
	}
    }
    if(max_index==63)
	cout<<"?"<<endl;
    else
	cout<<(char)(65+max_index)<<endl;
}
