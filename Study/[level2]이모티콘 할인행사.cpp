#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isFirst=true;

vector<int> calculate(vector<vector<int>> &users,vector<int> &emoticons,vector<int> &percent)
{
    vector<int> res(2,0);
    for(int u=0;u<users.size();u++)
    {
        int sum=0;
        for(int i=0;i<emoticons.size();i++)
        {
            if(percent[i]<users[u][0]) continue; //응 안사~
            int money=emoticons[i]-emoticons[i]*(percent[i]/100.0);
            sum+=money;
        }   
        
        if(users[u][1]<=sum)
        {
            sum=0;
            res[0]++;
            continue;
        }
        res[1]+=sum;
    }
    
    return res;
}
void recursive(int size,vector<vector<int>> &users,vector<int> &emoticons,const vector<int> &rates,int selected,vector<int> &percent,int idx,vector<int> &answer)
{
    
    if(size==selected)
    {
        const vector<int> &res=calculate(users,emoticons,percent);
        
        if(answer[0]<res[0])
        {
            answer=res;
        }
        else if(answer[0]==res[0])
        {
            if(answer[1]<res[1])
                answer=res;
        }
        //플러스가 같으면, 구매비용이 높은 애 
        return;
    }
    
    percent[idx]=rates[0];
    recursive(size,users,emoticons,rates,selected+1,percent,idx+1,answer);
    
    percent[idx]=rates[1];
    recursive(size,users,emoticons,rates,selected+1,percent,idx+1,answer);
    
    percent[idx]=rates[2];
    recursive(size,users,emoticons,rates,selected+1,percent,idx+1,answer);
    
    percent[idx]=rates[3];
    recursive(size,users,emoticons,rates,selected+1,percent,idx+1,answer);
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2,0);
    vector<int> keepPercent(emoticons.size(),0);
    pair<int,int> res;
    vector<int> rates={ 10,20,30,40 };
    
    recursive(emoticons.size(),users,emoticons,rates,0,keepPercent,0,answer);

    return answer;
}