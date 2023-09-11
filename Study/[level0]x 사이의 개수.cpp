#include <string>
#include <vector>
#include <sstream>

using namespace std;

void split(string input, vector<int> &output){
    
    istringstream stream(input);
    string buf;
    
    vector<string> tmp;
    int cnt=0;
    while(getline(stream,buf,'x')){
        output.push_back(buf.size());
    }
    if(input[input.length()-1]=='x')
        output.push_back(buf.size());
}
vector<int> solution(string myString) {
    vector<int> answer;
    split(myString,answer);
    return answer;
}