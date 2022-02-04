#include <iostream>
using namespace std;

void fibonacci(int n,int& zero,int& one) {
	
    if (n == 0)
    {
        zero++;
        return;
    }
    if (n == 1) {
        one++;
        return;
    }
    int pre_zero = 1;
    zero = 0;
    int tmp_zero;
    int tmp_one;
    int pre_one = 0;
    one = 1;

    for (int i = 2; i <= n; i++) {
        tmp_zero = zero;
        zero = zero + pre_zero;
        pre_zero = tmp_zero;

        tmp_one = one;
        one = one + pre_one;
        pre_one = tmp_one;
        
    }
}

int main() {
    int input;
    int n;
    cin >> input;

    while (input) {
        int zero = 0;
        int one = 0;
        input--;
        cin >> n;
        fibonacci(n,zero,one);
        cout << zero << " " << one << endl;
    }
}