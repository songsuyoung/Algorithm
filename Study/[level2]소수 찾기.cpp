#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

void recursive(vector<char> &v, set<int> &number,vector<bool>& isVisited,string word,int selected)
{
    if(selected<=word.length())
    {
        number.insert(stoi(word));
        return;
    }
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        if(isVisited[i]) continue;
        isVisited[i]=true;
        recursive(v,number,isVisited,word+v[i],selected);
        isVisited[i]=false;
    }
}
int solution(string numbers) {
    int answer = 0;
    
    vector<char> v;
    
    for(int i=0;i<numbers.size();i++)
    {
        v.push_back(numbers[i]);
    }
    //999 9999
    vector<bool> isVisited(1000001,false);
    set<int> number;
    for(int i=1;i<=numbers.length();i++)
    {
        recursive(v,number,isVisited,"",i);   
    }
    
   
    for(auto num:number)
    {
        bool isNotPrim=false;
        if(num==1||num==0) continue;
        for(int i=2;i<num;i++)
        {
            if(num%i==0)
            {
                isNotPrim=true;
                break;
            }
        }
        if(isNotPrim==false)
        {
            answer++;
        }
    }
    return answer;
}