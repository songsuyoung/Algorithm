#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void recursive(const string &input,string output,vector<int> &res,vector<bool> &isVisited)
{
    if(input.length()==output.length())
    {
        if(stoi(input)<stoi(output))
        {
            res.push_back(stoi(output));
        }
        return ;
    }

    for(int i=0;i<input.length();i++)
    {
        if(isVisited[i]) continue;
        isVisited[i]=true;
        recursive(input,output+input[i],res,isVisited);
        isVisited[i]=false;
    }
}
int main()
{
    string input;
    cin>>input;

    vector<bool> isVisited(input.length(),false);
    vector<int> res;
    recursive(input,"",res,isVisited);
    if(res.size()==0)
    {
        cout<<0<<'\n';
    }
    else
    {
        cout<<*min_element(res.begin(),res.end());
    }
}