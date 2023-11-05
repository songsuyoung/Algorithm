#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin>>input;

    vector<int> sums;
    int currVal=0;
    int sum=0;
    for(int i=0;i<=input.length();i++)
    {
        if(input[i]=='-'||i==input.length())
        {
            sum+=currVal;
            sums.push_back(sum);
            sum=0;
            currVal=0;
        }else if(input[i]=='+')
        {
            sum+=currVal;
            currVal=0;
        }else{
            currVal=10*currVal+(input[i]-'0');
            
        }
    }
    sum=sums[0];
    for(int i=1;i<sums.size();i++)
        sum-=sums[i];
    cout<<sum<<'\n';
}