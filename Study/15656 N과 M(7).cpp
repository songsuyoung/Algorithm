#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recursive(vector<int> &arr, int M, vector<int> &tmp,int selected)
{
    if(M==selected)
    {
        for(int i=0;i<tmp.size();i++)
        {
            cout<<tmp[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=0;i<arr.size();i++)
    {
        tmp.push_back(arr[i]);
        recursive(arr,M,tmp,selected+1);
        tmp.pop_back();
    }
}
int main()
{
    int N,M;
    cin>>N>>M;

    vector<int> arr(N,0);

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());
    vector<int> tmp;
    recursive(arr,M,tmp,0);
}