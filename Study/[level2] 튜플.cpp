#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Init(const string &s)
{
    bool isClose=false;
    string tmp="";
    vector<vector<int>> buffer;
    vector<int> v;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{')
        {
            v.clear();
            tmp="";
            isClose=false;
        }else if(s[i]=='}')
        {
            if(isClose==false)
            {
                v.push_back(stoi(tmp));
                buffer.push_back(v);   
            }    
            isClose=true;
        }else if(isClose==false&&s[i]==',')
        {
            v.push_back(stoi(tmp));
            tmp="";
        }
        else
        {
            if(isClose==false)
            {
                tmp+=s[i];
            }
        }
    }
    return buffer;
}
bool compare(const vector<int> &a,const vector<int> &b)
{
    return a.size()<b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    //{ }를 기준으로 자른다. {} 뒤에 ',' 나오면 push_back한다
    vector<vector<int>> buffer=Init(s);
    sort(buffer.begin(),buffer.end(),compare); //문자열 길이 순서대로 정렬
    
    bool isOrder[100001]={};
    
    for(int i=0;i<buffer.size();i++)
    {
        for(int j=0;j<buffer[i].size();j++)
        {
            if(isOrder[buffer[i][j]])
                continue;
            isOrder[buffer[i][j]]=true;
            answer.push_back(buffer[i][j]);
        }
    }
    return answer;
}