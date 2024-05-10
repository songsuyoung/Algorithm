#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    
    while((s.find(' ')!=string::npos))
    {
        int index = s.find(' ');
        nums.push_back(stoi(s.substr(0,index)));
        s = s.erase(0,index+1);
    }
    nums.push_back(stoi(s));
    
    int minVal=987654321;
    int maxVal=-987654321;
    
    for(int i=0;i<nums.size();i++)
    {
        minVal=min(minVal,nums[i]);
        maxVal=max(maxVal,nums[i]);
    }
   
    answer = to_string(minVal)+" "+to_string(maxVal);
    return answer;
}