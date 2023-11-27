#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Subject{
    public:
    string name;
    string time;
    int duration;
    Subject(string n,string t,int d):name(n),time(t),duration(d){}
    
};
bool compare(Subject &a,Subject &b)
{
    int idxA=a.time.find(':');
    int hourA=stoi(a.time.substr(0,idxA));
    int minA=stoi(a.time.substr(idxA+1));
    
    
    int idxB=b.time.find(':');
    int hourB=stoi(b.time.substr(0,idxB));
    int minB=stoi(b.time.substr(idxB+1));
    
    return hourA==hourB? minA<minB:hourA<hourB; //오름차순 B가 더커야함
}

bool operator>(string &a,string &b)
{
    int idxA=a.find(':');
    int hourA=stoi(a.substr(0,idxA));
    int minA=stoi(a.substr(idxA+1));
    
    int idxB=b.find(':');
    int hourB=stoi(b.substr(0,idxB));
    int minB=stoi(b.substr(idxB+1));
    
    return hourA==hourB? minA>minB:hourA>hourB;
}

string GetEndTime(string &time,int &duration)
{
    int idx=time.find(':');
    int hour=stoi(time.substr(0,idx));
    int min=stoi(time.substr(idx+1));
    
    //min+time => /60 => 나온 몫 hour+=몫 min=(min%60);
    
    min=min+duration;
    hour=hour+(min/60);
    min=(min%60);
    
    return to_string(hour)+":"+to_string(min);
}
//A(다음 과제) - B(이전 과제)
int operator-(string &a,string &b)
{
    int idxA=a.find(':');
    int hourA=stoi(a.substr(0,idxA));
    int minA=stoi(a.substr(idxA+1))+(hourA*60);
    
    int idxB=b.find(':');
    int hourB=stoi(b.substr(0,idxB));
    int minB=stoi(b.substr(idxB+1))+(hourB*60);
    
    int min=abs(minA-minB);
    //남은 분 가져오기
    return min;
}
vector<string> solution(vector<vector<string>> plans) {
 
    vector<string> answer;
    vector<Subject> v;
    stack<Subject> s;
    for(int i=0;i<plans.size();i++)
    {
        v.push_back(Subject(plans[i][0],plans[i][1],stoi(plans[i][2])));
    }
    
    sort(v.begin(),v.end(),compare);
    
    for(int i=0;i<v.size()-1;i++)
    {
        //현재 과제가 끝나는 시간을 가져온다
        string endTime=GetEndTime(v[i].time,v[i].duration);
     
        //다음 시작시각보다 현재 과제시각이 클 경우
        if(endTime>v[i+1].time)
        {
            //다음 시작시각 - 현재 과제시각 = M(진행한 분)
            int min=v[i+1].time - v[i].time;
            //현재 과제시각 duration-=M 저장 후 stack 넣기
            v[i].duration-=min;
            s.push(v[i]);
        }
        //다음 시작과제보다 작거나 같을 때 answer.push_back(Subject.name)
        else
        {
            answer.push_back(v[i].name);
            //다음 시작과제 - 현재 끝난시각 = M(남아있는 분:양수)
            int min=v[i+1].time-endTime;
            
            //스택이 비어있지 않고, 남아있는 분 > 0 크다면 반복문 진행
            while(!s.empty()&&min>0)
            {
                //int remaining=M(남아있는 시간)-s.top.duration
                int remaining=min-s.top().duration;
                
                if(remaining<0)
                {
                    //remaining이 음수이면, s.top.duration-=M 후 while문 break
                    s.top().duration-=min;
                    break;
                }
                
                //양수라면, answer.push_back(s.top().name), s.pop(), M=remaining 업데이트
                answer.push_back(s.top().name);
                s.pop();
                min=remaining;
            }
        }
    }
    //마지막 과제 수행
    answer.push_back(v[v.size()-1].name);

    while(!s.empty())
    {
        answer.push_back(s.top().name);
        s.pop();
    }
    return answer;
}