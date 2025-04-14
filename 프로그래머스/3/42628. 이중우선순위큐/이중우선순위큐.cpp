#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    
    multiset<int> mst;
    
    int commandCount = 0;
    for(int i=0; i<operations.size(); i++)
    {
        int num = stoi(operations[i].substr(2, operations[i].length())); //0 명령어 1번 띄어쓰기 2번부터
        
        if(operations[i][0] == 'I')
        {   
            //모두 넣는다.
            mst.insert(num);
        }
        else
        {
            if(mst.size() >= 1)
            {
                if(num>0)
                {
                    //최대를 밴다.
                    mst.erase(--mst.end());
                }
                else
                {
                    mst.erase(mst.begin());
                }
            }
        }
    }
    
    if(mst.size() != 0)
    {
        answer[0] = *(--mst.end());
        
        answer[1] = *(mst.begin());
    }
    return answer;
}

/*

I 숫자 => 큐 삽입
D 1 => 큐 최댓값 삭제
D -1 => 큐 최솟값 삭제
최대, 최소에 대한 priority_queue를 두개 사용하는데,,,

I -45 => 최소
I 653 => 최대 => 653 출력 -45 > 0 (최소)
I -642 => 최소
I 45 => (-45+-642)/2 > 45 => 최대
I 97 => 최대 

97 제거 , 최소 -642 제거

*/