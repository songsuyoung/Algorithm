#include <string>
#include <vector>
#include <stack>
using namespace std;

//monotonic stack
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    
    stack<pair<int,int>> s;
    s.push(make_pair(numbers[0],0));
    
    for(int i=1;i<numbers.size();i++)
    {
        while(!s.empty()&&s.top().first<numbers[i])
        {
            answer[s.top().second]=numbers[i];
            s.pop();
        }
        s.push(make_pair(numbers[i],i));
    }
    
    while(!s.empty())
    {   
        answer[s.top().second]=-1;
        s.pop();
    }
    return answer;
}