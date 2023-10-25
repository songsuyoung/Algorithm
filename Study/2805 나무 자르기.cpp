#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long calLen(vector<long long> &trees,long long cutLen){

    long long sum=0;
    for(long long i=0;i<trees.size();i++)
    {
        if(trees[i]>=cutLen)
            sum+=trees[i]-cutLen;
    }
    return sum;
}
int main()
{
    long long N,M;
    cin>>N>>M;

    vector<long long> trees;
    for(int i=0;i<N;i++)
    {
        long long treeHeight;
        cin>>treeHeight;

        trees.push_back(treeHeight);
    }

    sort(trees.begin(),trees.end());
    long long left=1,right=trees[N-1];
    long long minLen=0;
    while(left<=right)
    {
        long long mid=(left+right)/2;

        if(calLen(trees,mid)>=M){
            minLen=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    cout<<minLen<<'\n';
}