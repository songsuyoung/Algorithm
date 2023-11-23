#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first==b.first? a.second<b.second : a.first<b.first;
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    vector<pair<int,int>> v;
    
    for(int i=0;i<targets.size();i++)
    {
        v.push_back(make_pair(targets[i][0],targets[i][1]));
    }
    
    sort(v.begin(),v.end());
    
    pair<int,int> thre=make_pair(0,0);
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first<thre.second)
        {
            if(thre.second>v[i].second)
                thre.second=v[i].second;
            continue;
        }
        
        thre=v[i];
        answer++;
    }
    return answer;
}