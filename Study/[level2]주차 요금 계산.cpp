#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

struct Car
{
  int min;
  string number;
  bool isOut;
};
//map<string,pair<bool,int>> 차 번호, (출차여부,현재 누적가격)
vector<Car> split(vector<string> records)
{
    vector<Car> output;
    for(int i=0;i<records.size();i++)
    {
        istringstream buf(records[i]);
        string tmp;
        vector<string> v;
        while(getline(buf,tmp,' '))
        {
            v.push_back(tmp);
        }
        int hour = stoi(v[0].substr(0,v[0].find(':')));
        int min = hour*60+stoi(v[0].substr(v[0].find(':')+1));
        bool isOut = v[2]=="IN"? false:true;
        output.push_back(Car{min,v[1],isOut});
    }
    return output;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    vector<int> answer;
    map<string,pair<bool,int>> res;
    map<string,int> buf;
    
    vector<Car> v = split(records);
    vector<string> names;
    for(int i=0;i<v.size();i++)
    {
        if(res.find(v[i].number)==res.end())
            names.push_back(v[i].number);
        if(v[i].isOut == false)
        {
            //입차했을 때 입시로 buf에 저장한다.
            buf[v[i].number]=v[i].min;
            res[v[i].number].first=false;
        }
        else
        {
            //출차 했을 때 buf에 있는 min값을 꺼내온다.
            res[v[i].number].second+=abs(v[i].min-buf[v[i].number]);
            res[v[i].number].first=true;
        }
    }
    
    for(int i=0;i<names.size();i++)
    {
        //만약에 v의 isOut이 false가 아니라면
        if(res[names[i]].first==false)
        {
            //출차 안한차량임으로 23:59에 출차한것으로 간주
            int last=23*60+59;
            res[names[i]].second+=abs(last-buf[names[i]]);
            res[names[i]].first=true;
        }
    }
    
    for(auto it=res.begin();it!=res.end();it++)
    {
        auto tmp=*it;
       int total=fees[1]; //pair로 iterator 전달
       tmp.second.second-=fees[0];
       if(tmp.second.second>0)
       {
           total+=((tmp.second.second/fees[2])*fees[3]);
           if(tmp.second.second%fees[2]!=0)
                total+=fees[3];
       }
       answer.push_back(total);
    }
    
    return answer;
}