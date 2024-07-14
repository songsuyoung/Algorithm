#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int split(string input)
{
    int idx=0;
    while((idx=input.find(' '))!=string::npos)
    {
        input.erase(0,idx+1);
        idx=input.find(' ');
    }
    
    return stoi(input);
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int,vector<int>,greater<int>> minpq;
    priority_queue<int,vector<int>,less<int>> maxpq;
    
    
    int len=0;
    for(int i=0;i<operations.size();i++)
    {
        //split 거쳐야함
        int num=split(operations[i]);
        if(len==0)
        {
            while(!minpq.empty())
            {
                minpq.pop();
            }
                
            while(!maxpq.empty())
            {
                maxpq.pop();
            } 
          //연산 안하고 넘어감. 
        }
        
        if(operations[i][0]=='I')
        {
            minpq.push(num);
            maxpq.push(num);
            len++;
        }
        else
        {
            //D일때에는 삭제 연산
            if(len == 0) continue;
            
            if(num<0)
            {
                //min제거
                minpq.pop();
            }
            else
            {
                //max제거
                maxpq.pop();
            }
            len--;
        }
    }
    
    if(len==0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxpq.top());
        answer.push_back(minpq.top());
    }
    return answer;
}