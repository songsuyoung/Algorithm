#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> key;
    for(int idx=0;idx<keymap.size();idx++){//map을 이용해서 최솟값을 미리 업데이트해놓는다.';
        for(int j=0;j<keymap[idx].size();j++)
            key[keymap[idx][j]]=105;
    }
    for(int idx=0;idx<keymap.size();idx++){//map을 이용해서 최솟값을 미리 업데이트해놓는다.';
        for(int j=0;j<keymap[idx].size();j++)
            if(key[keymap[idx][j]]>(j+1)){
                key[keymap[idx][j]]=j+1;
            }
    }
    
    
    for(int i=0;i<targets.size();i++){
        int sum=0;
        for(int j=0;j<targets[i].size();j++){
            if(!key[targets[i][j]]){
                sum=-1;
                break;
            }
            sum+=key[targets[i][j]];
        }
        answer.push_back(sum);
    }
    

    return answer;
}