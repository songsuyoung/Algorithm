#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    
    int m,n;
    cin>>m>>n;
    
    string answer="";
    
    if(m==0)
        cout<<0<<'\n';
    else{
        while(m!=0){
            
            int modNum=m%n;
            m=m/n;
            
            if(modNum>9){ //10 - 65 11 -66 12 -67 13 14 15
                answer+=(modNum+55);
            }else{
                answer+=to_string(modNum);
            }
        }
        reverse(answer.begin(),answer.end());
    }    
    cout<<answer<<'\n';
    return 0;
}