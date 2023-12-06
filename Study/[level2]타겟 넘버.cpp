#include <string>
#include <vector>
#include <iostream>
using namespace std;

int recursive(const int &target,const vector<int> &numbers,int idx,int sum,bool isMinus)
{
    if(idx>numbers.size()) return 0;
    
    if(idx==numbers.size()&&sum==target)
    {
        return 1;
    }
    
    //빼거나
    int res=0;
    res=recursive(target,numbers,idx+1,sum+numbers[idx],0)+recursive(target,numbers,idx+1,sum-numbers[idx],1);
    //더함
    
    return res;
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer=recursive(target,numbers,0,0,false);
    return answer;
}