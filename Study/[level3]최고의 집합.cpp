#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    while(s!=0)
    {
        if(s/n==0)
        {
            answer.push_back(-1);
            break;
        }
        answer.push_back(s/n);
        s-=(s/n);
        n-=1;
    }
    return answer;
}