#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    
    vector<int> orderNum;
    stack<int> buffer;
    vector<string> cnt;
    
    int N;
    cin>>N;
    
    
    for(int i=0;i<N;i++)
    {
        int tmp=0;
        cin>>tmp;
        orderNum.push_back(tmp);
    }
    
    int j=0;
    for(int i=0;i<N&&j<=orderNum.size();i++){
        cnt.push_back("+");
        buffer.push(i+1);
        
        while(!buffer.empty()&&buffer.top()==orderNum[j]){
            cnt.push_back("-");
            buffer.pop();
            j++;
        }
    }
    
    if(cnt.size()>=orderNum.size()*2){
        for(int i=0;i<cnt.size();i++)
            cout<<cnt[i]<<'\n';
    }else
        cout<<"NO"<<'\n';
    return 0;
}