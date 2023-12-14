#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>
using namespace std;


 deque<int> split(string input)
{
    
    input=input.substr(1,input.length()-1);
    
    istringstream sstream(input);
    string buf;

    deque<int> v;

    while(getline(sstream,buf,(',')))
    {
        v.push_back(stoi(buf));
    }

    return v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;

    for (int i = 0; i < T; i++)
    {

        bool isFail=false;
        string command;
        cin>>command;
        int N;
        cin>>N;

        string input;
        cin>>input;

        bool isReverse=false;
        deque<int> q;
        if(N!=0)
        {
           q=split(input);
        }
        for(int j=0;j<command.length();j++)
        {
            switch(command[j])
            {
                case 'R':
                isReverse=!isReverse;
                break;
                case 'D':
                if(q.empty())
                {
                    isFail=true;
                    break;
                }
                if(isReverse)
                    q.pop_back();
                else
                    q.pop_front();
                
                break;
            }
        }
        if(isFail==true)
        {
            cout<<"error\n";
            continue;
        }
        if(q.empty())
        {
            cout<<"[]\n";
            continue;
        }
        string res="[";
        if(isReverse)
        {
            
            for(int j=q.size()-1;j>0;j--)
            {
                res+=to_string(q[j]);
                res+=",";
            }
            res+=to_string(q.front());
        }
        else
        {

            for(int j=0;j<q.size()-1;j++)
            {
                res+=to_string(q[j]);
                res+=",";
            }
            res+=to_string(q.back());

        }
        res+="]\n";
        cout<<res;
    }
    
}