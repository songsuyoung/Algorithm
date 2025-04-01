#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<bool> isVisited(10,0);
    
    for(int i=0; i<numbers.size(); i++)
    {
        isVisited[numbers[i]]=true;
    }
    
    for(int i=0; i<10; i++)
    {
        if(isVisited[i]==false)
        {
            answer+=i;
        }
    }
    
    return answer;
}