#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(const pair<int,int>& a, const pair<int,int> &b){
    
    if(a.first>b.first)
        return false;
    else if(a.first==b.first){
        if(a.second>b.second)
            return false;
    }
    return true;
}
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    
    vector<pair<int,int>> v;
    
    for(int i=0;i<T;i++){
    
        int x,y;
        
        cin>>x>>y;
        
        v.push_back(make_pair(x,y));
    }
    
    sort(v.begin(),v.end(),comp);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}