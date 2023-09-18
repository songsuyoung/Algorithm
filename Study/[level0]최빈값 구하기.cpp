#include <string>
#include <vector>
using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int cnt[1005]={0,};

    for(int i=0;i<array.size();i++){
        cnt[array[i]]++;
        
        if(answer<=cnt[array[i]]){ //가장 높은 빈도수 체크
            answer=cnt[array[i]];
        }
    }
    
    vector<int> modeVal;
    for(int i=0;i<1000;i++){
        if(cnt[i]==answer){
            modeVal.push_back(i);
        }
    }

    if(modeVal.size()!=1)
        answer=-1;
    else
        answer=modeVal[0];
    
    return answer;
}