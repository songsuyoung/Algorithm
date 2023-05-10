#include <iostream>
#include <vector>
#include <string>
#include <sstream> //split 사용을 위함
using namespace std;

int main(){

    string line;
    int lineCount=0;
 
    getline(cin,line);

    stringstream ss(line);
    ss.str(line);   
    
    string word;
    while(ss>>word){
	lineCount++;
    }

    cout<<lineCount<<endl;
    return 0;
}
