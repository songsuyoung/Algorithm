#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int &a,int &b)
{
    string sta = to_string(a);
    string stb = to_string(b);
    
    return (sta+stb)>(stb+sta);
}
string solution(vector<int> numbers) {
    string answer = "";
    
    int cnt=0;
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i] == 0)
        {
            cnt++;
        }
    }
    
    if(cnt == numbers.size())
    {
        answer="0";
        return answer;
    }
    
    sort(numbers.begin(),numbers.end(),compare);
    
    for(int i=0;i<numbers.size();i++)
    {
        answer+=to_string(numbers[i]);
    }
    
    return answer;
}