#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 100'000);
    answer[0] = 0;
    
    //하나씩 삽입, cnt == freq.size() 같으면, while문을 통해서 중복된 애들을 제거함.
    //answer의 0, 1 거리보다 작으면
    //answer에 인덱스 삽입.
    
    deque<pair<string, int>> dq; //이름과 인덱스
    unordered_map<string, int> freq; //이름과 나온 빈도수
    for(int i=0; i<gems.size(); i++)
    {
        freq[gems[i]] = 0; //초기화, unique한 개수를 알 수 있음.
    }
    
    int cnt = 0;
    for(int i=0; i<gems.size(); i++)
    {
        //이름, 인덱스 삽입
        dq.push_back({gems[i], i+1});
        
        //freq가 모두 채워졌다면,
        if(freq[gems[i]]==0)
        {
            cnt++;
        }
        freq[gems[i]] ++;
        
        if(cnt==freq.size())
        {
            //모두 담았음.
            //중복되는 거 제거
            while(!dq.empty())
            {
                pair<string, int> cur = dq.front();
                
                if(freq[cur.first]>=2)
                {
                    freq[cur.first]--;
                    dq.pop_front();
                }
                else
                {
                    break;
                }
            }
            
            if(abs(answer[0] - answer[1]) > abs(dq.front().second - dq.back().second))
            {
                answer[0] = dq.front().second;
                answer[1] = dq.back().second;        
            }
        }
    }
    return answer;
}

/*
갑부된 어피치

진열대의 특정 범위의 보석을 모두 구매하되 특별히 아래 목적 달성
"진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간을 찾아서 구매" => 거리가 가장 짧은, 그런데 모든 종류의 보석이 적어도 1개 포함된.

예)
["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
  |                                                   |  => 7개
          |                                           |  => 6개
                  |                                   |  => 5개
                  
-> 아이디어 :
deque? 현재 있는게 한번 더 나오면 뱉는다.

예)

Ruby f
Dia f
개수를 셀까?


 3  2  2  3  3  1  1 => 서로 다른 개수가 몇 개인지 unordered_map 으로 추척(개수까지)
 
 
 while(!dq.empty())
 {
    if(m[dq.top()]>=2)
    {
        m[dq.top]--; //줄임 개수
        dq.pop();
    }
    else
    {
        break;
    }
 }
 
 2 2 2 2 1 1
 1 2 2 1 1 => 끝 (5줄)
 
 dq => (이름, idx)
*/