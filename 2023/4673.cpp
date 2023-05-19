/*
1 1+1 -> 2 제거
2 
3
4

.
.
.
50 50 + 5+ 0 -> 55 제거

remove(a.begin(),a.end(),154);
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> selfNum;
    for(int i=1;i<=10000;i++){
        selfNum.push_back(i);
    }
    
    for(int i=0;i<10000;i++){
        int sum=i;
        string num=to_string(i);
        for(int j=0;j<num.length();j++){
            sum+=(num[j]-'0');
        }
        
        selfNum.erase(remove(selfNum.begin(),selfNum.end(),sum),selfNum.end());
    }
    
    for(int i=0;i<selfNum.size();i++){
        cout<<selfNum[i]<<'\n';
    }
    return 0;
}