#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

void split(vector<string> &terms,map<char,int> &output){
    
    
    for(int i=0;i<terms.size();i++){
        istringstream buf(terms[i]); //input을 stringstream으로 바꾼다..
        string stringbuf; //자른걸 넣을거야..
        vector<string> buffer;
        while(getline(buf,stringbuf,' ')){
            //buf에서 ' '를 기준으로 잘라서 stringbuf에 넣는다.
            buffer.push_back(stringbuf);
        }
        
        output[buffer[0][0]]=stoi(buffer[1]);
    }

}
void split(string today,vector<int> &buffer){

    istringstream buf(today); //input을 stringstream으로 바꾼다..
    string stringbuf; //자른걸 넣을거야..
    while(getline(buf,stringbuf,'.')){
            //buf에서 ' '를 기준으로 잘라서 stringbuf에 넣는다.
        buffer.push_back(stoi(stringbuf));
    }

}

void splitAndtransform(vector<string> &privacies,map<char,int> &terms,vector<int> &output,vector<int> &answer){
    
    
    for(int i=0;i<privacies.size();i++){
        istringstream buf(privacies[i]); //input을 stringstream으로 바꾼다..
        string stringbuf; //자른걸 넣을거야..
        vector<string> buffer;
        while(getline(buf,stringbuf,' ')){
            //buf에서 ' '를 기준으로 잘라서 stringbuf에 넣는다.
            buffer.push_back(stringbuf);
        }

        int idx=buffer[0].find(".")+1;
        int day=stoi(buffer[0].substr(idx+3,buffer[0].length()));
        int month=stoi(buffer[0].substr(idx,2))+terms[buffer[1][0]];
        int year=0;
               
        if(month>12){
            year+=month/12;
            month=(month%12);
        }
        if(month==0){
            year-=1;
            month=12;
        }
    
        year=stoi(buffer[0].substr(0,idx-1))+year;
        
        if(output[0]>year){        
            answer.push_back(i+1);
        }else if(output[0]==year){
            if(output[1]>month){
                answer.push_back(i+1);
            }else if(output[1]==month){
                if(output[2]>=day)
                    answer.push_back(i+1);
            }
        }
    }

}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> term;
    vector<int> output;
    
    split(terms,term);
    split(today,output);
    
    splitAndtransform(privacies,term,output,answer);
    
    return answer;
}