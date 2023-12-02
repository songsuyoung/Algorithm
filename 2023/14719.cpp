#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h,w;
    cin>>h>>w;
    
    vector<int> v;
    for(int i=0;i<w;i++)
    {
        int tmp;
        cin>>tmp;

        v.push_back(tmp);
    }

    int sum=0;
    for(int i=0;i<w;i++)
    {
        int maxleft=0,maxright=0;
        //i를 기준으로 왼쪽에서 큰 블록, 오른쪽에서 큰 블록을 찾는다.
        for(int j=i-1;j>=0;j--)
        {
            maxleft=max(maxleft,v[j]);
        }

        for(int j=i+1;j<w;j++)
        {
            maxright=max(maxright,v[j]);
        }
        int minVal=min(maxleft,maxright);
        int tmp=minVal-v[i];
        if(tmp<=0) continue;
        sum+=tmp;
    }
    cout<<sum<<'\n';
}

