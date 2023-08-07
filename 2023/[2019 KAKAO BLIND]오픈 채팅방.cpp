#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void split(string &tmp,vector<string> &output){
    istringstream ss(tmp);
    string stringBuffer;
    while (getline(ss, stringBuffer, ' ')){
        output.push_back(stringBuffer);
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<int,pair<string, string>> commands;
    map<string,string> output;
    
    for(int i=0;i<record.size();i++){
        vector<string> tmp;
        split(record[i],tmp);
        string command=tmp[0];
        string uid=tmp[1];
        
        if(tmp.size()>2){
            string nickname=tmp[2];
            
            if(output.count(uid)){
                output[uid]=nickname; //변경
            }else{
                output.insert(make_pair(uid,nickname));
            }
                
        }
        commands.insert(make_pair(i,make_pair(command,uid)));
    }
    

    for(int i=0;i<commands.size();i++){
        if(commands[i].first=="Enter"){
            answer.push_back(output[commands[i].second]+"님이 들어왔습니다.");
        }else if(commands[i].first=="Leave"){
            answer.push_back(output[commands[i].second]+"님이 나갔습니다.");
        }
    }
    return answer;
}