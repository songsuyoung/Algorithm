#include <string>
#include <vector>
#include <sstream>
using namespace std;

void split(string input, vector<string> &v){
    istringstream stream(input);
    string buffer;
    
    while(getline(stream,buffer,' ')){
        if(!buffer.empty())
            v.push_back(buffer);
    }
}

vector<string> solution(string my_string) {
    vector<string> answer;
    
    split(my_string,answer);
    return answer;
}