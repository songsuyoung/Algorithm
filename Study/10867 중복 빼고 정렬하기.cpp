#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    
    int N;
    cin>>N;
    
    vector<int> sorting;

    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        sorting.push_back(tmp);
    }
    sort(sorting.begin(),sorting.end());
    sorting.erase(unique(sorting.begin(),sorting.end()),sorting.end());
    
    for(int i=0;i<sorting.size();i++){
        cout<<sorting[i]<<' ';
    }
    return 0;
}