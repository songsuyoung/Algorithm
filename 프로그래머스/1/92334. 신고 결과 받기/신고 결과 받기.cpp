#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    //1. 신고 횟수를 계산한다 + 유저 ID, 신고한 ID도 리셋시킨다.
    unordered_map<string,int> count;
    unordered_map<string, unordered_set<string>> user;
    unordered_set<string> suspend_user;
    for(int i=0; i<report.size(); i++)
    {
        int find = report[i].find(" "); //공백을 기준으로 자른다.
        
        const string& user_id = report[i].substr(0, find);
        const string& suspend_id = report[i].substr(find+1);
        
        if(user[user_id].find(suspend_id) == user[user_id].end())
        {
            count[suspend_id]++; //신고 횟수
            user[user_id].insert(suspend_id); //report[i][0] -> report[i][1] 신고함
        }
        
        if(count[suspend_id]>=k)
        {
            //정지당할 유저
            suspend_user.insert(suspend_id);
        }
    }
    
    //user_id를 돌면서, 실제 개수를 확인한다.
    for(int i=0; i<id_list.size(); i++)
    {
        for(const auto user_id : user[id_list[i]])
        {
            if(suspend_user.find(user_id) != suspend_user.end())
            {
                //있다면 정지당해야함.
                answer[i]++; //메일 전송 개수
            }
        }
    }
    return answer;
}

/*
각 유저는 한 번에 한 명의 유저를 신고
k번 이상 신고된 유저는 게시판 이용이 정지되며, 정지 사실을 메일로 발송

//신고 당한애에 대해서 unordered_map<string, int> 신고횟수   => K번 이상 신고되어지면, unordered_set<string> 저장(정지당한애)
muzi = 1
apeach = 0
frodo = 2
neo = 2

frodo, neo 정지

//유저ID, vector<string>(신고한 ID)
muzi = frodo, neo 신고 => 2 신고한 ID에 대한 정지당한 애 리스트에서 확인. 있으면, answer[idx]++;
frodo = neo 신고 => 1
apeach = frodo 신고 => 1
neo = X => 0

*/