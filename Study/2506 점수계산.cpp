
#include <iostream>
using namespace std;

int main()
{
    
    int N;
    
    cin>>N;
    
    int sum=0;
    
    int num=0;
    for(int i=0;i<N;i++)
    {
        int bit;
        cin>>bit;
        
        if(bit==1)
        {
            num++;
        }
        else
        {
            num=0;
        }
        
        sum+=num;
    }
    
    cout<<sum<<'\n';

    
    return 0;
}