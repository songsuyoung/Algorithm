#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

void split(vector<string> &report,map<string,map<string,int>> &uids){

    vector<string> uid;
    for(int i=0;i<report.size();i++){
        uid.clear();
        string stringBuffer;
        string tmp=report[i];
        istringstream ss(tmp);
        while (getline(ss, stringBuffer, ' ')){
            uid.push_back(stringBuffer);
        }
        string front=uid[0];
        string back=uid[1];
        if(uids[back].count(front)){
            continue;
        }else{
            uids[back][front]=0;
        }
    }
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string,map<string,int>> uids;
    split(report,uids);
    vector<string> freezer;
    for(int i=0;i<id_list.size();i++){
        if(uids[id_list[i]].size()>=k){
            freezer.push_back(id_list[i]);
        }
        answer.push_back(0);
    }

    for(int i=0;i<id_list.size();i++){
        for(int j=0;j<freezer.size();j++){
            if(uids[freezer[j]].count(id_list[i])){
                answer[i]++;
            }
        }    
    }
    return answer;
}