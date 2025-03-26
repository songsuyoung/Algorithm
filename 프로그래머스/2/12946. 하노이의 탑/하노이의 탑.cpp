#include <bits/stdc++.h>

using namespace std;

void hanoi(int from, int tmp, int to, int n,vector<vector<int>>& answer)
{
    if(n <= 1)
    {
        answer.push_back({from,to});
        return;
    }
    
    hanoi(from, to, tmp,n-1,answer); //1->2
    answer.push_back({from,to});
    hanoi(tmp, from ,to,n-1,answer); //2->3
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(1,2,3,n,answer);
    
    return answer;
}

/*
[1] 1->2
[2] 2->3

[1] 1->3


from tmp to

from to tmp
1     3   2


*/