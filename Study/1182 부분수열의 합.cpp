#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int recursive(int S,int size,vector<int> &nums,bool isVisited[],int sum,int idx,int selected){

    if(selected>size)
        return 0;

    if(sum==S&&selected>0&&selected==size) //8선택 하지도 않았는데 리턴된거 아닐가요?
    {
        return 1;
    }
    int result=0;
    for(int i=idx;i<nums.size();i++) //0 1 2 3 4 
    {
        if(isVisited[i])
            continue;
        isVisited[i]=true;
        result+=recursive(S,size,nums,isVisited,sum+nums[i],i+1,selected+1);
        isVisited[i]=false;
    }

    return result;
}
int main()
{
    int N,S;
    cin>>N>>S;

    int cnt=0;
    bool isVisited[22]={};
    vector<int> nums;
    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }

    int sum=0;
    for(int i=1;i<=N;i++)
    {
        sum+=recursive(S,i,nums,isVisited,0,0,0);
    }
    cout<<sum<<'\n';
}