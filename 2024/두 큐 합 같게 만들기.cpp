#include <string>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    long long q1Sum=accumulate(queue1.begin(),queue1.end(),0);
    long long q2Sum=accumulate(queue2.begin(),queue2.end(),0);
    int size=queue1.size()*3;
    
    int idx1=0;
    int idx2=0;
    while(q1Sum!=q2Sum){ //q2에서 뺌 q1은 더함
        
        if(q1Sum<q2Sum){
            int tmp=queue2[idx2++];
            queue1.push_back(tmp);

            q1Sum+=tmp;
            q2Sum-=tmp;
        }else if(q1Sum>q2Sum){
            int tmp=queue1[idx1++];
            queue2.push_back(tmp);
            
            q1Sum-=tmp;
            q2Sum+=tmp;
        }
        answer++;
        if(size<=answer){
            answer=-1;
            break;
        }
    }
    return answer;
}