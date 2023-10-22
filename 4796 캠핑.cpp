#include <iostream>
using namespace std;
int main()
{

    int idx=1;
    while(true)
    {

        int L,P,V; //P일 중 L일동안만 사용가능 

        cin>>L>>P>>V;

        if(L==0&&P==0&&V==0)
            break;
        

        int result=V/P*L;

        result+=V%P<L? V%P:L;
        cout<<"Case "<<idx++<<": "<<result<<'\n';
    }


}