#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int left=1;
    int sum=0;
    for(int right=1;right<n;right++)
    {
        
        if(sum<n)
        {
            sum+=right;
        }
        
        if(sum==n)
        {
            answer++;
        }
        //two pointer
        while(sum>=n)
        {
            sum-=left;
            if(sum==n)
            {
                answer++;
            }
            left++;
        }
    }
    return answer;
}