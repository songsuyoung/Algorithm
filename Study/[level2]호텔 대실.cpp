#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct Compare
{
    bool operator()(string &a,string &b)
    {
        int hourA=stoi(a.substr(0,a.find(':')));
        int minA=stoi(a.substr(a.find(':')+1));
        
        int hourB=stoi(b.substr(0,b.find(':')));
        int minB=stoi(b.substr(b.find(':')+1));
        
        return (hourA>hourB)||(hourA==hourB&&minA>minB);
    }
};

bool operator>(string &a,string &b)
{
    //끝난시간.. 즉 
    int hourA=stoi(a.substr(0,a.find(':')));
    int minA=stoi(a.substr(a.find(':')+1));
        
    int hourB=stoi(b.substr(0,b.find(':')));
    int minB=stoi(b.substr(b.find(':')+1));
 
    return hourA>hourB|| (hourA==hourB&&minA>minB);
}

bool compare(pair<string,string> &a,pair<string,string> &b)
{
    int hourA=stoi(a.first.substr(0,a.first.find(':')));
    int minA=stoi(a.first.substr(a.first.find(':')+1));
        
    int hourB=stoi(b.first.substr(0,b.first.find(':')));
    int minB=stoi(b.first.substr(b.first.find(':')+1));
      
    if(hourA==hourB)
        return minA<minB;
    return hourA<hourB;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<string,string>> b;

    for(auto time : book_time)
    {
        b.push_back(make_pair(time[0],time[1]));
    }
    
    sort(b.begin(),b.end(),compare);
    
    priority_queue<string,vector<string>,Compare> q;
    
    q.push(b[0].second);
    for(int i=1;i<b.size();i++)
    {
        int hourA=stoi(q.top().substr(0,q.top().find(':')));
        int minA=stoi(q.top().substr(q.top().find(':')+1))+10;
        string endTime=to_string(hourA+(minA/60))+':'+to_string(minA%60);
            //크면 예약 못받음
        if(endTime>b[i].first)
        {
            q.push(b[i].second);
        }else
        {
                //작거나 같으면 예약받을 수 있음 대신에 현재 queue를 빼고 난뒤 새로운 값을 삽입
            if(!q.empty())
                q.pop();
            q.push(b[i].second); //끝나는 시간으로 queue에 삽입    
        }
    }
    if(!q.empty())
        answer=q.size();
    return answer;
}