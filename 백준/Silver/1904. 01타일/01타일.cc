#include <bits/stdc++.h>
using namespace std;

int dp[1'000'005];

int recursive(int N)
{
    if (N <= 1)
    {
        return dp[N] = 1;
    }

    if (dp[N] != 0)
    {
        return dp[N];
    }

    return dp[N] = (recursive(N-1) + recursive(N-2))%15746;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int N;
    cin>>N;

    cout<<recursive(N)%15746<<'\n';
}

/*
하나만의 타일 1
0타일 2개 붙인 한 쌍의 00타일

예

11 => 1 2개
00 => 00 1개

N = 4
1111
1100
1001
0011
0000


N-2

1 => 1
11, 00 => 2
111,100,001 => 3 (1+2)
1111,1100,0011,1001,0000 => 5 (2+3)
11111,11001,11100,00111,10011,10000,00001,00100 => 8 (3+5)
*/
