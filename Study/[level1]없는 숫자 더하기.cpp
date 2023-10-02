#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> numbers) {
    map<int,bool> num;
    
    for(int i=0;i<numbers.size();i++){
        num[numbers[i]]=true;
    }
    int answer=0;
    for(int i=0;i<=9;i++){
        if(!num[i])
            answer+=i;
    }  
    return answer;
}