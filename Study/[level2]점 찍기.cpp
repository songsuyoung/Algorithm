#include <string>
#include <vector>
#include <cmath>
using namespace std;


long long solution(int k, int d) {
    
    long long answer=1; //0,0
    
    for(int x=0;x<=d;x+=k)
    {
        long long y=(pow(d,2)-pow(x,2));
        answer+=(static_cast<long long>(sqrt(y))/k);
    }
    
    answer+=d/k;
    return answer;
}