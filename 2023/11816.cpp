#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    
    string x;
    
    cin>>x;
    
    int num=10; //default는 10진수로
    int end=0;
    if(x[1]=='x'){
        num=16;
        end=2;
    }else{
        if(x[0]=='0'){
            num=8;
            end=1;
        }
    }
    int j=0,result=0;
    for(int i=x.length()-1;i>=end;i--){
        int nums=x[i]-'0';
        if(x[i]>='a'){
            nums=x[i]-'W';
        }
        result+=pow(num,j++)*nums;
    }
    
    cout<<result<<'\n';
    return 0;
}