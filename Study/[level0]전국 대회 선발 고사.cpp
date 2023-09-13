#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    map<int,int> tmp;
    
    for(int i=0;i<rank.size();i++){
        tmp[rank[i]]=i; //현재 등수 - 번째
    }
    
    int threshold=10000;
    for(int i=1;i<=rank.size();i++){
        
        if(attendance[tmp[i]]){ //번째 idx를 이용해서 참석확인
            answer+=threshold*tmp[i]; //idx번째를 곱해줌.
            threshold/=100;
        }
        
        if(threshold==0)
            break;
    }

    return answer;
}