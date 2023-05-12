#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    int T;
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        int H,W,N;
        
        cin>>H>>W>>N;
        
        int yy=N;
        int xx=1;
        for(;yy>H;yy-=H){
            xx++;
        }
        
        cout<<yy*100+xx<<endl;
    }
    return 0;
}