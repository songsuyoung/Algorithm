#include <string>
#include <vector>
using namespace std;

int recursive(vector<int> &nums,bool *isVisited,int cnt,int result,int idx){
    
    //base
    if(cnt>=3){
        if(result==0){
            return 1;
        }
        return 0;
    }
    if(idx>=nums.size())
        return 0;
    
    //recursive
    // 0 1 2 , 0 1 3 , 0 1 4, 0 2 3, 0 
    int sum=0;
    for(int i=idx;i<nums.size();i++){
        if(!isVisited[i]){
            isVisited[i]=true;
            sum+=recursive(nums,isVisited,cnt+1,result+nums[i],i+1);
            isVisited[i]=false;
        }
    }
    
    return sum;
}
int solution(vector<int> number) {
    
    bool isVisited[15]={false,};
    int answer=recursive(number,isVisited,0,0,0);
    return answer;
}