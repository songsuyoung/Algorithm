#include <bits/stdc++.h>
using namespace std;

void recursive(int num, int from, int tmp, int to, vector<vector<int>> &answer,int cnt)
{
    if(num <= 1)
    {
        vector<int> v = {from, to};
        answer.push_back(v);
        return;
    }
    recursive(num-1, from,to,tmp,answer, cnt+1);
    
    vector<int> v = {from, to};
    answer.push_back(v);

    recursive(num-1, tmp, from, to, answer, cnt+1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    recursive(n, 1, 2, 3,answer,0);
    return answer;
}

/*
한 번에 하나의 원판만 옮길 수 있다.
큰 원판이 작은 원판 위에 있음 안된다.

ㅇ)ㅖ)


n
1 2 3

1->2
1->3
2->1
3->2
1->2
1->3
2->1
2->3
1->3

n개의 원판을 3번 원판으로 옮기는 최소 수..

*/