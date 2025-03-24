#include <bits/stdc++.h>
using namespace std;

set<set<string>> st;

void recursive(vector<string> &banned_id, unordered_map<string,vector<string>> &cnt, unordered_map<string,bool> &isVisited, int idx)
{
    if(idx>=banned_id.size())
    {
        //도착
        set<string> s;
        for(int i=0; i<banned_id.size(); i++)
        {
            for(const auto& c : cnt[banned_id[i]])
            {
                if(isVisited[c])
                {
                    s.insert(c);
                }
            }
        }
        
        st.insert(s);
        return;
    }
    //갈 수 있는 곳 확인
    for(const auto& c : cnt[banned_id[idx]])
    {
        if(isVisited[c])
        {
            continue;
        }
        isVisited[c] = true;
        recursive(banned_id, cnt, isVisited, idx+1);
        isVisited[c] = false;
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    //개수를 저장할 메모리 공간 unordered_map<string,int>
    unordered_map<string,vector<string>> cnt;
    
    //banned_id에 중복이 존재하지만, 중복이 없을 때의 개수를 세어야한다.
    set<string> unique_banned_id;
    
    for(int i=0; i<banned_id.size(); i++)
    {
        unique_banned_id.insert(banned_id[i]);
    }
    
    //user_id를 한바퀴 돌면서 banned_id 패턴에 일치하는지를 확인한다.
    for(int i=0; i<user_id.size(); i++)
    {
        for(const auto& id : unique_banned_id)
        {
            if(user_id[i].size() != id.size()) continue; //크기가 맞지 않으면 일치하지 않음을 의미
            int k=0;
            for(; k<id.size(); k++)
            {
                if(id[k] != '*' && id[k] != user_id[i][k]) break; //한글자라도 다르면 일치하지 않음
            }
            
            if(k>=id.size())
            {
                //일치한다는 뜻.
                cnt[id].push_back(user_id[i]);
            }   
        }
    }
    
    unordered_map<string,bool> isVisited;
    for(const auto& c : cnt)
    {
        for(const auto& v : c.second)
        {
            isVisited[v]=false;
        }
    }
    recursive(banned_id, cnt, isVisited, 0);
    
    answer = st.size();
    return answer;
}

/*
이벤트에 비정상적인 방법으로 당첨을 시도한 응모자들을 발견 => 불량 사용자 ( 당첨 처리 제외 )
개인 정보를 위해서 일부 문자를 *로 가려서 전달, 가리고자 하는 문자 하나에 * 문자 하나를 사용. 최소 하나 이상 *을 사용

예)
응모자
frodo, fradi, crodo, abc123, frodoc

불량 사용자
fr*d*, abc1**

제재 아이디
frodo, abc123
fradi, abc123

조합.
fr*d* 모양을 띄어져 있는 개수 세기 예) 2개
abc1** 모양을 띄어져 있는 개수 세기 예) 1개


예)
*rodo = 2 => crodo, frodo => 2C1 = 2
*rodo = 2 => frodo, crodo => 1C1 = 1
***** = 2 => frodoc, abc123 

1 패턴에 맞는 사람 찾기
*rodo => 2명
****** => 2명


*rodo => 2명 중 1명 선택
*rodo => 1명 중 1명 선택
****** => 2명 중 1명 선택 

2C1 + 1C1 = 2+1 = 3

2C1 * 1C1 = 2

2C1 * 1C1 * 2C1 = 2*2 = 4.. 2C1 1C1 중복 => frodo, crodo 각 한 개씩


*/