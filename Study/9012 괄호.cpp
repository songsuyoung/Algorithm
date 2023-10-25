#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int N;
    cin>> N;

    string input;
    for(int i=0;i<N;i++)
    {
        getchar();
        cin>>input;
        stack<char> s;
        bool isFail=false;
        for(int j=0;j<input.length();j++)
        {
            if(input[j]=='(')
            {
                s.push(input[j]);
            }
            else{
                if(s.empty())
                {
                    isFail=true;
                    break;
                }
                s.pop();
            }
        }

        if(isFail||!s.empty())
        {
            cout<<"NO\n";
        }else
            cout<<"YES\n";
    }
}