#include <string>
#include <vector>
#include <iostream>
using namespace std;


void recursive(int n,vector<bool> &isChecked, vector<int> &info,int idx,vector<int> &answer,int &maxVal)
{
    //base
    if(idx>=isChecked.size())
    {
        vector<int> res(isChecked.size(),0);
        int sum=0,apeachSum=0;
        //계산 진행
        for(int i=0;i<isChecked.size();i++)
        {
            if(isChecked[i])
            {
                //이긴거.
                res[i]=info[i]+1;
                sum+=(10-i);
            }
            else
            {
                if(info[i]!=0)
                    apeachSum+=(10-i);
            }
        
        }
        int distance=abs(sum-apeachSum);
        if((sum-apeachSum)>0&&maxVal<=distance)
        {
            //조건 검사=>뒤 점수가 더 높은 
            if(n>0)
            {
                res[res.size()-1]+=n;
            }

            if(maxVal==distance)
            {
                for(int i=res.size()-1;i>=0;i--)
                {
                    if(answer[i]>res[i]) return;
                    if(answer[i]<res[i]) break;
                }
                
                // [2,3,1,0,0,0,0,2,3,0,0] answer
                // [2,1,0,2,0,0,0,1,3,0,0] res
            }
            answer=res;
            maxVal=distance;
        }
        return;
    }
    //recursive
    //지는 경우

    isChecked[idx]=false;
    recursive(n,isChecked,info,idx+1,answer,maxVal);

    if(n-(info[idx]+1)>=0)
    {
        isChecked[idx]=true;
        recursive(n-(info[idx]+1),isChecked,info,idx+1,answer,maxVal);
        isChecked[idx]=false;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(info.size(),0);
    vector<bool> isChecked(info.size(),false);
    int maxVal=0;
    
    recursive(n,isChecked,info,0,answer,maxVal);
    
    if(maxVal==0)
    {
        answer.resize(1);
        answer[0]=-1;
    }
    
    return answer;
}