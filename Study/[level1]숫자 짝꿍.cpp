#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char,long long> nums;

    for(long long i=0;i<X.length();i++){ //최대 3,000,000번
        nums[X[i]]++;
    }
    
    vector<char> same;
    
    for(long long j=0;j<Y.length();j++){
        if(nums[Y[j]]){ //1이상이면
            same.push_back(Y[j]);
            nums[Y[j]]--;
        }
    }
    
    if(same.size()!=0){
        
        sort(same.begin(),same.end());
        
        for(long long i=same.size()-1;i>=0;i--){
            answer+=same[i];
        }
        
        if(answer[0]=='0')
            answer="0";
    }else{
        answer="-1";   
    }
    
    return answer;
}