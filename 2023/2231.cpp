#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    string N;
    cin>>N;
    
    int integer=stoi(N);
    int i=0;
    int sum=0;
    for(;i<integer&&sum!=integer;i++){
        sum=0;
        string operation=to_string(i);
        for(int j=0;j<operation.length();j++){
            sum+=(operation[j]-'0');
        }
        sum+=i;
        if(sum==integer) break;
    }
    if(i==integer){
        cout<<0<<'\n';
    }else
        cout<<i<<'\n';
        
    return 0;
}