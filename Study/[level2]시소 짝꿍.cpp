#include <bits/stdc++.h>
using namespace std;
using ll=long long;

long long solution(vector<int> w) {
    long long answer = 0;
    
    map<ll,int> weights[3];
    
    for(int i=0;i<w.size();i++)
    {
        for(int j=2;j<=4;j++)
        {
            ll val=w[i]*j;
            weights[j-2][val]++;
        }
    }
    
    for(int i=0;i<w.size();i++)
    {
        //2 -> 3 -> 4와 같은지를 봐
        //왜냐면 2:2 3:3 4:4는 있지만
        //2:3 1:1.5 2:3 3:6
        
        ll multiplyby2=w[i]*2; //0 1 2
        ll multiplyby3=w[i]*3; 
        ll multiplyby4=w[i]*4;
        
        answer+=(weights[0][multiplyby2]-1);
        //2는 3과 4 비교
        answer+=weights[1][multiplyby2];
        answer+=weights[2][multiplyby2];
        
        //3은 2와 4와 비교
        answer+=weights[0][multiplyby3];
        answer+=weights[2][multiplyby3];
        
        //4는 2과 3를 비교
        answer+=weights[0][multiplyby4];
        answer+=weights[1][multiplyby4];
    }
    
    return answer/2;
}
