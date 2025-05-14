#include <bits/stdc++.h>

using namespace std;

int ChangeTimeToInt(string time)
{
    int pos = time.find(':');
    
    int min = stoi(time.substr(0,pos));
    int sec = stoi(time.substr(pos+1)); //': 포함'
    
    return (min*60)+sec;
}

string ChangeIntToTime(int time)
{
    string min = to_string(time/60);
    string sec = to_string(time%60);

    if(min.size()<=1)
    {
        min.insert(0, "0");
    }
    
    if(sec.size()<=1)
    {
        sec.insert(0, "0");
    }
    
    return min+":"+sec;
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int end_time = ChangeTimeToInt(video_len);
    int cur_time = ChangeTimeToInt(pos);
    int op_start_time = ChangeTimeToInt(op_start);
    int op_end_time = ChangeTimeToInt(op_end);
    
    for(int i=0; i<commands.size(); i++)
    {
         //오프닝일 경우에 오프닝 내에 들어가는지 확인
        if(cur_time>=op_start_time && cur_time <= op_end_time)
        {
            cur_time = op_end_time;
        }
        
        if(commands[i] == "prev")
        {
            cur_time -= 10; //10초 뺀다.
            if(cur_time<0)
            {
                cur_time = 0;
            }
        }
        else if(commands[i] == "next")
        {
            cur_time += 10; //10초 더함.
            if(cur_time>end_time)
            {
                //초과하면 리셋
                cur_time = end_time;
            }
        }
    }
    
    // 명령어는 끝났지만, 마지막이 오프닝이면 건너뜀
    if(cur_time>=op_start_time && cur_time <= op_end_time)
    {
        cur_time = op_end_time;
    }
    
    
    answer = ChangeIntToTime(cur_time);
    
    return answer;
}
/*

시간을 하나의 int값으로 만들어야한다. M*60 + S | M = (Res)/60 S = (Res)%60 
동영상 재생기 10초 전, 10초 후, 오프닝 건너뛰기 3가지 기능

prev => 10초 전으로 이동, 만약 10초 미만이면 0분 0초로 이동
next => 10초 후 이동, 남은 시간이 10초 미만이면 마지막 위치로
오프닝 건너뛰기 => op_start <= 현재 재생 위치 <= op_end 인경우 op_end로 이동

예)
34:33 => int로 만들기 34*60 + 33 
pos => 13:00  - 10 해보고 <=0 0 저장
next 13:10 ok + 10 해보고 >=video_len video len 저장 (미리 변환 => end)
prv 13:00 (결과)

오프닝 안에 속하는지를 확인.
*/