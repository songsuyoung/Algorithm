#include <bits/stdc++.h>
using namespace std;

/*
열은 컬럼
행은 튜플 (하나 풍텅이)
첫번째 컬럼은 기본키로서 모든 튜플에 대해 중복되지 않도록 보장

0번째 idx는 기본키로, 중복되지 않는다.
 0 1 2
[2 2 6] (튜플 0)
[1 5 10] (튜플 1)
[4 2 9] (튜플 2)
[3 8 3] (튜플 3)

1. col번째를 기준으로 오름차순 : 정렬 (col - 1)을 기준으로 정렬, sort compare A[col-1] < B[col-1]
2. S_i를 i번째 행의 튜플에 대해 각 컬럼 값을 i로 나눈 나머지들의 합으로 정의
S_begin row_begin - 1 : data[row_begin()-1] 2,2,6  => 2%2(row_begin) + 2%2 + 6%2 = 0 
S_begin + 1
...
S_end row_end -1 : data[row_end -1] : 1,5,10 => 1%3 + 5%3 + 10%3 = 1 + 2 + 1 = 4
0 ^(xor) 4 = 
0000
0100
----
0100
*/

int col_idx=-1;
bool compare(vector<int> &a,vector<int> &b)
{
    if(a[col_idx] == b[col_idx])
    {
        return a[0]>b[0];
    }
    
    return a[col_idx]<b[col_idx];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    col_idx = col-1;
    
    sort(data.begin(),data.end(),compare);
    
    vector<int> sum;
    for(int i=row_begin-1;i<row_end;i++)
    {
        //행 정의
        int val=0;
        
        for(int j=0;j<data[i].size();j++)
        {
            val+=(data[i][j]%(i+1));
        }
        sum.push_back(val);
    }
    
    for(int i=0;i<sum.size();i++)
    {
        answer^=sum[i];
    }
    
    return answer;
}