#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> missing;
    for(int i=0;i<name.size();i++){
        if(i>=yearning.size()){//만약에 name size 4 , yearning size 3이라면, i가 3을 넘으면 idx초과..
            missing[name[i]]=0;
        }else{
            missing[name[i]]=yearning[i];
        }
    }
    
    for(int i=0;i<photo.size();i++){
        int sum=0;
        for(int j=0;j<photo[i].size();j++){
            sum+=missing[photo[i][j]];
        }
        answer.push_back(sum);
    }
    return answer;
}