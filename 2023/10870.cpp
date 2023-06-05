
//fibonacci 도 캐시가 가능함
// 0 1 2   3.  4.  5
// 0 1 0-1 2-1 3-2 4-3
#include <iostream>

using namespace std;

int fibonacci(int n,int *cached){
    
    if(n<=0)
        return 0;
    if(n<=1)
        return 1;
    
    if(cached[n]==0) //n이 0일때 이전껄 호출
        cached[n]=fibonacci(n-1,cached)+fibonacci(n-2,cached);
    return cached[n-1]+cached[n-2]; //있으면 그냥 리턴..
}
int main()
{
    int N;
    cin>>N;
    
    int cached[21]={0,1,0,};
    cout<<fibonacci(N,cached);
    return 0;
}