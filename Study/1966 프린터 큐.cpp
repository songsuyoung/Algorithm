#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int T;
    cin>>T;

    for(int i=0;i<T;i++)
    {
        int N,M;
        cin>>N>>M;
        queue<pair<int,int>> q;
        int priority[105]={};
        for(int i=0;i<N;i++)
        {
            int tmp;
            cin>>tmp;
            q.push(make_pair(tmp,i));
            priority[i]=tmp;
        }

        sort(priority,priority+N);//큰 수로
        int idx=N-1;
        int cnt=0;
        while(!q.empty())
        {

            if(q.front().first==priority[idx]){
                idx--;
                if(q.front().second==M||idx<0)
                    break;
                q.pop();
                cnt++;
                continue;
            }
            
            q.push(q.front());
            q.pop();
            
        }
        cout<<cnt+1<<'\n';

    }
}