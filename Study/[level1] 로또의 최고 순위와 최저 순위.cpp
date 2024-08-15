#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int order[] = {6,6,5,4,3,2,1};
    map<int,bool> nums;
    
    for(int i=0;i<win_nums.size();i++)
    {
        nums[win_nums[i]]=true;
    }
    
    int res=0,zero=0;
    for(int i=0;i<lottos.size();i++)
    {
        if(lottos[i]!=0&&nums[lottos[i]] == true)
        {
            nums[lottos[i]]=false;
            res++;
        }
        
        if(lottos[i]==0)
        {
            zero++;
        }
    }
    
    int max = res + zero;
    int min = res;
    
    answer.push_back(order[max]);
    answer.push_back(order[min]);
    
    return answer;
}