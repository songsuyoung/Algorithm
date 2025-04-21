#include <bits/stdc++.h>

using namespace std;

struct fee
{
    int entry;
    int time;       /*출차 - 입차 시간*/
    bool bIsExit;   /*출차 여부*/
};

vector<string> split(string input, string term)
{
    vector<string> v;
    
    int idx = 0;
    while((idx = input.find(term))!=string::npos)
    {
        string sub = input.substr(0, idx);
        v.push_back(sub);
        input.erase(0, idx+1);
    }
    v.push_back(input);
    
    return v;
}

int calculateMin(string record)
{
    int idx = record.find(":");
    
    int hour = stoi(record.substr(0, idx))*60;
    int min = stoi(record.substr(idx+1));
    
    return hour + min;
}

int calculateFee(vector<int> &fees, int min)
{
    int fee = fees[1]; //기본 요금은 항상 부여
    //주차 요금 계산
        
    // 기본 시간 | 기본 요금 | 단위 시간 | 단위 요금
    // car.second.time -=180 기본 시간을 뺀다. => 기본 요금 +5000
    min -= fees[0];
    
    //음수인가? 그러면 기본 요금만
    if(min<=0)
    {
        return fee;
    }
    
    // car.second.time %= 단위 시간 => 0으로 딱 안떨어지면 +1 추가
    if(min%fees[2] != 0)
    {
        fee+=fees[3];    
    }
    
    fee+= fees[3] * (min/fees[2]);
    // car.second.time /= 단위 시간 => (나온 몫 + 1(optional))* 단위 요금
    
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, fee> cars;
    for(int i=0; i<records.size(); i++)
    {
        vector<string> v = split(records[i], " ");
        int min = calculateMin(v[0]);
    
        if(v[2]=="IN")
        {
            //입차
            //이미 저장하고 있는 정보가 있는지 확인.
            cars[v[1]].entry = min;
            cars[v[1]].bIsExit = false;
        }
        else
        {
            //출차            
            cars[v[1]].time += (min-cars[v[1]].entry); /*출차 - 입차 시간 누적*/
            cars[v[1]].bIsExit = true;
        }
    }
    
    for(auto car : cars)
    {
        if(car.second.bIsExit == false)
        {
            //아직 출차 안했다.
            int min = calculateMin("23:59");
            
            car.second.time += (min - car.second.entry); //마지막 계산
        }
        
        int fee = calculateFee(fees, car.second.time);
        answer.push_back(fee);
        //cout<<car.first<<' '<<car.second.time<<' '<<fee<<'\n';
    }
    return answer;
}

/*
입차 - 출차

차량 번호 - 분계산(출차-입차 시간), 출차 했는가?

처음엔 - 입차 => 입차가 있다면 출차-입차 해서 unordered_map 저장
만약, 출차 했는가 -> false라면, 23:59로 출차 

06:00 ~ 06:34 
6*60 + 34 출차
6*60 + 00 입차

18:59 ~ 23:59
18*60 + 59
23*60 + 59

이전것 + 현재것 해서 누적해야 함. (여러번 입차/출차 가능)

*/