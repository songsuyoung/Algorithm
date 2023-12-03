#include <string>
#include <vector>
#include <iostream>
using namespace std;

int recursive(int k,vector<vector<int>> &dungeons,bool isVisited[])
{
    if(k<=0) return 0;
    int res=0;
    
    for(int i=0;i<dungeons.size();i++)
    {
        if(isVisited[i]) continue;
        if(k>=dungeons[i][0])
        {
            isVisited[i]=true;
            res=max(res,recursive(k-dungeons[i][1],dungeons,isVisited)+1);
            isVisited[i]=false;
        }
    }
    return res;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    bool isVisited[9]={};
    answer=recursive(k,dungeons,isVisited);
    return answer;
}