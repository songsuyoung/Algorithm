/*
c d e f g a b C 
1 2 3 4 5 6 7 8

1->8 연주 ascending i보다 i+1이 항상 커짐
8->1 연주 desending i보다 i+1이 항상 작음
둘다 아니라면 mixed
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> nums;
    
    for(int i=0;i<8;i++){
        int tmp;
        cin>>tmp;
        
        nums.push_back(tmp);
    }
    
    bool isAscending=false;
    bool isDecending=false;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]<nums[i+1]){
            isAscending=true;
        }else if(nums[i]>nums[i+1]){
            isDecending=true;
        }
        
        if(isAscending&&isDecending){
            cout<<"mixed\n";
            break;
        }
        
    }
    
    if(!isAscending&&isDecending){
        cout<<"descending\n";
    }
    
    if(!isDecending&&isAscending){
        cout<<"ascending\n";
    }
    

    return 0;
}
