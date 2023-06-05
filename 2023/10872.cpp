//factorial n-1 n
//cache적용가능
// 1 2 3 4 5 6 7 8 9 10 11 12
// 1 2 6 24 120 720 5040 40320 362880 3628800 39916800 479001600
#include <iostream>

using namespace std;

int factorial(int n,int *chached){
    
    if(n<=1){
        return 1;
    }
        
    if(chached[n]==0) //0일때 캐쉬에 저장 
        chached[n]=factorial(n-1,chached);
    return chached[n]*n;
}
int main()
{
    
    int N;
    cin>>N;
    //chached의 공간문제로 인해 3번 실패
    int chached[13]={0,};
    cout<<factorial(N,chached);

    return 0;
}