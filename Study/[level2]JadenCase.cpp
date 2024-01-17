#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isCheck=false;
    answer+=toupper(s[0]);
    for(int i=1;i<s.length();i++)
    {
        
        while(s[i]==' ')
        {
            answer+=s[i++];
            isCheck=true;
        }
        
        if(i>=s.length()) break;
        
        if(isCheck)
        {
            answer+=toupper(s[i]);
            isCheck=false;
        }
        else
        {
            answer+=tolower(s[i]);
        }
    }
    return answer;
}