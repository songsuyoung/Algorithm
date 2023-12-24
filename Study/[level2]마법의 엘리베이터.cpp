#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int bfs(int storey)
{
    
    
    int standard=10; //10의 자리
    int curStandard=1;
    queue<pair<int,int>> q;
    
    q.push(make_pair(storey,0));
    while(!q.empty())
    {
        pair<int,int> cur=q.front();
        q.pop();
        
        //2554  (2554%10)/1 4/1 => 4
        //2550  (2550%100)/10 50/10 => 5
        //2600  (2600%1000)/100  600/100 => 6
        //3000  (3000%10000)/1000 3000/1000 => 3
        int mod=(cur.first%standard)/curStandard;
        if(cur.first<0) continue;
        
        if(cur.first==0) return cur.second;
        if(mod<5)
        {
            //2554-(4*1) => 2550
            //3000-(1000*3) => 0
            q.push(make_pair(cur.first-(mod*curStandard),cur.second+mod));
        }
        else if(mod>5)
        {
            q.push(make_pair(cur.first+(curStandard*(10-mod)),cur.second+(10-mod)));
        }
        else
        {
            //n번째 자리가 5일때에는 n+1번째 자리의 수가 5이상인지 이하인지를 체크하여 조건을 부여해줘야한다.
            if((cur.first%(standard*10)/standard)<5)
            {
                 q.push(make_pair(cur.first-(mod*curStandard),cur.second+mod));
            }
            else
            {
                 q.push(make_pair(cur.first+(curStandard*(10-mod)),cur.second+(10-mod)));
            }
        }
        
        curStandard=standard;
        standard*=10;
    }
    
    return 0;
}
int solution(int storey) {
    int answer = bfs(storey);
    return answer;
}
