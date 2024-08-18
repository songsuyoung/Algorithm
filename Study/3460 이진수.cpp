#include <iostream>
using namespace std;
int main()
{
    
    int T;
    
    cin>>T;
    
    for(int tc=0;tc<T;tc++)
    {
        int num;
        cin>>num;
        
        int idx=0;
        while(num!=0)
        {
            if(num&1 == 1)
            {
                cout<<idx<<' ';
            }
            num>>=1; //1011 8+2+1
            
            idx++;
        }
    }

    return 0;
}