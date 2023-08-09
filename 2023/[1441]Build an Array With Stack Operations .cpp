
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
    
        int targetTop=0,preTop=0; //++tartgetTop
        vector<string> output;
        stack<int> s;

        for(int i=1;i<=n;i++){
            if(target[targetTop]==i){
                if(preTop<0)
                    preTop=0;
                //stack.top이랑 일치하지 않으면,,, pop해야함.
                while(!s.empty()&&target[preTop]!=s.top()){
                    s.pop();
                    output.push_back("Pop");
                }
                targetTop++;
            }

            s.push(i); //꼭 넣음 같은 순간에, 같지 않은 놈음 pop한다.
            output.push_back("Push");

            if(targetTop>=target.size())
                break;
            
            preTop=targetTop-1;
        }

        return output;
    }
};