#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Find(int idx,vector<int> &uf)
{
    if(idx==uf[idx]) return uf[idx];
    uf[idx]=Find(uf[idx],uf);
    return uf[idx];
}

void Union(int a,int b, vector<int> &uf)
{
    a=Find(a,uf);
    b=Find(b,uf);
    
    if(a!=b)
        uf[a]=b;
}

bool compare(vector<int> a,vector<int> b)
{
    return a[2]<b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> uf(n);
    
    for(int i=0;i<n;i++)
        uf[i]=i;
    
    sort(costs.begin(),costs.end(),compare);
    
    for(int i=0;i<costs.size();i++)
    {
        
        if(Find(costs[i][0],uf)!=Find(costs[i][1],uf))
        {
            Union(costs[i][0],costs[i][1],uf);
            answer+=costs[i][2];
        }
        
    }
    return answer;
}