#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool comp(pair<int,int> &a,pair<int,int> &b){
    return a.first==b.first? a.second>b.second:a.first<b.first;
}

struct Compare{
    bool operator()(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second>b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin>>N;
    
    int total=0;
    if(N!=0)
    {
        vector<pair<int,int>> speak;
        for(int i=0;i<N;i++)
        {
            int p,d;
            cin>>p>>d;

            speak.push_back(make_pair(d,p));
        }

        sort(speak.begin(),speak.end(),comp); //순차적으로 정렬

        int day=2;

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> q; //min heap
        q.push(speak[0]); //하나 삽입
        total+=q.top().second;
        
        for(int i=1;i<N;i++)
        {
        // cout<<q.top().first<<','<<q.top().second<<'\n';
            if(day>speak[i].first)
            {
                //day가 작으면, q에 있는 가장 작은 값을 제거 하고 
            
                if(!q.empty()&&q.top().second<speak[i].second)
                {
                    if(day<=speak[i].first)
                        break;
                    day--;
                    total-=q.top().second;
                    q.pop();
                }
            }
            if(day<=speak[i].first)
            {
                day++;
                total+=speak[i].second;
                q.push(speak[i]); //클때에는 
            }
        }

    }
    cout<<total<<'\n';
}