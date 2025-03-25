#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++)
    {
        int st = commands[i][0]-1;
        int ed = commands[i][1];
        int k = commands[i][2]-1; 
        
        vector<int> tmp;
        for(int j=st; j<ed; j++)
        {
            tmp.push_back(array[j]);
        }
        
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[k]);
    }
    return answer;
}

/*
array i번째 숫자부터 j번째 숫자까지 자르고 정렬, k번째 수를 구하려고 함.

1. 자르고
2. 정렬
3. 수를 봅음.
*/