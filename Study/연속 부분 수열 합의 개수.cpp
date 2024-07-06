#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> uniqueNum;
    
    
    for(int i=1;i<=elements.size();i++)
    {
        int sum=0;
        for(int j=0; j<i;j++) //i번째에 left 도달하면, 멈춰야함.
        {
            sum+=elements[j];
        }
        
        uniqueNum.insert(sum);
        
        //while -> left, right 
        for(int j=i; j<(elements.size()+i);j++)
        {
            //(j-i)%element.size() 6-2
            sum-=elements[((j-i)%elements.size())];
            sum+=elements[(j%elements.size())];
        
            uniqueNum.insert(sum);
        }
    }
    
    answer=uniqueNum.size();
    return answer;
}