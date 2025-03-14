#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    cout<<n;
    if(n%2 == 0)
    {
        cout<<" is even\n";
    }
    else
    {
        cout<<" is odd\n";
    }
    return 0;
}