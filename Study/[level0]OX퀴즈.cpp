#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool split(string input){
    vector<string> v;
    istringstream stream(input);
    string buf;
    int result=0;
    while(getline(stream,buf,' ')){

        if(buf=="="){
            switch(v[1][0]){
                case '+':
                    result=stoi(v[0])+stoi(v[2]);
                    break;
                case '-':
                    result=stoi(v[0])-stoi(v[2]);
                    break;
                case '/':
                    result=stoi(v[0])/stoi(v[2]);
                    break;
                case '*':
                    result=stoi(v[0])*stoi(v[2]);
                    break;
            }
        }else{
            v.push_back(buf);
        }
    }
    
    return stoi(v.back())==result;
    
}
vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(int i=0;i<quiz.size();i++){
        if(split(quiz[i])){
            answer.push_back("O");
        }else{
            answer.push_back("X");
        }
    }
    return answer;
}