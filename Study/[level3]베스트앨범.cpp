#include <bits/stdc++.h>
using ll=long long;
using namespace std;

struct Compare{
    
    bool operator()(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
        
    map<string,priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>> music;
    map<string,ll> cnts;
    for(int i=0;i<genres.size();i++)
    {
        cnts[genres[i]]+=plays[i];
        music[genres[i]].push(make_pair(plays[i],i));
    }
    
    map<ll,string,greater<ll>> genresAndCnt;
    
    for(auto cnt:cnts)
    {
        genresAndCnt[cnt.second]=cnt.first;
    }
    
    for(auto genre:genresAndCnt)
    {
        //first 횟수 second 장르
        int removeCnt=0;
        while(!music[genre.second].empty()&&removeCnt<2)
        {
            answer.push_back(music[genre.second].top().second);
            music[genre.second].pop();
            removeCnt++;
        }
    }
    return answer;
}