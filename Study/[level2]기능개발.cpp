#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    deque<int> q;
    
    for(int i=0;i<speeds.size();i++)
    {
        int progress=(100-progresses[i]);
        int days=progress/speeds[i];
        if(progress%speeds[i]!=0)
        {
            days++;
        }
        q.push_back(days);
    }
    
    while(!q.empty())
    {
        int cnt=0;
        int standard=q.front();
        while(!q.empty()&&standard>=q.front())
        {
            q.pop_front();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}